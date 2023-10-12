#include "DigiPin.h"
#include <Arduino.h>

Pin::Pin(int p) : pin(p) {
    pinMode(pin, OUTPUT);
}

void Pin::set_TCCRA() {
    // dummy implementation, you need to set actual values
}

void Pin::set_TCCRB(int wgm, int cs1, int cs0) {
    // dummy implementation, you need to set actual values
}

void Pin::set_TCNT() {
    // dummy implementation, you need to reset the timer count or set a specific value
}

void Pin::set_OCR(int value) {
    // dummy implementation, set Output Compare Register value
}

void Pin::set_TIMSK(int value) {
    // dummy implementation, set Timer Interrupt Mask Register
}

void Pin::factor_OCR(int factor) {
    // dummy implementation, modify the Output Compare Register with a factor
}
