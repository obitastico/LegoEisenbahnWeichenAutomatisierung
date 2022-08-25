#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  110 
#define SERVOMAX  510 

uint8_t servonum = 0;

int switchPins[] = {13, 12, 11, 10};

int switchStates[4];

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < sizeof(switchPins); i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
  }
  
  pwm.begin();
  pwm.setPWMFreq(60); 
  Serial.println("Setup abgesclossen");
  delay(50);
}

void loop() {
  for (int i = 0; i < sizeof(switchStates); i++) {
    switchStates[i] = readState(switchPins[i]);
    pinMode(switchPins[i], INPUT_PULLUP);
  }

  if(switchStates[0] == 1){
    pwm.setPWM(0, 0, 403);
  } else {
    pwm.setPWM(0, 0, 338);
  }

  if(switchStates[1] == 1){
    pwm.setPWM(1, 0, 433);
  } else {
    pwm.setPWM(1, 0, 365);
  }

  if(switchStates[2] == 1){
    pwm.setPWM(2, 0, 332);
  } else {
    pwm.setPWM(2, 0, 410);
  }
  if(switchStates[2] == 1){
    pwm.setPWM(3, 0, 450);
  } else {
    pwm.setPWM(3, 0, 378);
  }
  


}

int readState(int pin) {
  return digitalRead(pin) == 1 ? 1 : 0;
}
