#include "avr/io.h"
#include "lightpatterns.h"

lightPatterns[0] = pattern0;
lightPatterns[1] = pattern1;
lightPatterns[2] = pattern2;
lightPatterns[3] = pattern3;
lightPatterns[4] = pattern4;
lightPatterns[5] = pattern5;
lightPatterns[6] = pattern6;
lightPatterns[7] = pattern7;
lightPatterns[8] = pattern8;
lightPatterns[9] = pattern9;
lightPatterns[10] = pattern10;
lightPatterns[11] = pattern11;
lightPatterns[12] = pattern12;
lightPatterns[13] = pattern13;
lightPatterns[14] = pattern14;
lightPatterns[15] = pattern15;
lightPatterns[16] = pattern16;
lightPatterns[17] = pattern17;
lightPatterns[18] = pattern18;
lightPatterns[19] = pattern19;
lightPatterns[20] = pattern20;
lightPatterns[21] = pattern21;
lightPatterns[22] = pattern22;
lightPatterns[23] = pattern23;
lightPatterns[24] = pattern24;
lightPatterns[25] = pattern25;
lightPatterns[26] = pattern26;
lightPatterns[27] = pattern27;
lightPatterns[28] = pattern28;
lightPatterns[29] = pattern29;
lightPatterns[30] = pattern30;
lightPatterns[31] = pattern31;
lightPatterns[32] = pattern32;
lightPatterns[33] = pattern33;
lightPatterns[34] = pattern34;
lightPatterns[35] = pattern35;
lightPatterns[36] = pattern36;
lightPatterns[37] = pattern37;
lightPatterns[38] = pattern38;
lightPatterns[39] = pattern39;
lightPatterns[40] = pattern40;
lightPatterns[41] = pattern41;
lightPatterns[42] = pattern42;
lightPatterns[43] = pattern43;
lightPatterns[44] = pattern44;
lightPatterns[45] = pattern45;
lightPatterns[46] = pattern46;
lightPatterns[47] = pattern47;
lightPatterns[48] = pattern48;
lightPatterns[49] = pattern49;
lightPatterns[50] = pattern50;
lightPatterns[51] = pattern51;
lightPatterns[52] = pattern52;
lightPatterns[53] = pattern53;
lightPatterns[54] = pattern54;
lightPatterns[55] = pattern55;
lightPatterns[56] = pattern56;
lightPatterns[57] = pattern57;
lightPatterns[58] = pattern58;
lightPatterns[59] = pattern59;
lightPatterns[60] = pattern60;
lightPatterns[61] = pattern61;
lightPatterns[62] = pattern62;
lightPatterns[63] = pattern63;
lightPatterns[64] = pattern64;
lightPatterns[65] = pattern65;
lightPatterns[66] = pattern66;
lightPatterns[67] = pattern67;
lightPatterns[68] = pattern68;
lightPatterns[69] = pattern69;
lightPatterns[70] = pattern70;
lightPatterns[71] = pattern71;
lightPatterns[72] = pattern72;
lightPatterns[73] = pattern73;
lightPatterns[74] = pattern74;
lightPatterns[75] = pattern75;
lightPatterns[76] = pattern76;
lightPatterns[77] = pattern77;
lightPatterns[78] = pattern78;
lightPatterns[79] = pattern79;
lightPatterns[80] = pattern80;
lightPatterns[81] = pattern81;
lightPatterns[82] = pattern82;
lightPatterns[83] = pattern83;
lightPatterns[84] = pattern84;
lightPatterns[85] = pattern85;
lightPatterns[86] = pattern86;
lightPatterns[87] = pattern87;
lightPatterns[88] = pattern88;
lightPatterns[89] = pattern89;
lightPatterns[90] = pattern90;
lightPatterns[91] = pattern91;
lightPatterns[92] = pattern92;
lightPatterns[93] = pattern93;
lightPatterns[94] = pattern94;
lightPatterns[95] = pattern95;
lightPatterns[96] = pattern96;
lightPatterns[97] = pattern97;
lightPatterns[98] = pattern98;
lightPatterns[99] = pattern99;



// Empty test pattern.
int pattern0()
{
	LIGHTPORT = 0b00000000;

	return 1;
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
		case 7: LIGHTPORT = 0b00000011; break;
		case 6: LIGHTPORT = 0b00000110; break;
		case 5: LIGHTPORT = 0b00001100; break;
		case 4: LIGHTPORT = 0b00011000; break;
		case 3: LIGHTPORT = 0b00110000; break;
		case 2: LIGHTPORT = 0b01100000; break;
		case 1: LIGHTPORT = 0b11000000; break;
		case 0: LIGHTPORT = 0b10000001; break;
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
		case 7: LIGHTPORT = 0b00000111; break;
		case 6: LIGHTPORT = 0b00001110; break;
		case 5: LIGHTPORT = 0b00011100; break;
		case 4: LIGHTPORT = 0b00111000; break;
		case 3: LIGHTPORT = 0b01110000; break;
		case 2: LIGHTPORT = 0b11100000; break;
		case 1: LIGHTPORT = 0b11000001; break;
		case 0: LIGHTPORT = 0b10000011; break;
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
		case 7: LIGHTPORT = 0b00001111; break;
		case 6: LIGHTPORT = 0b00011110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b01111000; break;
		case 3: LIGHTPORT = 0b11110000; break;
		case 2: LIGHTPORT = 0b11100001; break;
		case 1: LIGHTPORT = 0b11000011; break;
		case 0: LIGHTPORT = 0b10000111; break;

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
		case 7: LIGHTPORT = 0b01000001; break;
		case 6: LIGHTPORT = 0b10000010; break;
		case 5: LIGHTPORT = 0b00000101; break;
		case 4: LIGHTPORT = 0b00001010; break;
		case 3: LIGHTPORT = 0b00010100; break;
		case 2: LIGHTPORT = 0b00101000; break;
		case 1: LIGHTPORT = 0b01010000; break;
		case 0: LIGHTPORT = 0b10100000; break;
	}

	step++;

	return ret;
}

int pattern6()
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
		case 7: LIGHTPORT = 0b01010001; break;
		case 6: LIGHTPORT = 0b10100010; break;
		case 5: LIGHTPORT = 0b01000101; break;
		case 4: LIGHTPORT = 0b10001010; break;
                case 3: LIGHTPORT = 0b00010101; break;
                case 2: LIGHTPORT = 0b00101010; break;
                case 1: LIGHTPORT = 0b01010100; break;
                case 0: LIGHTPORT = 0b10101000; break;
	}

	step++;

        return ret;
}

int pattern7()
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
		case 7: LIGHTPORT = 0b00011111; break;
		case 6: LIGHTPORT = 0b00111110; break;
		case 5: LIGHTPORT = 0b01111100; break;
		case 4: LIGHTPORT = 0b11111000; break;
                case 3: LIGHTPORT = 0b11110001; break;
                case 2: LIGHTPORT = 0b11100011; break;
                case 1: LIGHTPORT = 0b11000111; break;
                case 0: LIGHTPORT = 0b10001111; break;
	}

	step++;

        return ret;
}

int pattern8()
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
		case 7: LIGHTPORT = 0b00111111; break;
		case 6: LIGHTPORT = 0b01111110; break;
		case 5: LIGHTPORT = 0b11111100; break;
		case 4: LIGHTPORT = 0b11111001; break;
                case 3: LIGHTPORT = 0b11110011; break;
                case 2: LIGHTPORT = 0b11100111; break;
                case 1: LIGHTPORT = 0b11001111; break;
                case 0: LIGHTPORT = 0b10011111; break;
	}

	step++;

        return ret;
}

int pattern9()
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
		case 7: LIGHTPORT = 0b10011001; break;
		case 6: LIGHTPORT = 0b00110011; break;
		case 5: LIGHTPORT = 0b01100110; break;
		case 4: LIGHTPORT = 0b11001100; break;
                case 3: LIGHTPORT = 0b10011001; break;
                case 2: LIGHTPORT = 0b00110011; break;
                case 1: LIGHTPORT = 0b01100110; break;
                case 0: LIGHTPORT = 0b11001100; break;
	}

	step++;

        return ret;
}

int pattern10()
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
		case 7: LIGHTPORT = 0b00010001; break;
		case 6: LIGHTPORT = 0b00100010; break;
		case 5: LIGHTPORT = 0b01000100; break;
		case 4: LIGHTPORT = 0b10001000; break;
                case 3: LIGHTPORT = 0b00010001; break;
                case 2: LIGHTPORT = 0b00100010; break;
                case 1: LIGHTPORT = 0b01000100; break;
                case 0: LIGHTPORT = 0b10001000; break;
	}

	step++;

        return ret;
}

int pattern11()
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
		case 7: LIGHTPORT = 0b11011101; break;
		case 6: LIGHTPORT = 0b10111011; break;
		case 5: LIGHTPORT = 0b01110111; break;
		case 4: LIGHTPORT = 0b11101110; break;
                case 3: LIGHTPORT = 0b11011101; break;
                case 2: LIGHTPORT = 0b10111011; break;
                case 1: LIGHTPORT = 0b01110111; break;
                case 0: LIGHTPORT = 0b11101110; break;
	}

	step++;

        return ret;
}

int pattern12()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b01000010; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}


int pattern13()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b01000010; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00000000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00000000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern14()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern15()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern16()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern17()
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
		case 7: LIGHTPORT = 0b00011000; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b00011000; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b01111110; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern18()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern19()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b01111110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern20()
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
		case 7: LIGHTPORT = 0b01000010; break;
		case 6: LIGHTPORT = 0b10000001; break;
		case 5: LIGHTPORT = 0b01000010; break;
		case 4: LIGHTPORT = 0b10000001; break;
                case 3: LIGHTPORT = 0b01000010; break;
                case 2: LIGHTPORT = 0b10000001; break;
                case 1: LIGHTPORT = 0b01000010; break;
                case 0: LIGHTPORT = 0b10000001; break;
	}

	step++;

        return ret;
}

int pattern21()
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
		case 7: LIGHTPORT = 0b01100110; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b01100110; break;
		case 4: LIGHTPORT = 0b11000011; break;
                case 3: LIGHTPORT = 0b01100110; break;
                case 2: LIGHTPORT = 0b11000011; break;
                case 1: LIGHTPORT = 0b01100110; break;
                case 0: LIGHTPORT = 0b11000011; break;
	}

	step++;

        return ret;
}

int pattern22()
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
		case 7: LIGHTPORT = 0b00111100; break;
		case 6: LIGHTPORT = 0b11111111; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b11000011; break;
                case 3: LIGHTPORT = 0b10000001; break;
                case 2: LIGHTPORT = 0b01000010; break;
                case 1: LIGHTPORT = 0b00100100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern23()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b01111110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern24()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b10000001; break;
		case 5: LIGHTPORT = 0b11000011; break;
		case 4: LIGHTPORT = 0b11100111; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern25()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b01111110; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b10011001; break;
                case 1: LIGHTPORT = 0b11011011; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern26()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b10000001; break;
		case 5: LIGHTPORT = 0b10000001; break;
		case 4: LIGHTPORT = 0b10000001; break;
                case 3: LIGHTPORT = 0b11000011; break;
                case 2: LIGHTPORT = 0b01100110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern27()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b00000000; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b00000000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern28()
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
		case 7: LIGHTPORT = 0b00000000; break;
		case 6: LIGHTPORT = 0b00011000; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b01111110; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern29()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b11111111; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b11111111; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern30()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b01000010; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b01111110; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern31()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b11111111; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern32()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00100100; break;
                case 3: LIGHTPORT = 0b01000010; break;
                case 2: LIGHTPORT = 0b10000001; break;
                case 1: LIGHTPORT = 0b01000010; break;
                case 0: LIGHTPORT = 0b00100100; break;
	}

	step++;

        return ret;
}

int pattern33()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00100100; break;
                case 1: LIGHTPORT = 0b01000010; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern34()
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
		case 7: LIGHTPORT = 0b11100111; break;
		case 6: LIGHTPORT = 0b11100111; break;
		case 5: LIGHTPORT = 0b00011000; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b11000011; break;
                case 2: LIGHTPORT = 0b11000011; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00111100; break;
	}

	step++;

        return ret;
}

int pattern35()
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
		case 7: LIGHTPORT = 0b00000000; break;
		case 6: LIGHTPORT = 0b11111111; break;
		case 5: LIGHTPORT = 0b00000000; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b00000000; break;
                case 2: LIGHTPORT = 0b00000000; break;
                case 1: LIGHTPORT = 0b11111111; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern36()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b00011000; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b01111110; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern37()
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
		case 7: LIGHTPORT = 0b00011000; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b01100110; break;
		case 4: LIGHTPORT = 0b11000011; break;
                case 3: LIGHTPORT = 0b10000001; break;
                case 2: LIGHTPORT = 0b01000010; break;
                case 1: LIGHTPORT = 0b00100100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern38()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b11111111; break;
		case 5: LIGHTPORT = 0b01100110; break;
		case 4: LIGHTPORT = 0b01100110; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b11111111; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern39()
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
		case 7: LIGHTPORT = 0b00111100; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b00000000; break;
		case 4: LIGHTPORT = 0b01111110; break;
                case 3: LIGHTPORT = 0b01111110; break;
                case 2: LIGHTPORT = 0b00000000; break;
                case 1: LIGHTPORT = 0b11111111; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern40()
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
		case 7: LIGHTPORT = 0b00000000; break;
		case 6: LIGHTPORT = 0b00011000; break;
		case 5: LIGHTPORT = 0b00000000; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b00000000; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b00000000; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern41()
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
		case 7: LIGHTPORT = 0b00011000; break;
		case 6: LIGHTPORT = 0b00000000; break;
		case 5: LIGHTPORT = 0b00011000; break;
		case 4: LIGHTPORT = 0b00000000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b01111110; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern42()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern43()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b01100110; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b01100110; break;
                case 0: LIGHTPORT = 0b11000011; break;
	}

	step++;

        return ret;
}

int pattern44()
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
		case 7: LIGHTPORT = 0b00100100; break;
		case 6: LIGHTPORT = 0b10000001; break;
		case 5: LIGHTPORT = 0b01011010; break;
		case 4: LIGHTPORT = 0b10100101; break;
                case 3: LIGHTPORT = 0b01000010; break;
                case 2: LIGHTPORT = 0b10011001; break;
                case 1: LIGHTPORT = 0b01100110; break;
                case 0: LIGHTPORT = 0b10100101; break;
	}

	step++;

        return ret;
}

int pattern45()
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
		case 7: LIGHTPORT = 0b01100110; break;
		case 6: LIGHTPORT = 0b10000001; break;
		case 5: LIGHTPORT = 0b01100110; break;
		case 4: LIGHTPORT = 0b10000001; break;
                case 3: LIGHTPORT = 0b01100110; break;
                case 2: LIGHTPORT = 0b10000001; break;
                case 1: LIGHTPORT = 0b01100110; break;
                case 0: LIGHTPORT = 0b10000001; break;
	}

	step++;

        return ret;
}

int pattern46()
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
		case 7: LIGHTPORT = 0b00011000; break;
		case 6: LIGHTPORT = 0b00011000; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b11000011; break;
                case 1: LIGHTPORT = 0b11111111; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern47()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b10011001; break;
                case 2: LIGHTPORT = 0b00100100; break;
                case 1: LIGHTPORT = 0b01100110; break;
                case 0: LIGHTPORT = 0b11011011; break;
	}

	step++;

        return ret;
}

int pattern48()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b00000000; break;
		case 5: LIGHTPORT = 0b10000001; break;
		case 4: LIGHTPORT = 0b00000000; break;
                case 3: LIGHTPORT = 0b10000001; break;
                case 2: LIGHTPORT = 0b01100110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern49()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b01111110; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b11100111; break;
	}

	step++;

        return ret;
}

int pattern50()
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
		case 7: LIGHTPORT = 0b00011000; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b01111110; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00111100; break;
	}

	step++;

        return ret;
}

int pattern51()
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
		case 7: LIGHTPORT = 0b10011001; break;
		case 6: LIGHTPORT = 0b10011001; break;
		case 5: LIGHTPORT = 0b10011001; break;
		case 4: LIGHTPORT = 0b10011001; break;
                case 3: LIGHTPORT = 0b01100110; break;
                case 2: LIGHTPORT = 0b01100110; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern52()
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
		case 7: LIGHTPORT = 0b10011001; break;
		case 6: LIGHTPORT = 0b10011001; break;
		case 5: LIGHTPORT = 0b10011001; break;
		case 4: LIGHTPORT = 0b10011001; break;
                case 3: LIGHTPORT = 0b10011001; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern53()
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
		case 7: LIGHTPORT = 0b10011001; break;
		case 6: LIGHTPORT = 0b10011001; break;
		case 5: LIGHTPORT = 0b10011001; break;
		case 4: LIGHTPORT = 0b10011001; break;
                case 3: LIGHTPORT = 0b11100111; break;
                case 2: LIGHTPORT = 0b01100110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern54()
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
		case 7: LIGHTPORT = 0b10011001; break;
		case 6: LIGHTPORT = 0b10011001; break;
		case 5: LIGHTPORT = 0b10111101; break;
		case 4: LIGHTPORT = 0b10100101; break;
                case 3: LIGHTPORT = 0b11100111; break;
                case 2: LIGHTPORT = 0b01100110; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern55()
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
		case 7: LIGHTPORT = 0b11000011; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b11000011; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b01100110; break;
	}

	step++;

        return ret;
}

int pattern56()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b10011001; break;
		case 5: LIGHTPORT = 0b10111101; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b10000001; break;
                case 2: LIGHTPORT = 0b01000010; break;
                case 1: LIGHTPORT = 0b00100100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern57()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b00011000; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern58()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b01111110; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern59()
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
		case 7: LIGHTPORT = 0b11100111; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00111100; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b00111100; break;
                case 0: LIGHTPORT = 0b01100110; break;
	}

	step++;

        return ret;
}

int pattern60()
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
		case 7: LIGHTPORT = 0b11100111; break;
		case 6: LIGHTPORT = 0b01000010; break;
		case 5: LIGHTPORT = 0b01000010; break;
		case 4: LIGHTPORT = 0b01000010; break;
                case 3: LIGHTPORT = 0b00100100; break;
                case 2: LIGHTPORT = 0b00100100; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern61()
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
		case 7: LIGHTPORT = 0b11100111; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b10000001; break;
		case 4: LIGHTPORT = 0b10000001; break;
                case 3: LIGHTPORT = 0b10000001; break;
                case 2: LIGHTPORT = 0b11000011; break;
                case 1: LIGHTPORT = 0b11100111; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern62()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b11100111; break;
		case 5: LIGHTPORT = 0b11000011; break;
		case 4: LIGHTPORT = 0b10000001; break;
                case 3: LIGHTPORT = 0b10000001; break;
                case 2: LIGHTPORT = 0b01000010; break;
                case 1: LIGHTPORT = 0b00100100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern63()
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
		case 7: LIGHTPORT = 0b01000010; break;
		case 6: LIGHTPORT = 0b11100111; break;
		case 5: LIGHTPORT = 0b10100101; break;
		case 4: LIGHTPORT = 0b10100101; break;
                case 3: LIGHTPORT = 0b10111101; break;
                case 2: LIGHTPORT = 0b01011010; break;
                case 1: LIGHTPORT = 0b00100100; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern64()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b11000011; break;
		case 5: LIGHTPORT = 0b11100111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b01111110; break;
                case 2: LIGHTPORT = 0b00111100; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00000000; break;
	}

	step++;

        return ret;
}

int pattern65()
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
		case 7: LIGHTPORT = 0b00111100; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b00111100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b01111110; break;
                case 2: LIGHTPORT = 0b01111110; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern66()
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
		case 7: LIGHTPORT = 0b11100111; break;
		case 6: LIGHTPORT = 0b00111100; break;
		case 5: LIGHTPORT = 0b00011000; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00100100; break;
                case 0: LIGHTPORT = 0b10000001; break;
	}

	step++;

        return ret;
}

int pattern67()
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
		case 7: LIGHTPORT = 0b00111100; break;
		case 6: LIGHTPORT = 0b01100110; break;
		case 5: LIGHTPORT = 0b11000011; break;
		case 4: LIGHTPORT = 0b01100110; break;
                case 3: LIGHTPORT = 0b00111100; break;
                case 2: LIGHTPORT = 0b00011000; break;
                case 1: LIGHTPORT = 0b00011000; break;
                case 0: LIGHTPORT = 0b00011000; break;
	}

	step++;

        return ret;
}

int pattern68()
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
		case 7: LIGHTPORT = 0b00000001; break;
		case 6: LIGHTPORT = 0b00000011; break;
		case 5: LIGHTPORT = 0b00000111; break;
		case 4: LIGHTPORT = 0b00001111; break;
                case 3: LIGHTPORT = 0b00011111; break;
                case 2: LIGHTPORT = 0b00111111; break;
                case 1: LIGHTPORT = 0b01111111; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern69()
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
		case 7: LIGHTPORT = 0b10000000; break;
		case 6: LIGHTPORT = 0b11000000; break;
		case 5: LIGHTPORT = 0b11100000; break;
		case 4: LIGHTPORT = 0b11110000; break;
                case 3: LIGHTPORT = 0b11111000; break;
                case 2: LIGHTPORT = 0b11111100; break;
                case 1: LIGHTPORT = 0b11111110; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern70()
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
		case 7: LIGHTPORT = 0b00000000; break;
		case 6: LIGHTPORT = 0b00000011; break;
		case 5: LIGHTPORT = 0b00000000; break;
		case 4: LIGHTPORT = 0b00001111; break;
                case 3: LIGHTPORT = 0b00000000; break;
                case 2: LIGHTPORT = 0b00111111; break;
                case 1: LIGHTPORT = 0b00000000; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern71()
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
		case 7: LIGHTPORT = 0b00000000; break;
		case 6: LIGHTPORT = 0b11000000; break;
		case 5: LIGHTPORT = 0b00000000; break;
		case 4: LIGHTPORT = 0b11110000; break;
                case 3: LIGHTPORT = 0b00000000; break;
                case 2: LIGHTPORT = 0b11111100; break;
                case 1: LIGHTPORT = 0b00000000; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}


int pattern72()
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
		case 7: LIGHTPORT = 0b00000001; break;
		case 6: LIGHTPORT = 0b01000000; break;
		case 5: LIGHTPORT = 0b00000010; break;
		case 4: LIGHTPORT = 0b00100000; break;
                case 3: LIGHTPORT = 0b00000100; break;
                case 2: LIGHTPORT = 0b00010000; break;
                case 1: LIGHTPORT = 0b00001000; break;
                case 0: LIGHTPORT = 0b00010000; break;
	}

	step++;

        return ret;
}

int pattern73()
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
		case 7: LIGHTPORT = 0b10000000; break;
		case 6: LIGHTPORT = 0b00000010; break;
		case 5: LIGHTPORT = 0b01000000; break;
		case 4: LIGHTPORT = 0b00000100; break;
                case 3: LIGHTPORT = 0b00100000; break;
                case 2: LIGHTPORT = 0b00001000; break;
                case 1: LIGHTPORT = 0b00010000; break;
                case 0: LIGHTPORT = 0b00001000; break;
	}

	step++;

        return ret;
}

int pattern74()
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
		case 7: LIGHTPORT = 0b11100000; break;
		case 6: LIGHTPORT = 0b00111000; break;
		case 5: LIGHTPORT = 0b00001110; break;
		case 4: LIGHTPORT = 0b00000011; break;
                case 3: LIGHTPORT = 0b00000011; break;
                case 2: LIGHTPORT = 0b00001110; break;
                case 1: LIGHTPORT = 0b00111000; break;
                case 0: LIGHTPORT = 0b11100000; break;
	}

	step++;

        return ret;
}

int pattern75()
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
		case 7: LIGHTPORT = 0b00000111; break;
		case 6: LIGHTPORT = 0b00011100; break;
		case 5: LIGHTPORT = 0b01110000; break;
		case 4: LIGHTPORT = 0b11000000; break;
                case 3: LIGHTPORT = 0b11000000; break;
                case 2: LIGHTPORT = 0b01110000; break;
                case 1: LIGHTPORT = 0b00011100; break;
                case 0: LIGHTPORT = 0b00000111; break;
	}

	step++;

        return ret;
}

int pattern76()
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
		case 7: LIGHTPORT = 0b10000000; break;
		case 6: LIGHTPORT = 0b01000000; break;
		case 5: LIGHTPORT = 0b00100000; break;
		case 4: LIGHTPORT = 0b00010000; break;
                case 3: LIGHTPORT = 0b00001000; break;
                case 2: LIGHTPORT = 0b00000100; break;
                case 1: LIGHTPORT = 0b00000010; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern77()
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
		case 7: LIGHTPORT = 0b00000001; break;
		case 6: LIGHTPORT = 0b00000010; break;
		case 5: LIGHTPORT = 0b00000100; break;
		case 4: LIGHTPORT = 0b00001000; break;
                case 3: LIGHTPORT = 0b00010000; break;
                case 2: LIGHTPORT = 0b00100000; break;
                case 1: LIGHTPORT = 0b01000000; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern78()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b01111111; break;
		case 5: LIGHTPORT = 0b00111111; break;
		case 4: LIGHTPORT = 0b00011111; break;
                case 3: LIGHTPORT = 0b00011111; break;
                case 2: LIGHTPORT = 0b00100111; break;
                case 1: LIGHTPORT = 0b01000011; break;
                case 0: LIGHTPORT = 0b10000001; break;
	}

	step++;

        return ret;
}

int pattern79()
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
		case 7: LIGHTPORT = 0b11111111; break;
		case 6: LIGHTPORT = 0b11111110; break;
		case 5: LIGHTPORT = 0b11111100; break;
		case 4: LIGHTPORT = 0b11111000; break;
                case 3: LIGHTPORT = 0b11111000; break;
                case 2: LIGHTPORT = 0b11100100; break;
                case 1: LIGHTPORT = 0b11000010; break;
                case 0: LIGHTPORT = 0b10000001; break;
	}

	step++;

        return ret;
}

int pattern80()
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
		case 7: LIGHTPORT = 0b01000000; break;
		case 6: LIGHTPORT = 0b00010000; break;
		case 5: LIGHTPORT = 0b00000100; break;
		case 4: LIGHTPORT = 0b00000001; break;
                case 3: LIGHTPORT = 0b00000011; break;
                case 2: LIGHTPORT = 0b00001111; break;
                case 1: LIGHTPORT = 0b00111111; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern81()
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
		case 7: LIGHTPORT = 0b00000010; break;
		case 6: LIGHTPORT = 0b00001000; break;
		case 5: LIGHTPORT = 0b00100000; break;
		case 4: LIGHTPORT = 0b10000000; break;
                case 3: LIGHTPORT = 0b11000000; break;
                case 2: LIGHTPORT = 0b11110000; break;
                case 1: LIGHTPORT = 0b11111100; break;
                case 0: LIGHTPORT = 0b11111111; break;
	}

	step++;

        return ret;
}

int pattern82()
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
		case 7: LIGHTPORT = 0b10000000; break;
		case 6: LIGHTPORT = 0b10000000; break;
		case 5: LIGHTPORT = 0b11000000; break;
		case 4: LIGHTPORT = 0b11000000; break;
                case 3: LIGHTPORT = 0b11100000; break;
                case 2: LIGHTPORT = 0b11100000; break;
                case 1: LIGHTPORT = 0b11110000; break;
                case 0: LIGHTPORT = 0b11110000; break;
	}

	step++;

        return ret;
}

int pattern83()
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
		case 7: LIGHTPORT = 0b00000001; break;
		case 6: LIGHTPORT = 0b00000001; break;
		case 5: LIGHTPORT = 0b00000011; break;
		case 4: LIGHTPORT = 0b00000011; break;
                case 3: LIGHTPORT = 0b00000111; break;
                case 2: LIGHTPORT = 0b00000111; break;
                case 1: LIGHTPORT = 0b00001111; break;
                case 0: LIGHTPORT = 0b00001111; break;
	}

	step++;

        return ret;
}

int pattern84()
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
		case 7: LIGHTPORT = 0b00000001; break;
		case 6: LIGHTPORT = 0b00000100; break;
		case 5: LIGHTPORT = 0b00010000; break;
		case 4: LIGHTPORT = 0b01000000; break;
                case 3: LIGHTPORT = 0b00000010; break;
                case 2: LIGHTPORT = 0b00001000; break;
                case 1: LIGHTPORT = 0b00100000; break;
                case 0: LIGHTPORT = 0b10000000; break;
	}

	step++;

        return ret;
}

int pattern85()
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
		case 7: LIGHTPORT = 0b00000011; break;
		case 6: LIGHTPORT = 0b00001100; break;
		case 5: LIGHTPORT = 0b00110000; break;
		case 4: LIGHTPORT = 0b11000000; break;
                case 3: LIGHTPORT = 0b00000011; break;
                case 2: LIGHTPORT = 0b00001100; break;
                case 1: LIGHTPORT = 0b00110000; break;
                case 0: LIGHTPORT = 0b11000000; break;
	}

	step++;

        return ret;
}

int pattern86()
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
		case 7: LIGHTPORT = 0b00000111; break;
		case 6: LIGHTPORT = 0b00111000; break;
		case 5: LIGHTPORT = 0b11000001; break;
		case 4: LIGHTPORT = 0b00001110; break;
                case 3: LIGHTPORT = 0b01110000; break;
                case 2: LIGHTPORT = 0b10000011; break;
                case 1: LIGHTPORT = 0b00011100; break;
                case 0: LIGHTPORT = 0b11100000; break;
	}

	step++;

        return ret;
}

int pattern87()
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
		case 7: LIGHTPORT = 0b10000000; break;
		case 6: LIGHTPORT = 0b11000000; break;
		case 5: LIGHTPORT = 0b11100000; break;
		case 4: LIGHTPORT = 0b11110000; break;
                case 3: LIGHTPORT = 0b00001111; break;
                case 2: LIGHTPORT = 0b00000111; break;
                case 1: LIGHTPORT = 0b00000011; break;
                case 0: LIGHTPORT = 0b00000001; break;
	}

	step++;

        return ret;
}

int pattern88()
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
		case 7: LIGHTPORT = 0b00001111; break;
		case 6: LIGHTPORT = 0b00001110; break;
		case 5: LIGHTPORT = 0b00001100; break;
		case 4: LIGHTPORT = 0b00001000; break;
                case 3: LIGHTPORT = 0b00010000; break;
                case 2: LIGHTPORT = 0b00110000; break;
                case 1: LIGHTPORT = 0b01110000; break;
                case 0: LIGHTPORT = 0b11110000; break;
	}

	step++;

        return ret;
}

int pattern89()
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
		case 7: LIGHTPORT = 0b10001111; break;
		case 6: LIGHTPORT = 0b01001110; break;
		case 5: LIGHTPORT = 0b00101100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00110100; break;
                case 1: LIGHTPORT = 0b01110010; break;
                case 0: LIGHTPORT = 0b11110001; break;
	}

	step++;

        return ret;
}

int pattern90()
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
		case 7: LIGHTPORT = 0b10000001; break;
		case 6: LIGHTPORT = 0b01000010; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00011000; break;
                case 3: LIGHTPORT = 0b00011000; break;
                case 2: LIGHTPORT = 0b00100100; break;
                case 1: LIGHTPORT = 0b01000010; break;
                case 0: LIGHTPORT = 0b10000001; break;
	}

	step++;

        return ret;
}

int pattern91()
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
		case 7: LIGHTPORT = 0b00011111; break;
		case 6: LIGHTPORT = 0b00111111; break;
		case 5: LIGHTPORT = 0b01111111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b11111110; break;
                case 1: LIGHTPORT = 0b11111100; break;
                case 0: LIGHTPORT = 0b11111000; break;
	}

	step++;

        return ret;
}

int pattern92()
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
		case 7: LIGHTPORT = 0b00000111; break;
		case 6: LIGHTPORT = 0b00011111; break;
		case 5: LIGHTPORT = 0b01111111; break;
		case 4: LIGHTPORT = 0b11111111; break;
                case 3: LIGHTPORT = 0b11111111; break;
                case 2: LIGHTPORT = 0b11111110; break;
                case 1: LIGHTPORT = 0b11111000; break;
                case 0: LIGHTPORT = 0b11100000; break;
	}

	step++;

        return ret;
}

int pattern93()
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
		case 7: LIGHTPORT = 0b10001000; break;
		case 6: LIGHTPORT = 0b10001000; break;
		case 5: LIGHTPORT = 0b01000100; break;
		case 4: LIGHTPORT = 0b01000100; break;
                case 3: LIGHTPORT = 0b00100010; break;
                case 2: LIGHTPORT = 0b00100010; break;
                case 1: LIGHTPORT = 0b00010001; break;
                case 0: LIGHTPORT = 0b00010001; break;
	}

	step++;

        return ret;
}

int pattern94()
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
		case 7: LIGHTPORT = 0b00000011; break;
		case 6: LIGHTPORT = 0b00000001; break;
		case 5: LIGHTPORT = 0b00001000; break;
		case 4: LIGHTPORT = 0b00001100; break;
                case 3: LIGHTPORT = 0b00110000; break;
                case 2: LIGHTPORT = 0b00010000; break;
                case 1: LIGHTPORT = 0b10000000; break;
                case 0: LIGHTPORT = 0b11000000; break;
	}

	step++;

        return ret;
}

int pattern95()
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
		case 7: LIGHTPORT = 0b00100101; break;
		case 6: LIGHTPORT = 0b00100110; break;
		case 5: LIGHTPORT = 0b00100100; break;
		case 4: LIGHTPORT = 0b00101100; break;
		case 3: LIGHTPORT = 0b00110100; break;
		case 2: LIGHTPORT = 0b00100100; break;
		case 1: LIGHTPORT = 0b01100100; break;
		case 0: LIGHTPORT = 0b10100100; break;
	}

	step++;

        return ret;
}

int pattern96()
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
		case 7: LIGHTPORT = 0b01000101; break;
		case 6: LIGHTPORT = 0b10101010; break;
		case 5: LIGHTPORT = 0b01010101; break;
		case 4: LIGHTPORT = 0b00101010; break;
                case 3: LIGHTPORT = 0b01010100; break;
                case 2: LIGHTPORT = 0b10101010; break;
                case 1: LIGHTPORT = 0b01010101; break;
                case 0: LIGHTPORT = 0b10100010; break;
	}

	step++;

        return ret;
}

int pattern97()
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
		case 7: LIGHTPORT = 0b00000011; break;
		case 6: LIGHTPORT = 0b11100000; break;
		case 5: LIGHTPORT = 0b00001111; break;
		case 4: LIGHTPORT = 0b11111000; break;
		case 3: LIGHTPORT = 0b00011111; break;
		case 2: LIGHTPORT = 0b11110000; break;
		case 1: LIGHTPORT = 0b00000111; break;
		case 0: LIGHTPORT = 0b11000000; break;
	}

	step++;

        return ret;
}

int pattern98()
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
		case 7: LIGHTPORT = 0b11111100; break;
		case 6: LIGHTPORT = 0b00000010; break;
		case 5: LIGHTPORT = 0b11110001; break;
		case 4: LIGHTPORT = 0b00101000; break;
		case 3: LIGHTPORT = 0b00010100; break;
		case 2: LIGHTPORT = 0b10001111; break;
		case 1: LIGHTPORT = 0b01000000; break;
		case 0: LIGHTPORT = 0b00111111; break;
	}

	step++;

        return ret;
}

int pattern99()
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
		case 7: LIGHTPORT = 0b00001111; break;
		case 6: LIGHTPORT = 0b00010001; break;
		case 5: LIGHTPORT = 0b00100001; break;
		case 4: LIGHTPORT = 0b01000001; break;
		case 3: LIGHTPORT = 0b10000010; break;
		case 2: LIGHTPORT = 0b10000100; break;
		case 1: LIGHTPORT = 0b10001000; break;
		case 0: LIGHTPORT = 0b11110000; break;
	}

	step++;

        return ret;
}
