#include "Safe.h"

Safe::Safe() {
   // Serial.begin(9600);
    //randomSeed(analogRead(0));
    //password = random(100);
    //Serial.print("password: ");
    //Serial.println(password);
}

int Safe::getPassword() {
    return password;
}