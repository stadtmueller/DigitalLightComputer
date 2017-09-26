#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"
#include "lightpatterns.h"


#define F_CPU 20000000

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


// Global variables for lightpattern processing
// (slotSpeed is used for random and programming mode).
uint8_t slotSpeed = 3;

// Global variables for the input system.
uint8_t inputValueBuffer = 0;      // Value to be applied on Enter.
uint8_t digitPositionFactor = 1;   // Find out if input is first or second digit.
uint8_t multiplexPosition = 0;
uint8_t lastButtonPressed = 0;     // Last button pressed to apply correct values on Enter.
/*
   Last button numbering: 
   0: No button (initial, test enable).
   1: Int. clock speed.
   2: Slot select.
   3: Slot speed.
*/

// Global variables for mode switching.
uint8_t testModeEnabled = 0;   // 0 = normal mode; 1 = test mode
uint8_t randomModeEnabled = 0; // 0 = program mode; 1 = random mode
uint8_t clockSelected = 0;     // 0 = internal clock; 1 = external clock

// Global variables for int. clock.
uint8_t internalClockSpeed = 100;

// Global variables for programming mode.
// Explanation:
// Each light pattern has 8 stages.
// That means that one execution needs 8 beats.
//
// You can assign one light pattern to a slot.
// Each slot is then (patternSpeed)-times executed.
// This means that if you've assigned pattern 10
// to slot 0 and pattern 23 to slot 1
// with patternSpeed at 3 you will see
// 3 x 10 and then 3 x 23
// in a total of (8 * 3) * 2 = 48 beats.
uint8_t slotSelected = 0;
uint8_t slots[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };



// Functions.
int randomInt()
{
	return rand() / (RAND_MAX / 99 + 1);
}

void enableInternalClock()
{
	PORTC &= ~(1<<PC6);   			     // Disable ext. clock signal relay.
	TCCR2B |= (1<<CA22) | (1<<CA21) | (1<<CA20); // Start internal clock timer.

	lcd_clear();
	lcd_setcursor( 0, 1 );
	lcd_string( "Clock source:" );
	lcd_setcursor( 0, 2 );
	lcd_string( "Internal" );
}

void enableExternalClock()
{
	PORTC |= (1<<PC6);				  // Enable ext. clock signal relay.
	TCCR2B &= ~( (1<<CA22) | (1<<CA21) | (1<<CA20) ); // Stop internal clock timer.

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

	digitPositionFactor *= 10;

	if( digitPositionFactor == 100 )
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
		case 0: break;
		case 1: if( inputValueBuffer > 20 )
				break;
			else
				internalClockSpeed = 10 * inputValueBuffer;
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
	LIGHTDDR = 0b11111111;					// Main output port connected to driver.
	DDRC |= (1<<EXTCLKENABLE);				// Relay pin to enable ext. clock.
	DDRC &= ~(1<<TESTENABLE);				// Test button input.
	CONTROLDDR &= ~( (1<<SLOTSPEED)   | (1<<SLOTSEL) |	// Other control inputs.
		(1<<INTCLKSPEED) | (1<<MODESEL) | (1<<CLKSEL) );

	// Set up multiplex timer.
	TCCR0B |= (1<<CA01); // Prescaler clk / 8.
	TIMSK0 |= (1<<TOIE); // Enable overflow interrupt.
	TCNT0 = 0;

	// Set up timer for internal clock source.
	TCCR2B &= ~( (1<<CA22) | (1<<CA21) | (1<<CA20) ); // Prescaler clk/1024 (initially stoped).
	TIMSK2 |= (1<<TOIE); 				  // Enable overflow interrupt.
	TCNT2 = 0;

	// Setup external interrupt.
	EICRA |= (1<<ISC11); // Interrupt reuest on falling edge on INT1.
	EIMSK |= (1<<INT1);  // Enable ext. interrupt on INT1.

	sei();		     // Enable interrupts generally.

	while( true )
	{
		// Check input pins for button-presses.
		// Debounce by checking if button is still held down
		// 20ms after first detection.
		// -----------------------------------------------
		// Demultiplex keyboard: 
		// Keyboard grid:
		/**          __________   Multiplexposition:
			PD7 |1 | 2 | 3|  3
		  	PD6 |4 | 5 | 6|  2
		  	PD5 |7 | 8 | 9|  1
		  	PD4 |* | 0 | #|  0
			    -----------
			    PD0 PD1 PD2	   
		**/
		if( PIND & (1<<PD0) )
		{
			switch( multiplexPosition )
			{
				case 0: starButtonPressed(); break;    // *
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
			_dely_ms( 20 );

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

			while( !(PINB & (1<<CLKSEL)) )
				continue;
		}


		// Ran/Prog mode select.
		if( !(PINB & (1<<MODESEL)) )
		{
			_delay_ms( 20 );

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

			while( !(PINB & (1<<MODESEL)) )
				continue;
		}


		// Internal clock speed factor.
		if( !(PINB & (1<<INTCLKSPEED)) )
		{
			_delay_ms( 20 );

			if( !(PINB & (1<<INTCLKSPEED)) )
			{
				lcd_clear();
				lcd_setcursor( 0, 1 );
				lcd_string( "Clock speed:" );
				lcd_setcursor( 0, 2 );
				lcd_out( internalClockSpeedFactor );
			}

			while( !(PINB & (1<<INTCLKSPEED)) )
				continue;
		}


		// Slot select.
		if( !(PINB & (1<<SLOTSEL)) )
		{
			_delay_ms( 20 );

			if( !(PINB & (1<<SLOTSEL)) )
			{
				lcd_clear();
				lcd_setcursor( 0, 1 );
				lcd_string( "Slot:" );
				lcd_setcursor( 0, 2 );
				lcd_out( slotSelected );
			}

			while( !(PINB & (1<<SLOTSEL)) )
				continue;
		}


		// Slot speed.
		if( !(PINB & (1<<SLOTSPEED)) )
		{
			_delay_ms( 20 );

			if( !(PINB & (1<<SLOTSPEED)) )
			{
				lcd_clear();
				lcd_setcursor( 0, 1 );
				lcd_string( "Slot speed:" );
				lcd_setcursor( 0, 2 );
				lcd_out( slotSpeed );
			}

			while( !(PINB & (1<<SLOTSPEED)) )
				continue;
		}

		// Test.
		if( !(PINB & (1<<TESTENABLE)) )
		{
			static int oldModeRecovery = 0;

			_delay_ms( 20 );

			if( !(PINB & (1<<TESTENABLE)) )
			{
				if( testModeEnabled = 1 )
				{
					testmodeEnabled = 0;
					// Do some fallback.
				}
				else
				{
					testModeEnabled = 1;
					lcd_clear();
					lcd_setcursor( 0, 1 );
					lcd_string( "Testing now..." );
					// Set pattern to test (0).
				}
			}

			while( !(PINB & (1<<TESTENABLE)) )
				continue;
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
ISR( TIMER2_OVF_vect )
{
	// This will be called so fast that the
	// resolution must be enhanced by only
	// reacting every time counter hits
	// internalClockSpeed.
	static uint8_t counter = 0;

	counter++;

	if( counter == internalClockSpeed )
	{
		PORTD |= (1<<PD3);
		counter = 0;
	}
}

// Lightpattern processing.
ISR( INT1_vect )
{
	static uint8_t status = 0;
	static uint8_t slotCounter = 0;

	status = (*lightPatterns[selectedPattern])();  // Call current function.

	if( status )
	{
		slotCounter++;

		if( slotCounter == slotSpeed )
		{
			

	if( clockSelected == 0 ) // Clear pin when internal clock selected.
		PORTD &= ~(1<<PD3);
}




