#include<lpc21xx.h>
#include "header.h"
//void lcd_data(unsigned char data)
//{
//    unsigned int temp;

//    // HIGHER NIBBLE
//    IOCLR1 = 0xFF << 16;                
//		temp = (data & 0xF0) << 16;          
//    IOSET1 = temp;
//    IOSET1 = 1<<17;                      
//    IOCLR1 = 1<<18;                     
//    IOSET1 = 1<<19;                      
//    delay_ms(2);
//    IOCLR1 = 1<<19;                      

//    // LOWER NIBBLE
//    IOCLR1 = 0xFF << 16;
//    temp = (data & 0x0F) << 20;          
//		IOSET1 = temp;
//    IOSET1 = 1<<17;
//    IOCLR1 = 1<<18;
//    IOSET1 = 1<<19;
//    delay_ms(2);
//    IOCLR1 = 1<<19;
//}

//void lcd_cmd(unsigned char cmd)
//{
//    unsigned int temp;

//    // HIGHER NIBBLE
//    IOCLR1 = 0xFF << 16;
//    temp = (cmd & 0xF0) << 16;
//    IOSET1 = temp;
//    IOCLR1 = 1<<17;                      
//    IOCLR1 = 1<<18;                      
//    IOSET1 = 1<<19;
//    delay_ms(2);
//    IOCLR1 = 1<<19;

//    // LOWER NIBBLE
//    IOCLR1 = 0xFF << 16;
//    temp = (cmd & 0x0F) << 20;
//    IOSET1 = temp;
//    IOCLR1 = 1<<17;
//    IOCLR1 = 1<<18;
//    IOSET1 = 1<<19;
//    delay_ms(2);
//    IOCLR1 = 1<<19;
//}

//void lcd_init(void)
//{
//    IODIR1 |= 0xFF << 16; 
//    PINSEL1 = 0x0;

//    lcd_cmd(0x02);  
//    lcd_cmd(0x28);  
//    lcd_cmd(0x0E); 
//    lcd_cmd(0x01);  
//}

void lcd_string(char *ptr)
{
    while(*ptr != 0)
    {
        lcd_data(*ptr++);
    }
}

void lcd_data(unsigned char data)
{
    unsigned int temp;

    // HIGHER NIBBLE
    IOCLR1 = 0xF << 20;                 // clear only data lines
    temp = (data & 0xF0) << 16;         // put D4-D7 on P1.20-23
    IOSET1 = temp;
    IOSET1 = 1<<17;                     // RS=1
    IOCLR1 = 1<<18;                     // RW=0
    IOSET1 = 1<<19;                     // EN=1
    delay_ms(2);
    IOCLR1 = 1<<19;                     // EN=0

    // LOWER NIBBLE
    IOCLR1 = 0xF << 20;
    temp = (data & 0x0F) << 20;
    IOSET1 = temp;
    IOSET1 = 1<<17;
    IOCLR1 = 1<<18;
    IOSET1 = 1<<19;
    delay_ms(2);
    IOCLR1 = 1<<19;
}

void lcd_cmd(unsigned char cmd)
{
    unsigned int temp;

    // HIGHER NIBBLE
    IOCLR1 = 0xF << 20;
    temp = (cmd & 0xF0) << 16;
    IOSET1 = temp;
    IOCLR1 = 1<<17;                     // RS=0
    IOCLR1 = 1<<18;                     // RW=0
    IOSET1 = 1<<19;                     // EN=1
    delay_ms(2);
    IOCLR1 = 1<<19;

    // LOWER NIBBLE
    IOCLR1 = 0xF << 20;
    temp = (cmd & 0x0F) << 20;
    IOSET1 = temp;
    IOCLR1 = 1<<17;
    IOCLR1 = 1<<18;
    IOSET1 = 1<<19;
    delay_ms(2);
    IOCLR1 = 1<<19;
}

void lcd_init(void)
{
    IODIR1 |= (0xF << 20) | (1<<17) | (1<<18) | (1<<19); 
    PINSEL1 = 0x0;

    lcd_cmd(0x02);  
    lcd_cmd(0x28);  
    lcd_cmd(0x0C);  // Display ON, Cursor OFF
    lcd_cmd(0x06);  // Entry mode set
    lcd_cmd(0x01);  
    delay_ms(5);
}
