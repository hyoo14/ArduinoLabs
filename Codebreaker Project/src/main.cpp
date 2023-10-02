#include <Arduino.h>

int user;
int user_arr[4];

int attemp=3;
int error =0;

int led0=11;
int led1=5;
int led2=6;
int led3=44;

int tog, tog1, tog2, tog3, num;

void setupt(){
  
  Serial.begin(9600);

  randomSeed(analogRead(0));
  num = random(9999);
  Serial.println(num);
  pass[3] = num % 10;
  num /= 10;

}











// #include <Arduino.h>
// #include "DigiPin.h"
// #include "Safe.h"

// Pin red(11);
// Pin yellow(9);
// Pin blue(8);
// Pin green(10);
// Pin pins[] = {red, green, blue, yellow};
// Safe safe1;

// void pin_init(Pin color) { 
//     color.set_TCCRA();
//     color.set_TCCRB(1, 0, 0);
//     color.set_TCNT();
//     color.set_OCR(31248);
//     color.set_TIMSK(1);
// }

// int guessnum = 0;
// int factor = 1;

// void setup() {
//     Serial.begin(9600);
//     noInterrupts();
//     pin_init(red);
//     pin_init(blue);
//     pin_init(green);
//     pin_init(yellow);
//     interrupts();
// }

// int code = random(1000, 10000);
// String stringCode = String(code);
// char temp;

// void loop() {
//     while(Serial.available()) {
//         factor += 5;
//         String in = Serial.readString();
//         in.trim();
        
//         Serial.println(stringCode);
//         Serial.println(in);
//         Serial.println();
        
//         for (int i = 0; i < 4; i++) {
//             if (in[i] == stringCode[i]) {
//                 pins[i].set_TIMSK(0);
//             } else {
//                 pins[i].factor_OCR(factor);
//             }
//         }
        
//         guessnum += 1;
        
//         if (guessnum == 5) {
//             for (int i = 0; i < 4; i++) {
//                 pins[i].set_TIMSK(0);
//             }
//             PORTB |= (11 << 5);
//             PORTB |= (10 << 5);
//             PORTB |= (9 << 5);
//             PORTB |= (8 << 5);
//         }
//     }
// }

// ISR(TIMER3_COMPA_vect) {
//     digitalWrite(11, !digitalRead(11));
// }

// ISR(TIMER4_COMPA_vect) {
//     digitalWrite(10, !digitalRead(10));
// }

// ISR(TIMER1_COMPA_vect) {
//     digitalWrite(9, !digitalRead(9));
// }

// ISR(TIMER5_COMPA_vect) {
//     digitalWrite(8, !digitalRead(8));
// }
