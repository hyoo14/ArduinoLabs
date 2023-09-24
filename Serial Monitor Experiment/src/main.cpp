#include <Arduino.h>

// put function declarations here:
// int myFunction(int, int);
int pin = 8; //Pin LED is attached to 
char temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0){
    int received = Serial.parseInt();
    while (Serial.available()>0){
      temp = Serial.read();  
    }
    analogWrite(pin, received);
    String sm = "Received Input: " + String(received);
    Serial.println(sm);
  }
}
