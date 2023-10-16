#ifndef DigitalPin_h
#define DigitalPin_h

#include <Arduino.h>

class DigitalPin{
    public:
        DigitalPin(int pin, uint8_t pinBit, volatile uint8_t *portX, volatile uint8_t *ddrX, volatile uint8_t *pinX);
        void set_pin(uint8_t pinBit, volatile uint8_t *portX, volatile uint8_t *ddrX, volatile uint8_t *pinX);
        void set_input_mode();
        void set_output_mode();
        void on();
        void off();
        void invert_pin();
        void set_TCCRA(volatile uint8_t* reg, uint8_t value);
        void set_TCCRB(volatile uint8_t* reg, uint8_t value);
        void set_TCNT(volatile uint16_t* reg, uint16_t value);
        void set_OCR(volatile uint16_t* reg, uint16_t value);
        volatile void factor_OCR(volatile uint16_t* reg, double factor);
        void set_TIMSK(volatile uint8_t* reg, uint8_t value);
        int getPin();
        int getPinPosition();
        void findPinBit();
        int digitalRead();
        void printPos();
    private:
        int _pin;
        int _pinBit;
        uint8_t _pinBitPosition;
        volatile uint8_t *_portX;
        volatile uint8_t *_ddrX;
        volatile uint8_t *_pinX;
};

#endif