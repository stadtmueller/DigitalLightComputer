#import <avr/io.h>
#import <avr/interrupt.h>
#import <util/delay.h>
#import <stdlib.h>
#import "lcd.h"
#import "lightpatterns.h"

#ifndef F_CPU
#define F_CPU 16000000
#endif

#define LIGHTDDR DDRA
#define LIGHTPORT PORTA

#define CONTROLDDR DDRB
#define CONTORLPORT PORTB

#define DISPLAYDDR DDRC
#define DISPLAYPORT PORTC

#define KEYBOARDDDR DDRD
#define KEYBOARDPORT PORTD

// Pushbutton pins.
#define CLKSEL      PB4
#define MODESEL     PB3
#define INTCLKSPEED PB2
#define SLOTSEL     PB1
#define SLOTSPEED   PB0
#define TESTENABLE  PC7

// Relay pin.
#define EXTCLKENABLE PC6

// Ext clk input / int. clk output.
#define CLOCKIO PD3

// Global variables for the input system.
uint8_t inputValueBuffer = 0;      // Value to be applied on Enter.
uint8_t digitPositionFactor = 1;   // To determine wether input is first or second digit.
uint8_t multiplexPosition = 0;
uint8_t lastButtonPressed = 0;     // Last button pressed to apply correct values on Enter.
// Last button numbering:
/* 0: No button (initial, test enable).
   1: Int. clock speed.
   2: Slot select.
   3: Slot speed.
*/

// Global variables for mode switching.
uint8_t testModeEnabled   = 0; // 0 = normal mode; 1 = test mode
uint8_t randomModeEnabled = 0; // 0 = program mode; 1 = random mode
uint8_t clockSelected = 0;     // 0 = internal clock; 1 = external clock

// Global variables for int. clock.
uint8_t internalClockSpeedFactor = 10;

// Global variables for programming mode.
uint8_t slotSelected = 0;
uint8_t slotSpeed = 3;


// Functions.
int randomInt()
{
	return rand() / (RAND_MAX / 99 + 1);
}

void enableInternalClock()
{
	PORTC &= ~(1<<PC6);	  // Disable ext. clock signal relay.
	GICR &= ~(1<<INT1); 	  // Disable ext. interrupts on INT1.
	DDRD |= (1<<CLOCKIO); // Change pin direction to maintain clock monitor LED.
	// Start Timer with internalClockSpeedFactor.

	lcd_clear();
	lcd_setcursor( 0, 1 );
	lcd_string( "Clock source:" );
	lcd_setcursor( 0, 2 );
	lcd_string( "Internal" );
}

void enableExternalClock()
{
	// Stop Timer.
	PORTC |= (1<<PC6);
	DDRD &= ~(1<<CLOCKIO);
	GICR |= (1<<INT1);	   // Enable ext. interrupts on INT1.

	lcd_clear();
	lcd_setcursor( 0, 1 );
	lcd_string( "Clock source:" );
	lcd_setcursor( 0, 2 );
	lcd_string( "External" );
}

void numberButtonPressed( uint8_t number )
{
	if( testModeEnabled )
		return;

	inputValuePlaceHolder = number * digitPositionFactor;

	digitPoitionFactor *= 10;

	if( digitPoitionFactor == 100 )
		digitPositionFactor = 1;
}

void enterButtonPressed()
{
// Last button numbering:
/* 0: No button (initial, test enable).
   1: Int. clock speed.
   2: Slot select.
   3: Slot speed.
*/
	switch( lastButtonPressed )
	{
		case 0: return;
		case 1: internalClockSpeedFactor = inputValueBuffer;
			break;
		case 2: slotSelected = inputValueBuffer;
			break;
		case 3: slotSpeed = inputValueBuffer;
			break;
	}
			
	inputValueBuffer = 0;
}


int main( void )
{
	// Set pin directions.
	LIGHTDDR = 0b11111111;
	CONTROLDDR &= ~( (1<<SLOTSPEED) | (1<<SLOTSEL) |
			 (1<<INTCLKSPEED) | (1<<MODESEL) | (1<<CLKSEL) );
	DDRC &= ~(1<<TESTENABLE);
	DDRC |= (1<<EXTCLKENABLE);
	KEYBOARDDDR = 0b11110000;

	// Set up multiplex timer.
	TCCR0B |= (1<<CA01); // Prescaler clk / 8.
	TIMSK0 |= (1<<TOIE); // Enable overflow interrupt.
	TCNT0 = 0;

	// Set up timer for internal clock source.

	// Setup external interrupt.
	MCUCR |= (1<<ISC11); // Interrupt reuest on falling edge on INT1.

	sei();		     // Enable global interrupts.

	while( true )
	{
		// Check input pins for button-presses.


		// -----------------------------------------------
		// Demultiplex keyboard: 
		// Keyboard grid:
		/*          ___________  Multiplexposition:
			PD7 |1 | 2 | 3|  3
		  	PD6 |4 | 5 | 6|  2
		  	PD5 |7 | 8 | 9|  1
		  	PD4 |* | 0 | #|  0
			    -----------
			    PD0 PD1 PD2
		*/

		if( PIND & (1<<PD0) )
		{
			switch( multiplexPosition )
			{
				case 0: modeButtonPressed(); break;    // * Ran/Porg Mode
				case 1: numberButtonPressed(7); break; // 7
				case 2: numberButtonPressed(4); break; // 4
				case 3: numberButtonPressed(1); break; // 1
			}
		}

		if( PIND & (1<<PD1) )
		{
			switch( multiplexPosition )
			{
				case 0: numberButtonPressed(0); break; // 0
				case 1: numberButtonPressed(8); break; // 8
				case 2: numberButtonPressed(5); break; // 5
				case 3: numberButtonPressed(2); break; // 2
			}
		}

		if( PIND & (1<<PD2) )
		{
			switch( multiplexPosition )
			{
				case 0: enterButtonPressed(); break;   // # Enter
				case 1: numberButtonPressed(9); break; // 9
				case 2: numberButtonPressed(6); break; // 6
				case 3: numberButtonPressed(3); break; // 3
			}
		}
		// ------------------------------------------------------------

		// ------------------------------------------------------------
		// Other control buttons.

		// Clock select.
		if( !(PINB & (1<<CLKSEL)) )
		{
			// 0 = internal clock; 1 = external clock
			if( clockSelected == 0 )
			{
				enableExternalClock(); // Change clock source and update display.
				clockSelected = 1;
			}
			else
			{
				enableInternalClock();
				clockSelected = 0;
			}
		}


		// Ran/Prog mode select.
		if( !(PINB & (1<<MODESEL)) )
		{
			// 0 = program mode; 1 = random mode
			if( randomModeEnabled = 1 )
			{
				randomModeEnabled = 0;
			}
			else
			{
				randomModeEnabled = 1;
			}
		}


		// Internal clock speed factor.
		if( !(PINB & (1<<INTCLKSPEED)) )
		{
			lcd_clear();
			lcd_setcursor( 0, 1 );
			lcd_string( "Clock speed:" );
			lcd_setcursor( 0, 2 );
			lcd_out( internalClockSpeedFactor );
		}


		// Slot select.
		if( !(PINB & (1<<SLOTSEL)) )
		{
			lcd_clear();
			lcd_setcursor( 0, 1 );
			lcd_string( "Slot:" );
			lcd_setcursor( 0, 2 );
			lcd_out( slotSelected );
		}


		// Slot speed.
		if( !(PINB & (1<<SLOTSPEED)) )
		{
			lcd_clear();
			lcd_setcursor( 0, 1 );
			lcd_string( "Slot speed:" );
			lcd_setcursor( 0, 2 );
			lcd_out( slotSpeed );
		}

		// Test.
		if( !(PINB & (1<<TESTENABLE)) )
		{
			static int oldModeRecovery = 0;

			if( testModeEnabled = 1 )
			{
				testmodeEnabled = 0;
				// Set pattern to inital (1).
			}
			else
			{
				testModeEnabled = 1;
				lcd_clear();
				lcd_setcursor( 0, 1 );
				lcd_string( "Testing now..." );

				enableInternalClock();
				internalClockSpeedFactor = 10;
				// Set pattern to test (0).
			}
		}

		// -------------------------------------------------------------
					
	}
}

// Multiplexer
ISR( TIMER0_OVF_vect )
{
	if( multiplexPosition == 4 )
		multiplexPosition = 0;

	// Keyboard
	KEYBOARDPORT |= 16 * multiplexPosition;

	multiplexPosition++;
}

// Internal Clock
ISR( )
{

}

// Beatshifter
ISR( INT1_vect )
{

}
