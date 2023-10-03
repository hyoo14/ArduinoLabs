#include <Arduino.h>


int turnLED(int);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    Serial.print(command);
    //turnLED(200);
    analogWrite(11, 200);
    delay(1000);
    analogWrite(11, 0);
  }

}


// int turnLED(int value) {
//     analogWrite(11, value);
//     String sm = "Received Input: " + String(value);
//     Serial.println(sm);
//     delay(2000);

//     return 1;
// }

