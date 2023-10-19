#include "DigitalPin.h"

DigitalPin1::DigitalPin1(int pin1) : pinNumber1(pin1) {
    pinMode(pinNumber1, OUTPUT);
    digitalWrite(pinNumber1, LOW);
}

void DigitalPin1::setTCCRA(uint8_t value) { TCCR1A = value; }
void DigitalPin1::setTCCRB(uint8_t value) { TCCR1B = value; }
void DigitalPin1::setTCNT(uint16_t value) { TCNT1 = value; }
void DigitalPin1::setOCR(uint16_t value) { OCR1A = value; }
void DigitalPin1::factorOCR(float factor) { OCR1A = (uint16_t)(OCR1A * factor); }
void DigitalPin1::setTIMSK(uint8_t value) { TIMSK1 = value; }
int DigitalPin1::getPin1() const {
    return pinNumber1;
}

DigitalPin2::DigitalPin2(int pin2) : pinNumber2(pin2) {
    pinMode(pinNumber2, OUTPUT);
    digitalWrite(pinNumber2, LOW);
}

void DigitalPin2::setTCCRA(uint8_t value) { TCCR1A = value; }
void DigitalPin2::setTCCRB(uint8_t value) { TCCR1B = value; }
void DigitalPin2::setTCNT(uint16_t value) { TCNT1 = value; }
void DigitalPin2::setOCR(uint16_t value) { OCR1A = value; }
void DigitalPin2::factorOCR(float factor) { OCR1A = (uint16_t)(OCR1A * factor); }
void DigitalPin2::setTIMSK(uint8_t value) { TIMSK1 = value; }
int DigitalPin2::getPin2() const {
    return pinNumber2;
}

DigitalPin3::DigitalPin3(int pin3) : pinNumber3(pin3) {
    pinMode(pinNumber3, OUTPUT);
    digitalWrite(pinNumber3, LOW);
}

void DigitalPin3::setTCCRA(uint8_t value) { TCCR1A = value; }
void DigitalPin3::setTCCRB(uint8_t value) { TCCR1B = value; }
void DigitalPin3::setTCNT(uint16_t value) { TCNT1 = value; }
void DigitalPin3::setOCR(uint16_t value) { OCR1A = value; }
void DigitalPin3::factorOCR(float factor) { OCR1A = (uint16_t)(OCR1A * factor); }
void DigitalPin3::setTIMSK(uint8_t value) { TIMSK1 = value; }
int DigitalPin3::getPin3() const {
    return pinNumber3;
}

DigitalPin4::DigitalPin4(int pin4) : pinNumber4(pin4) {
    pinMode(pinNumber4, OUTPUT);
    digitalWrite(pinNumber4, LOW);
}

void DigitalPin4::setTCCRA(uint8_t value) { TCCR1A = value; }
void DigitalPin4::setTCCRB(uint8_t value) { TCCR1B = value; }
void DigitalPin4::setTCNT(uint16_t value) { TCNT1 = value; }
void DigitalPin4::setOCR(uint16_t value) { OCR1A = value; }
void DigitalPin4::factorOCR(float factor) { OCR1A = (uint16_t)(OCR1A * factor); }
void DigitalPin4::setTIMSK(uint8_t value) { TIMSK1 = value; }
int DigitalPin4::getPin4() const {
    return pinNumber4;
}