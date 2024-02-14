#include <RoveHBridge.h>
#include <cmath>

#define FWD_PWM   23
#define RVS_PWM   22
//#define FTIR_PIN  25
#define BUTTON    41

// Define H bridge params
int16_t offset1 = -10;
int16_t offset2 = 10;
uint32_t PWM = 750000000;

RoveHBridge motor1(FWD_PWM, RVS_PWM);

void setup() {
  Serial.begin();
  delay(1000);
  Serial.println("Testing effect of vibrations from the VCA");
}

void loop() {
  uint32_t now = millis();
  int16_t decipercent = std::sin((double)now * 0.001);
  if(digitalRead(BUTTON) == HIGH) {
    Motor1.drive(decipercent);
  }
}