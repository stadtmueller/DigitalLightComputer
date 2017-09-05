#include "avr/io.h"
#include "lightpatterns.h"

lightPatterns[0] = pattern0;
lightPatterns[1] = pattern1;
lightPatterns[2] = pattern2;
lightPatterns[3] = pattern3;
lightPatterns[4] = pattern4;
lightPatterns[5] = pattern5;

// Test pattern.
int pattern0()
{
	if( LIGHTPORT == PORTMAX )
	{
		LIGHTPORT = 0b00000001;
		return 1;
	}
	else
	{
		LIGHTPORT *= 2;
		return 0;
	}
}

// Binary counter pattern.
int pattern1()
{
	if( LIGHTPORT == PORTMAX )
	{
		LIGHTPORT = 0b00000001;
		return 1;
	}
	else
	{
		LIGHTPORT += 1;
		return 0;
	}
}

// Binary counter mirrored.
int pattern2()
{
	 if( LIGHTPORT == 
}

int pattern3()
{
}

int pattern4()
{
}

int pattern5()
{
}
