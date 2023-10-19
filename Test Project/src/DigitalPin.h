#ifndef DIGIPIN_H
#define DIGIPIN_H

#include <Arduino.h>

class DigitalPin1 {
public:
    DigitalPin1(int pin1);
    
    void setTCCRA(uint8_t value);
    void setTCCRB(uint8_t value);
    void setTCNT(uint16_t value);
    void setOCR(uint16_t value);
    void factorOCR(float factor);
    void setTIMSK(uint8_t value);
    int getPin1() const;

    int pinNumber1;


private:
};

class DigitalPin2 {
public:
    DigitalPin2(int pin2);
    
    void setTCCRA(uint8_t value);
    void setTCCRB(uint8_t value);
    void setTCNT(uint16_t value);
    void setOCR(uint16_t value);
    void factorOCR(float factor);
    void setTIMSK(uint8_t value);
    int getPin2() const;

    int pinNumber2;


private:
};
class DigitalPin3 {
public:
    DigitalPin3(int pin3);
    
    void setTCCRA(uint8_t value);
    void setTCCRB(uint8_t value);
    void setTCNT(uint16_t value);
    void setOCR(uint16_t value);
    void factorOCR(float factor);
    void setTIMSK(uint8_t value);
    int getPin3() const;

    int pinNumber3;


private:
};

class DigitalPin4 {
public:
    DigitalPin4(int pin4);
    
    void setTCCRA(uint8_t value);
    void setTCCRB(uint8_t value);
    void setTCNT(uint16_t value);
    void setOCR(uint16_t value);
    void factorOCR(float factor);
    void setTIMSK(uint8_t value);
    int getPin4() const;

    int pinNumber4;


private:
};
#endif