#include <Arduino.h>

int user;
int user_arr[4];
int pass[4];

int attempt=3;
int error =0;

int led0=11;
int led1=10;
int led2=9;
int led3=8;

int tog0, tog1, tog2, tog3, num;

void setup(){
  
  Serial.begin(9600);

  randomSeed(analogRead(0));
  num = random(9999);
  Serial.println(num);
  pass[3] = num % 10;  num /= 10;
  pass[2] = num % 10;  num /= 10;
  pass[1] = num % 10;  num /= 10;
  pass[0] = num % 10;  

  // Set pin to only outupt and low
  pinMode(led0,OUTPUT); pinMode(led1,OUTPUT); pinMode(led2,OUTPUT); pinMode(led3, OUTPUT);
  digitalWrite(led0, LOW); digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);

  noInterrupts(); //disable all interrupts

  //Timer 1 init to 1Hz
  TCCR1A=0;
  TCCR1B=0;
  TCNT1=0;
  OCR1A = 15624; // OCR3A = 16M / (1Hz * 1024) -1 ;
  TCCR1B |= (1<<WGM12); //WGM4
  TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10); //prescalar value = 1024;
  TIMSK1 |= (1<<OCIE1A); // enable overflow flag

  //Timer 3 init to 1Hz
  TCCR3A=0;
  TCCR3B=0;
  TCNT3=0;
  OCR3A = 15624; // OCR3A = 16M / (1Hz * 1024) -1 ;
  TCCR3B |= (1<<WGM32); //WGM4
  TCCR3B |= (1<<CS32) | (0<<CS31) | (1<<CS30); //prescalar value = 1024;
  TIMSK3 |= (1<<OCIE3A); // enable overflow flag

  //Timer 4 init to 1Hz
  TCCR4A=0;
  TCCR4B=0;
  TCNT4=0;
  OCR4A = 15624; // OCR3A = 16M / (1Hz * 1024) -1 ;
  TCCR4B |= (1<<WGM42); //WGM4
  TCCR4B |= (1<<CS42) | (0<<CS41) | (1<<CS40); //prescalar value = 1024;
  TIMSK4 |= (1<<OCIE4A); // enable overflow flag

  //Timer 5 init to 1Hz
  TCCR5A=0;
  TCCR5B=0;
  TCNT5=0;
  OCR5A = 15624; // OCR3A = 16M / (1Hz * 1024) -1 ;
  TCCR5B |= (1<<WGM52); //WGM4
  TCCR5B |= (1<<CS52) | (0<<CS51) | (1<<CS50); //prescalar value = 1024;
  TIMSK5 |= (1<<OCIE5A); // enable overflow flag

  interrupts(); //enable all interrupts



}
void loop(){
  if (Serial.available()>0){
    //parse input
    user = Serial.parseInt();
    for (int j=3; j>=0; j--){
      user_arr[j] = user % 10;
      user /= 10;
      Serial.println(user_arr[j]);
    }
    attempt -= 1;

    if( (user_arr[0] == pass[0])  && (user_arr[1] == pass[1]) && (user_arr[2] == pass[2]) && (user_arr[3] == pass[3])   ){
      tog0 = 1;
      tog1 = 1;
      tog2 = 1;
      tog3 = 1;
      Serial.print("UNLOCKED\n");
    }

    //check for attempts left
    if (attempt == 0){
      //if any key is wrong, all led on
      if( (user_arr[0] != pass[0])  || (user_arr[1] != pass[1]) || (user_arr[2] != pass[2]) || (user_arr[3] != pass[3])   ){
        error = 1234;
        tog0=0;
        tog1=0;
        tog2=0;
        tog3=0;
        Serial.print("ERROR: No attempt left\n");
      }
    }
    if (attempt !=0){
      Serial.print("REMAINING attempt: ");
      Serial.print(attempt);
      //turn off led if correct
      if (user_arr[0] == pass[0]) tog0 = 1;
      if (user_arr[1] == pass[1]) tog1 = 1;
      if (user_arr[2] == pass[2]) tog2 = 1;
      if (user_arr[3] == pass[3]) tog3 = 1;

      // if not
      // increase to 5Hz and set tog =0
      if (attempt == 2){
        if (user_arr[0] != pass[0]){
          OCR1A = 3124;
          tog0=0;
        }
        if (user_arr[1] != pass[1]){
          OCR3A = 3124;
          tog1=0;
        }
        if (user_arr[2] != pass[2]){
          OCR4A = 3124;
          tog2=0;
        }
        if (user_arr[3] != pass[3]){
          OCR5A = 3124;
          tog3=0;
        }
      }

      // increase to 25Hz and set tog =0
      if (attempt == 2){
        if (user_arr[0] != pass[0]){
          OCR1A = 624;
          tog0=0;
        }
        if (user_arr[1] != pass[1]){
          OCR3A = 624;
          tog1=0;
        }
        if (user_arr[2] != pass[2]){
          OCR4A = 624;
          tog2=0;
        }
        if (user_arr[3] != pass[3]){
          OCR5A = 624;
          tog3=0;
        }
      }// attempt = 1

    }//attempt !=0
    

    
  }//Serial.available()
}

ISR(TIMER1_COMPA_vect) {
  if (tog0 == 1) digitalWrite(led0, LOW); //correct key
  if (tog0 == 0){
    if (error) digitalWrite(led0, HIGH);
    else digitalWrite(led0, !digitalRead(led0)); //blinks when wrong
  }
}

ISR(TIMER3_COMPA_vect) {
  if (tog1 == 1) digitalWrite(led1, LOW); //correct key
  if (tog1 == 0){
    if (error) digitalWrite(led1, HIGH);
    else digitalWrite(led1, !digitalRead(led1)); //blinks when wrong
  }
}
ISR(TIMER4_COMPA_vect) {
  if (tog2 == 1) digitalWrite(led2, LOW); //correct key
  if (tog2 == 0){
    if (error) digitalWrite(led2, HIGH);
    else digitalWrite(led2, !digitalRead(led2)); //blinks when wrong
  }
}
ISR(TIMER5_COMPA_vect) {
  if (tog3 == 1) digitalWrite(led3, LOW); //correct key
  if (tog3 == 0){
    if (error) digitalWrite(led3, HIGH);
    else digitalWrite(led3, !digitalRead(led3)); //blinks when wrong
  }
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
