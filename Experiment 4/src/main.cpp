#include <Arduino.h>

int BUTTON_PIN=2; // Pin button is connected to
int press_count=0; // Initialize counter
void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(BUTTON_PIN,INPUT); // Set button pin to input
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button_state,CHANGE);  
}

void loop() {
  
}

void button_state(){
  if(digitalRead(BUTTON_PIN)==HIGH)
  {
    press_count=press_count+1;
    Serial.println(String("Button Pressed "+String(press_count)+" Times"));
  }
}
