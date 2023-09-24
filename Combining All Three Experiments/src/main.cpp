#include <Arduino.h>
#include "Morse.h"

// put function declarations here:
// int myFunction(int, int);
int pin = 8; //Pin LED is attached to 
char temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

Morse morse(pin);

int blinkMorse();
int turnLED(int);

// void loop() {
//   // put your main code here, to run repeatedly:
//   while (Serial.available() > 0){
//     int received = Serial.parseInt();
//     while (Serial.available()>0){
//       temp = Serial.read();  
//     }
//     analogWrite(pin, received);
//     String sm = "Received Input: " + String(received);
//     Serial.println(sm);
//   }
// }

// void loop() {
//     if (Serial.available()) {
//         String command = Serial.readStringUntil('\n');
//         command.trim();
//         if (command == "blink") {
//             blinkMorse();
//         } else if (command == "turn") {
//             turnLED();
//         }
//     }
// }

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();

        if (command == "blink") {
            blinkMorse();
        } else if (command.startsWith("turn")) {
            int spaceIndex = command.indexOf(' ');
            if(spaceIndex != -1) {
                String valueStr = command.substring(spaceIndex + 1);
                int value = valueStr.toInt();
                turnLED(value);
            }
        }
    }
}

int blinkMorse() {
    morse.dot(); morse.dot(); morse.dot();
    morse.dash(); morse.dash(); morse.dash();
    morse.dot(); morse.dot(); morse.dot();
    delay(2000);

    return 1;
}

int turnLED(int value) {
    analogWrite(pin, value);
    String sm = "Received Input: " + String(value);
    Serial.println(sm);
    delay(2000);

    return 1;
}
// void turnLED() {
//     while (Serial.available() > 0) {
//         int received = Serial.parseInt();
//         while (Serial.available() > 0) {
//             temp = Serial.read();
//         }
//         analogWrite(pin, received);
//         String sm = "Received Input: " + String(received);
//         Serial.println(sm);
//     }
    
// }
