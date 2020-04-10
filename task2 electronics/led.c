#include<reg51.h>
sbit LED1 =  P0^0; // this will be blinking every 50ms
sbit LED2 =  P0^1; // will show switch status(inverted)
sbit SW = P3^2;

void timer0_isr() interrupt 1
{
    TH0  = 0X4B;        //ReLoad the timer value (50ms)
    TL0  = 0XFD;
    LED1 =!LED1;        // Toggle the LED pin 
}

void main()
{
    TMOD = 0x01;       //Timer0 mode 1 
    TH0 = 0X4B;        //Load the timer value
    TL0 = 0XFD;
    TR0 = 1;           //turn ON Timer zero
    ET0 = 1;           //Enable TImer0 Interrupt
    EA = 1;            //Enable Global Interrupt bit
    SW = 1;            //Make SW pin as input
    while(1)
    {
        LED2= SW;      //Display the SW status on led(P0.1)
    } 
}