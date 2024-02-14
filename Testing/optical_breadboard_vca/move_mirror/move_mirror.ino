#include <RoveHBridge.h>
#include <cmath>

#define FWD_PWM   23
#define RVS_PWM   22
//#define FTIR_PIN  25
#define BUTTON    41

// Define H bridge params
int16_t offset1 = -10;
int16_t offset2 = 10;
uint16_t PWM = 50000;

RoveHBridge motor1(FWD_PWM, RVS_PWM);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Testing effect of vibrations from the VCA");
  motor1.configFrequency(PWM);
}

int16_t notes[10] = {1000, 900, 800, 700, 600, 500, 600, 700, 800, 900};
int16_t squareWave(uint32_t t) {
  //return (t / 1000) % 2 == 0 ? 1000 : 500;
  uint8_t index = (t/250) % 10;
  return notes[index];
}

void loop() {
  uint32_t now = millis();
  int16_t decipercent = squareWave(now);
  motor1.drive(decipercent);
  //Serial.println(decipercent);
}