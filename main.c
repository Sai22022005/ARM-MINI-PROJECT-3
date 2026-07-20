// Project Title: AI Secure Login Authentication System Using LPC2129 with EM-18 RFID Reader and 4x4 Keypad Matrix 

#include <lpc21xx.h>
#include <string.h>
#include"header.h"
#define GREEN_LED (1<<19)
#define RED_LED   (1<<20)

char valid_rfid[] = "1234567890";   // Example RFID
char valid_pass[] = "1234";         // Example password

int main(void)
{
    char rfid[12], pass[5];
    int i;
		uart0_init(9600);
    	lcd_init();
		keypad_init();
//		 IODIR0 |= 0xF0;// keyboard init;
   		 IODIR1 |= GREEN_LED | RED_LED;
   		 IOSET1 = GREEN_LED | RED_LED;   

    lcd_string("AISECURITYSYSTEM");
  //  delay_ms(00);
    while(1)
	{
        lcd_string("SCAN RFID CARD");
        // Read RFID (10 chars)
        for(i=0; i<12; i++) 
		{
    		rfid[i] = uart0_rx();
   			if(rfid[i] >= '0' && rfid[i] <= '9')  // only digits
        	lcd_data(rfid[i]);
		}
				rfid[i] = '\0';
		
        if(strcmp(rfid, valid_rfid) == 0)
		{
            lcd_string("RFID VERIFIED");
            lcd_string("ENTER PASSWORD");
            for(i=0; i<4; i++) 
			{
                pass[i] = keypad_scan();
                lcd_string("*");   // Mask input
            }
            pass[i] = '\0';

            if (strcmp(pass, valid_pass) == 0)
			{
                IOCLR1= GREEN_LED;   // LED ON
                IOSET1 = RED_LED;     // LED OFF
                lcd_string("ACCESS GRANTED");
			} 
			else 
			{	
                IOCLR1 = RED_LED;     // LED ON
                IOSET1 = GREEN_LED;   // LED OFF
                lcd_string("ACCESS DENIED");
        	}
		}
		else
		{
            IOCLR1 = RED_LED;         // LED ON
            IOSET1 = GREEN_LED;       // LED OFF
            lcd_string("INVALID RFID");
        }
        delay_ms(300);
        IOSET1 = GREEN_LED | RED_LED; // Reset LEDs OFF
    }
}
