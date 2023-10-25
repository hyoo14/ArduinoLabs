#include <Arduino.h>

// Pin assignments for the LED and the photoresistor
int ledPin = 6; 
int photoresistorPin = A0; 

// Variables used for PWM control and reading the photoresistor's value
float currentDutyCycle = 0.0; // Current duty cycle, ranging from 0 to 1
int photoResistorValue;  // Placeholder for future use if needed
int fixedResistorValue = 10000;  // Resistance value of the 10kΩ resistor used in voltage divider
float dutyCyclePercentage; 

void setup() {
  Serial.begin(9600); 
  Serial.println("Duty Cycle(%), Voltage across 10kΩ Resistor, Voltage across Photoresistor"); 

  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  pinMode(photoresistorPin, INPUT); // Set the photoresistor pin as an input
  
  // Timer configuration
  noInterrupts(); // Disable all interrupts for configuration
  TCCR4A = 0b10000010; 
  TCCR4B = 0b00010010; 
  TCNT4 = 0;  // Timer/Counter Register initialization
  OCR4A = 0; // Output Compare Register initialization
  ICR4 = 400; // Input Capture Register setup
  interrupts(); // Re-enable interrupts
}

void loop() {
  // Adjust the PWM signal's duty cycle
  if (currentDutyCycle > 1.01) {
    currentDutyCycle = 0.05;  // Reset duty cycle if it exceeds 1
  } 
  OCR4A = (ICR4 * currentDutyCycle);  // Set the duty cycle for the PWM signal
  dutyCyclePercentage = currentDutyCycle * 100;  // Convert duty cycle to percentage
  currentDutyCycle += 0.05;  // Increment duty cycle

  delay(2000); // Pause the loop for 2 seconds
  
  // Read the voltage across the photoresistor
  float voltageAcrossFixedResistor = analogRead(photoresistorPin) * (5.0 / 1023.0);  
  float currentThroughFixedResistor = (voltageAcrossFixedResistor / fixedResistorValue) * 1000000; 
  float voltageAcrossPhotoresistor = 5 - voltageAcrossFixedResistor; 
  float resistanceOfPhotoresistor = ((5 * fixedResistorValue) / voltageAcrossFixedResistor) - fixedResistorValue; 

  // Print the data to the serial monitor
  Serial.print(String(dutyCyclePercentage) + ", " + String(voltageAcrossFixedResistor) + ", " + String(voltageAcrossPhotoresistor) + "\n");
}



// #include <Arduino.h>

// // LED와 포토레지스터 연결 핀 설정
// int LED_R = 6; 
// int Vdiv_in = A0; 

// // PWM 제어 및 읽기에 사용되는 변수들
// float dcycle_f = 0.0; // 현재 duty cycle (0~1)
// int photoRead; 
// int RPR = 10000;  // 10k 저항 값
// float dcycle_percent; 

// void setup() {
//   Serial.begin(9600); 
//   Serial.println("Duty Cycle(%), Voltage across R-10k, Voltage across Photoresistor"); 

//   pinMode(LED_R, OUTPUT);  // LED 핀을 출력으로 설정
//   pinMode(Vdiv_in, INPUT); // 포토레지스터 핀을 입력으로 설정
  
//   // Timer 설정: 이 부분은 아두이노보드의 특정 타이머에 대한 설정입니다.
//   noInterrupts(); 
//   TCCR4A = 0b10000010; 
//   TCCR4B = 0b00010010; 
//   TCNT4 = 0; 
//   OCR4A = 0; 
//   ICR4 = 400; 
//   interrupts();
// }

// void loop() {
//   // PWM 신호의 duty cycle을 조절
//   if (dcycle_f > 1.01) {
//     dcycle_f = 0.05; 
//   } 
//   OCR4A = (ICR4 * dcycle_f); 
//   dcycle_percent = dcycle_f * 100; 
//   dcycle_f += 0.05;

//   delay(2000); // 2초 동안 대기
  
//   // 포토레지스터의 전압 읽기
//   float RPRvoltage = analogRead(Vdiv_in) * (5.0 / 1023.0); 
//   float RPRcurrent = ((RPRvoltage) / RPR) * 1000000; 
//   float photoVoltage = 5 - RPRvoltage; 
//   float photoRes = ((5 * RPR) / RPRvoltage) - RPR; 

//   // 시리얼 모니터에 데이터 출력
//   Serial.print(String(dcycle_percent) + ", " + String(RPRvoltage) + ", " + String(photoVoltage) + "\n");
// }


// #include <Arduino.h>

// int LED_R = 6; 
// int Vdiv_in = A0; 
// float dcycle_f = 0.0; 
// int photoRead; 
// int RPR = 10000; 
// float dcycle_percent; 

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600); 
//   Serial.println("Duty Cycle(%), Voltage across R-10k, Voltage across Photoresistor"); 

//   pinMode(LED_R, OUTPUT); 
//   pinMode(Vdiv_in, INPUT); 
//   noInterrupts(); 
//   TCCR4A = 0b10000010; 
//   TCCR4B = 0b00010010; //prescalar 8 
//   TCNT4 = 0; 
//   OCR4A = 0; 
//   ICR4 = 400; 
//   interrupts();

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if (dcycle_f > 1.01) {
//     dcycle_f = 0.05; 
//     OCR4A = (ICR4 * dcycle_f); 
//     dcycle_percent = dcycle_f * 100; 
//     dcycle_f = dcycle_f + 0.05; 
//   } 
//   else { 
//     OCR4A = (ICR4 * dcycle_f); 
//     dcycle_percent = dcycle_f * 100; 
//     dcycle_f = dcycle_f + 0.05; 
//   } 
//   // Serial.println("Delaying for 2 Seconds"); 
//   delay(2000); 
//   float RPRvoltage = analogRead(Vdiv_in) * (5.0 / 1023.0); 

//   float RPRcurrent = ((RPRvoltage) / RPR) * 1000000; 
//   float photoVoltage = 5 - RPRvoltage; 
//   float photoRes = ((5 * RPR) / RPRvoltage) - RPR; 
//   Serial.print(String(dcycle_percent) + ", " + String(R2voltage) + ", " + String(photoVoltage) + "\n");  

// }
