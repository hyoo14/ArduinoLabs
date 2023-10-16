#include <Arduino.h>
#include "lab1.h"

LED :: LED(String Color) 
{   int pin;
    if (Color.equals("red"))
    {
       pin= 11;
    }
    else if (Color.equals("yellow"))
    {
        pin= 10;
    } else if (Color.equals("blue"))
    {
        pin= 8;
    } else if (Color.equals("green"))
    {
        pin= 9;
    }
    _pin=pin;
    pinMode(_pin,OUTPUT);
}


void LED :: led_on()
{
    digitalWrite(_pin,1);
}

void LED :: led_off()
{
    digitalWrite(_pin,0);
}

void LED :: led_inten(int intensity)
{
        analogWrite(_pin,intensity);
}  

void LED :: blink(int times, int on, int off)
{
    static int counter=0;
    while (counter<=times)
    {
        led_on();
        delay(on);
        led_off();
        delay(off);
        counter++;
    }
}