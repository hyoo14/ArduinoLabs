#include <Arduino.h>

// put function declarations here:
//int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8,1);
  delay(1000);
  digitalWrite(8,0);
  delay(1000);
}

// put function definitions here:
//int myFunction(int x, int y) {
//  return x + y;
//}