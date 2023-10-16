#ifndef lab1_h
#define lab1_h 

#include <Arduino.h>

class LED
{
    public:
        LED(String Color);
        void led_on();
        void led_off();
        void led_inten(int intensity);
        void blink(int times, int on, int off);
    
    private:
        int _pin;
    
};

#endif