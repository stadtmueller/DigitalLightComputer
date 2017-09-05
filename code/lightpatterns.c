#include "avr/io.h"
#include "lightpatterns.h"

lightPatterns[0] = pattern0;
lightPatterns[1] = pattern1;
lightPatterns[2] = pattern2;
lightPatterns[3] = pattern3;
lightPatterns[4] = pattern4;
lightPatterns[5] = pattern5;

// Empty test pattern.
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

// Single up counter.
int pattern1()
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

int pattern2()
{
	static int step = 0;
	int ret;

	if( step == 8 )
	{
		step = 0;
		ret = 1;
	}

	switch( step )
	{
		case 0: LIGHTPORT = 0b10000001; break;
		case 1: LIGHTPORT = 0b11000000; break;
		case 2: LIGHTPORT = 0b01100000; break;
		case 3: LIGHTPORT = 0b00110000; break;
		case 4: LIGHTPORT = 0b00011000; break;
		case 5: LIGHTPORT = 0b00001100; break;
		case 6: LIGHTPORT = 0b00000110; break;
		case 7: LIGHTPORT = 0b00000011; break;
	}

	step++;

	return ret;
}

int pattern3()
{
	static int step = 0;
	int ret = 0;

	if( step == 8 )
	{
		step = 0;
		ret = 1;
	}

	switch( step )
	{
		case 0: LIGHTPORT = 0b10000011; break;
		case 1: LIGHTPORT = 0b11000001; break;
		case 2: LIGHTPORT = 0b11100000; break;
		case 3: LIGHTPORT = 0b01110000; break;
		case 4: LIGHTPORT = 0b00111000; break;
		case 5: LIGHTPORT = 0b00011100; break;
		case 6: LIGHTPORT = 0b00001110; break;
		case 7: LIGHTPORT = 0b00000111; break;
	}

	step++;

	return ret;
}

int pattern4()
{
	static int step = 0;
	int ret = 0;

	if( step == 8 )
	{
		step = 0;
		ret = 1;
	}

	switch( step )
	{
		case 0: LIGHTPORT = 0b10000111; break;
		case 1: LIGHTPORT = 0b11000011; break;
		case 2: LIGHTPORT = 0b11100001; break;
		case 3: LIGHTPORT = 0b11110000; break;
		case 4: LIGHTPORT = 0b01111000; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 6: LIGHTPORT = 0b00011110; break;
		case 7: LIGHTPORT = 0b00001111; break;
	}

	step++;

	return ret;
}

int pattern5()
{
	static int step = 0;
	int ret = 0;

	if( step == 8 )
	{
		step = 0;
		ret = 1;
	}

	switch( step )
	{
		case 0: LIGHTPORT = 0b10100000; break;
		case 1: LIGHTPORT = 0b01010000; break;
		case 2: LIGHTPORT = 0b00101000; break;
		case 3: LIGHTPORT = 0b00010100; break;
		case 4: LIGHTPORT = 0b00001010; break;
		case 5: LIGHTPORT = 0b00000101; break;
		case 6: LIGHTPORT = 0b10000010; break;
		case 7: LIGHTPORT = 0b01000001; break;
	}

	step++;

	return ret;
}
