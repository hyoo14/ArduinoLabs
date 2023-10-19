
#include <Arduino.h>
//old but might be useful for Lab3

//int user;
//int user_arr[4];
//int pass[4];

//flag to be used after all attempts are used
int error = 0;

//intialize userInput
int userInput;

//pins the LEDs are plugged in 
const int led0_pin = 8;
const int led1_pin = 9;
const int led2_pin = 10;
const int led3_pin = 11;

//ints used to toggle LEDs on and off
int tog0, tog1, tog2, tog3, password;
int p_oneths, p_tenths, p_hundredths, p_thousandths;
void setup() {
  //begins serial monitor
  Serial.begin(9600);

//generates random number between 1000-9999
  randomSeed(analogRead(0));
  //password = random(1000,9999);
  password = 2431;//9132;
  Serial.print("password: ");
  Serial.println(password);
  
//splits the random password into individual digits
p_oneths  = (password / 1U) % 10;
p_tenths  = (password / 10U) % 10;
p_hundredths  = (password / 100U) % 10;
p_thousandths = (password / 1000U) % 10;
   
  //intializes pins to be used for output
  pinMode(led0_pin, OUTPUT);
  digitalWrite(led0_pin, LOW);
  
  pinMode(led1_pin, OUTPUT);
  digitalWrite(led1_pin, LOW);

  pinMode(led2_pin, OUTPUT);
  digitalWrite(led2_pin, LOW);

  pinMode(led3_pin, OUTPUT);
  digitalWrite(led3_pin, LOW);


  noInterrupts(); 
  //Timer 1 init to 1Hz
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624; 
  TCCR1B |= (1 << WGM12); 
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10); 
  TIMSK1 |= (1 << OCIE1A); 

  //Timer 2 init to 1Hz
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5 = 0;
  OCR5A = 15624;
  TCCR5B |= (1 << WGM52);
  TCCR5B |= (1 << CS52) | (0 << CS51) | (1 << CS50);
  TIMSK5 |= (1 << OCIE5A);
  
  //Timer 3 init to 1Hz
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;
  OCR3A = 15624;
  TCCR3B |= (1 << WGM32); 
  TCCR3B |= (1 << CS32) | (0 << CS31) | (1 << CS30);
  TIMSK3 |= (1 << OCIE3A); 

  //Timer 4 init to 1Hz
  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4 = 0;
  OCR4A = 15624;
  TCCR4B |= (1 << WGM42); 
  TCCR4B |= (1 << CS42) | (0 << CS41) | (1 << CS40);
  TIMSK4 |= (1 << OCIE4A); 

  interrupts(); 
}

int attempt = 3;

void loop() {
    while (attempt > 0 && Serial.available()) {
        Serial.print("in the while loop, remaining attempt: ");
        Serial.println(attempt);   

        String inputStr = Serial.readStringUntil('\n');
        int userInput = inputStr.toInt();

        int d_oneths = (userInput / 1U) % 10; 
        int d_tenths = (userInput / 10U) % 10;
        int d_hundredths= (userInput / 100U) % 10; 
        int d_thousands = (userInput / 1000U) % 10; 
//Used for trooble shooting: displays the user input as individual digits
        Serial.print("u_oneths");Serial.println(d_oneths);
        Serial.print("u_Tenths");Serial.println(d_tenths);
        Serial.print("u_Hundredths");Serial.println(d_hundredths);
        Serial.print("u_thousondths");Serial.println(d_thousands);
        

//used for trooble shooting: displays the password as indivdual digits
       Serial.print("p_oneths=");Serial.println(p_oneths);
        Serial.print("p_tenths=");Serial.println(p_tenths);
        Serial.print("p_hundredths=");Serial.println(p_hundredths);
        Serial.print("p_thousandths=");Serial.println(p_thousandths);
        

        Serial.println(userInput);
        attempt-=1;

         //determins what digits of users attempt was correct and displays what digit
            if (d_oneths == p_oneths){ 
            tog0 = 1;
            Serial.println("oneths correct");
            }

            if (d_tenths == p_tenths) {
            tog1 = 1;
            Serial.println("tenths correct");
            }

            if (d_hundredths == p_hundredths){
            tog2 = 1;
            Serial.println("Hundredths correct");
            }

            if (d_thousands == p_thousandths){ 
            tog3 = 1;
            Serial.println("thousandths correct");
            }

        //displays amount off attempts remaining
        Serial.print("REMAINING attempt: ");
        Serial.println(attempt);

        // used to tell user when entire password was correct 
        if((d_oneths == p_oneths) && (d_tenths == p_tenths) && (d_hundredths == p_hundredths) && (d_thousands == p_thousandths)){
        Serial.print("Password Correct"); Serial.println(password);
        
        attempt =0;
        }
    
        //displays when user did not guess correct pin after 3 attempts
        if ((attempt == 0) && (d_oneths != p_oneths) && (d_tenths != p_tenths) && (d_hundredths != p_hundredths) && (d_thousands != p_thousandths)){
            error = 1;
            tog0 = 0;
            tog1 = 0;
            tog2 = 0;
            tog3 = 0;
            Serial.print("ERROR: No attempt left\n");
            Serial.print("Password was:");
            Serial.println(password);
        }
        else {
//sets flashing for 2nd attempt
            if (attempt == 2) {
                if (d_oneths != p_oneths) {
                    OCR1A = 3124;
                    tog0 = 0;
                }
                if (d_oneths != p_tenths) {
                    OCR5A = 3124;
                    tog1 = 0;
                }
                if (d_hundredths != p_hundredths){
                  OCR3A = 3124;
                  tog2 = 0;
                }
                
                if (d_thousands != p_thousandths) {
                    OCR4A = 3124;
                    tog3 = 0;
                }

        //sets flashing for 1st attempt
                if (attempt == 1) {
              
                }      if (d_oneths != p_oneths) {
                    OCR1A = 624;
                    tog0 = 0;
                }
                if (d_tenths != p_tenths) {
                    OCR5A = 624;
                    tog1 = 0;
                }
                if (d_hundredths != p_hundredths){
                  OCR3A = 624;
                  tog2 = 0;
                }
               
                
                if (d_thousands  != p_thousandths) {
                    OCR4A = 624;
                    tog3 = 0;
                }

            }
        }
    }
    }

ISR(TIMER1_COMPA_vect) {
  if (tog0 == 1) digitalWrite(led0_pin, LOW);
  else if (tog0 == 0) {
    if (error) digitalWrite(led0_pin, HIGH);
    else digitalWrite(led0_pin, !digitalRead(led0_pin));
  }
}

ISR(TIMER3_COMPA_vect) {
  if (tog1 == 1) digitalWrite(led1_pin, LOW);
  else if (tog1 == 0) {
    if (error) digitalWrite(led1_pin, HIGH);
    else digitalWrite(led1_pin, !digitalRead(led1_pin));
  }
}
ISR(TIMER5_COMPA_vect) {
  if (tog2 == 1) digitalWrite(led2_pin, LOW);
  else if (tog2 == 0) {
    if (error) digitalWrite(led2_pin, HIGH);
    else digitalWrite(led2_pin, !digitalRead(led2_pin));
  }
}

ISR(TIMER4_COMPA_vect) {
  if (tog3 == 1) digitalWrite(led3_pin, LOW);
  else if (tog3 == 0) {
    if (error) digitalWrite(led3_pin, HIGH);
    else digitalWrite(led3_pin, !digitalRead(led3_pin));
  }
}

