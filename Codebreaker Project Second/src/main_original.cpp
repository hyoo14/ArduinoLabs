#include <Arduino.h>

int password;  // Variable to store the generated password
int led0 = 8;  // Pin number for the LED
int tog0;      // Variable to track LED status

void setup() {
  
  Serial.begin(9600); // Initialize serial communication at 9600 baud

  // Initialize the random seed and generate a password between 0 to 9
  randomSeed(analogRead(0));
  password = random(10);  
  Serial.print("password: ");
  Serial.println(password);  // Print generated password

  // Set up the LED pin and turn it off initially
  pinMode(led0, OUTPUT);
  digitalWrite(led0, LOW);

  noInterrupts();  // Disable all interrupts

  // Initialize Timer 1 for 1Hz
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;  // Calculation for 1Hz: OCR1A = 16M / (1Hz * 1024) - 1
  TCCR1B |= (1 << WGM12);  // Set WGM1 mode
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);  // Set prescaler to 1024
  TIMSK1 |= (1 << OCIE1A);  // Enable Timer1 compare interrupt

  interrupts();  // Enable all interrupts
}

int attempt = 3;  // Number of attempts for entering the password

void loop() {  
  
  // Continue to check for input while there are remaining attempts and serial data is available
  while(attempt > 0 && Serial.available()){
    Serial.print("in the while loop, remaining attempt: ");
    Serial.println(attempt);   
    
    String inputStr = Serial.readStringUntil('\n');  // Read user's input from serial
    int userInput = inputStr.toInt();  // Convert string input to integer
    
    Serial.println(userInput);   // Print user's input
    attempt--;  // Decrease the number of attempts

    // If user's input matches the password
    if (userInput == password) {
      Serial.println("in the Second if statement");
      tog0 = 1;  // Set LED status to indicate success
      Serial.println("UNLOCKED\n");
      attempt = 0;  // Reset attempts to exit loop
      break;
    }  
    
    Serial.print("REMAINING attempt: ");
    Serial.println(attempt);  // Print remaining attempts

    // Change Timer1 frequency and LED status based on remaining attempts
    if (attempt == 2) {
      OCR1A = 3124;
      tog0 = 0;
    }
    if (attempt == 1) {
      OCR1A = 624;
      tog0 = 0;
    }      
    if (attempt == 0) Serial.println("ERROR: No attempt left");  
  } 
} 

// Interrupt service routine for Timer1 compare match
ISR(TIMER1_COMPA_vect) {
  if (tog0 == 1) digitalWrite(led0, LOW);  // Turn off the LED if password is correct
  else digitalWrite(led0, !digitalRead(led0));  // Blink the LED if password is wrong
}
