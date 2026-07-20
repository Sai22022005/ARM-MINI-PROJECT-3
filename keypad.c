#include<lpc21xx.h>
#include "header.h"

void keypad_init(void)
{
IODIR0 |= 0xF0;
}

char keypad_scan(void)
{
    int row, col;
    char keys[4][4] =
	{
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
    };

    while(1)
	{
		for(row=0; row<4; row++) 
		{
            IO0SET = 0xF0;             // all rows high
            IO0CLR = (1<<(row+4));     // drive one row low
            col = IO0PIN & 0x0F;       // read cols
            if(col != 0x0F) 
			{
                if(!(col & 0x01)) return keys[row][0];
                if(!(col & 0x02)) return keys[row][1];
                if(!(col & 0x04)) return keys[row][2];
                if(!(col & 0x08)) return keys[row][3];
            }
        }
    }
}

