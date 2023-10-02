#include <Arduino.h>

// // put function declarations here:
// int LED_PIN = 5;

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(LED_PIN, OUTPUT); //set pin 5 to only output
//   digitalWrite(5, LOW); // set pint 5 to a value of LOW
//   noInterrupts(); // disable all interrupts
//   TCCR3A=0; // Initializes all bits in TCCR3A to zero
//   TIMSK3=0;
//   TCNT3=0; // Initializes counter TCNT3 to 0
//   OCR3A=15624;
//   TCCR3B |=(1<<WGM32); // Places in waveform generation mode 4
//   TCCR3B |=(1<<CS32) | (0<<CS31) | (0<<CS30); // set prescalar to 256
//   TIMSK3 |=(1<<OCIE3A); //Enable timer 3 pin 5 output compare flag
//   interrupts();
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// ISR(TIMER3_COMPA_vect){
//   digitalWrite(LED_PIN,!digitalRead(LED_PIN)); //Flips output value
// }


int LED_PIN=5; // Pin LED is connected to
void setup() {
  pinMode(LED_PIN,OUTPUT); // Set pin 5 to only output
  digitalWrite(5,LOW); // Set pin 5 to a value of LOW
  noInterrupts(); // Disable all interrupts
  TCCR3A=0; // Initializes all bits in TCCR3A to zero
  TCCR3B=0; // Initializes all bits in TCCR3B to zero
  TIMSK3=0;
  TCNT3=0; // Initializes counter TCNT3 to 0
  OCR3A=15624;
  TCCR3B |=(1<<WGM32); // Places in waveform generation mode 4
  TCCR3B |= (1<<CS32) |(0<<CS31) |(0<<CS30); //Set prescalar to 256
  TIMSK3 |=(1<<OCIE3A); //Enable timer 3 pin 5 output compare flag
  interrupts();
}

void loop() {
  
}
ISR(TIMER3_COMPA_vect){
  digitalWrite(LED_PIN,!digitalRead(LED_PIN)); // Flips output value
}

 