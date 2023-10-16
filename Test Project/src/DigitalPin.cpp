#include <Arduino.h>
#include "DigitalPin.h"

// put function declarations here:
DigitalPin::DigitalPin(int pin, uint8_t pinBit, volatile uint8_t *portX, volatile uint8_t *ddrX, volatile uint8_t *pinX){
  _pin = pin;
  set_pin(pinBit, portX, ddrX, pinX);
}

void DigitalPin::set_pin(uint8_t pinBit, volatile uint8_t *portX, volatile uint8_t *ddrX, volatile uint8_t *pinX){
  _portX = portX;
  _ddrX = ddrX;
  _pinBit = pinBit;
  _pinX = pinX;
  findPinBit();
}

void DigitalPin::set_input_mode(){
  //*_ddrX &= !_pinBit;
  *_ddrX &= ~_pinBit;
}

void DigitalPin::set_output_mode(){
  *_ddrX |= _pinBit;
}

void DigitalPin::on(){
  *_portX |= _pinBit;
}

void DigitalPin::off(){
  *_portX &= !_pinBit;
}

void DigitalPin::invert_pin(){
  if(digitalRead() == 1) off();  //pin is high
  else  on();   //pin is low  
}

void DigitalPin::set_TCCRA(volatile uint8_t* reg, uint8_t value) {
  *reg = value;
}

    // Set TCCRB register based on the associated pin
void DigitalPin::set_TCCRB(volatile uint8_t* reg, uint8_t value) {
  *reg = value;
}

    // Set TCNT register based on the associated pin
void DigitalPin::set_TCNT(volatile uint16_t* reg, uint16_t value) {
  *reg = value;
}

    // Set OCR register based on the associated pin
void DigitalPin::set_OCR(volatile uint16_t* reg, uint16_t value) {
  *reg = value;
}

    // Factor OCR register based on the associated pin
volatile void DigitalPin::factor_OCR(volatile uint16_t* reg, double factor) {
  *reg = *reg * factor;
}

    // Set TIMSK register based on the associated pin
void DigitalPin::set_TIMSK(volatile uint8_t* reg, uint8_t value) {
  *reg = value;
}

int DigitalPin::getPin(){
  return _pin;
}

int DigitalPin::getPinPosition(){
  return _pinBitPosition;
}

void DigitalPin::findPinBit(){
  int read, temp = 1;
  for(int i = 0; i < 8; i++){
    if(temp == _pinBit){
      read = i;
      break;
    }
    temp = temp * 2;
  }
  _pinBitPosition = read;
}

int DigitalPin::digitalRead(){
  int read;
  read = (*_pinX >> _pinBitPosition & _pinBit >> _pinBitPosition);
  return read;
}

void DigitalPin::printPos(){
  Serial.println(_pinBitPosition);
  Serial.println(_pinBit);
}