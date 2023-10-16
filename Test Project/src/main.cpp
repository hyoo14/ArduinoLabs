#include <Arduino.h>
#include <string.h>
#include "DigitalPin.h"
#include "safe.h"

// put function declarations here:
char temp;
Safe safe;
int result[4]={0,0,0,0};
int attempts = 0;
// DigitalPin firstLight(11, 0b00100000, &PORTB, &DDRB, &PINB);  //light on timer1
// DigitalPin secondLight(5, 0b00001000, &PORTE, &DDRE, &PINE);  //light on timer3
// DigitalPin thirdLight(6, 0b00001000, &PORTH, &DDRH, &PINH);   //light on timer4
// DigitalPin fourthLight(44, 0b00100000, &PORTL, &DDRL, &PINL);    //light on timer5
DigitalPin firstLight(11, 0b00100000, &PORTB, &DDRB, &PINB);  //light on timer1
DigitalPin secondLight(10, 0b00001000, &PORTE, &DDRE, &PINE);  //light on timer3
DigitalPin thirdLight(9, 0b00001000, &PORTH, &DDRH, &PINH);   //light on timer4
DigitalPin fourthLight(8, 0b00100000, &PORTL, &DDRL, &PINL);    //light on timer5

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  //timer 1
  noInterrupts();  
  firstLight.set_TCCRA(&TCCR1A,0b10000000);
  firstLight.set_TCCRB(&TCCR1B,0b00001100);
  firstLight.set_TCNT(&TCNT1,0);
  firstLight.set_OCR(&OCR1A,62499);
  firstLight.set_TIMSK(&TIMSK1, 0b00000010);
  //timer3
  secondLight.set_TCCRA(&TCCR3A,0b10000000);
  secondLight.set_TCCRB(&TCCR3B,0b00001100);
  secondLight.set_TCNT(&TCNT3,0);
  secondLight.set_OCR(&OCR3A,62499);
  secondLight.set_TIMSK(&TIMSK3, 0b00000010);
  //timer4
  thirdLight.set_TCCRA(&TCCR4A,0b10000000);
  thirdLight.set_TCCRB(&TCCR4B,0b00001100);
  thirdLight.set_TCNT(&TCNT4,0);
  thirdLight.set_OCR(&OCR4A,62499);
  thirdLight.set_TIMSK(&TIMSK4, _BV(OCIE4A));
  //timer5
  fourthLight.set_TCCRA(&TCCR5A,0b10000000);
  fourthLight.set_TCCRB(&TCCR5B,0b00001100);
  fourthLight.set_TCNT(&TCNT5,0);
  fourthLight.set_OCR(&OCR5A,62499);
  fourthLight.set_TIMSK(&TIMSK5, 0b00000010);

  Serial.print("\nHere is the passcode(FOR TESTING/GRADING): ");
  for(int i = 0; i < 4; i++) Serial.print(safe.getChar(i));
  Serial.print("\n");
  sei();
  interrupts();  
}

ISR(TIMER1_COMPA_vect) {
  firstLight.invert_pin();  // Toggle the LED state
}

ISR(TIMER3_COMPA_vect) {
  secondLight.invert_pin();  // Toggle the LED state
}

ISR(TIMER4_COMPA_vect) {
  thirdLight.invert_pin();  // Toggle the LED state
}

ISR(TIMER5_COMPA_vect) {
  fourthLight.invert_pin();  // Toggle the LED state
}

void loop() {
  // put your main code here, to run repeatedly:
  String resultString;
  
  while (Serial.available()>0){
    String userInput = Serial.readString();
    while (Serial.available()>0){
      temp = Serial.read();
    }
    safe.compareCode(result,userInput);
    
    if(++attempts >= 5){
      firstLight.on();
      firstLight.set_TCCRB(&TCCR1B, ~_BV(CS12) | ~_BV(CS11) | ~_BV(CS10));
      secondLight.on();
      secondLight.set_TCCRB(&TCCR3B, ~_BV(CS32) | ~_BV(CS31) | ~_BV(CS30));
      thirdLight.on();
      thirdLight.set_TCCRB(&TCCR4B, ~_BV(CS42) | ~_BV(CS41) | ~_BV(CS40));
      fourthLight.on();
      fourthLight.set_TCCRB(&TCCR5B, ~_BV(CS52) | ~_BV(CS51) | ~_BV(CS50));
    }

    if(result[0] <= -1){
      firstLight.set_TCCRB(&TCCR1B, ~_BV(CS12) | ~_BV(CS11) | ~_BV(CS10));
      firstLight.off();
    } else { firstLight.factor_OCR(&OCR1A,0.5);}
    if(result[1] <= -1){
      secondLight.set_TCCRB(&TCCR3B, ~_BV(CS32) | ~_BV(CS31) | ~_BV(CS30));
      secondLight.off();
    } else {secondLight.factor_OCR(&OCR3A,0.5);}
    if(result[2] <= -1){
      thirdLight.set_TCCRB(&TCCR4B, ~_BV(CS42) | ~_BV(CS41) | ~_BV(CS40));
      thirdLight.off();
    } else {thirdLight.factor_OCR(&OCR4A,0.5);}
    if(result[3] <= -1){
      fourthLight.set_TCCRB(&TCCR5B, ~_BV(CS52) | ~_BV(CS51) | ~_BV(CS50));
      fourthLight.off();
    } else {fourthLight.factor_OCR(&OCR5A,0.5);}
  }
  
}