#include <RoveHBridge.h>
#include <cmath>

#define FWD_PWM   23
#define RVS_PWM   22
//#define FTIR_PIN  25
#define BUTTON    41

// Define H bridge params
int16_t offset1 = -10;
int16_t offset2 = 10;
float PWM = 750000;

RoveHBridge motor1(FWD_PWM, RVS_PWM);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Testing effect of vibrations from the VCA");
  motor1.configFrequency(PWM);
}

int interval = 10000;
int minstren = 50, maxstren = 300;
int diffstren = maxstren - minstren;
int16_t notes[10] = {1000, 800, 600, 400, 200, 0, 200, 400, 600, 800};
int16_t squareWave(uint32_t t) {
  //return (t / 1000) % 2 == 0 ? 1000 : 500;
  uint8_t index = (t/interval) % 10;
  return notes[index];
}

int16_t triangleWave(uint32_t t) {
  uint32_t second = t / interval;
  double frac = t - second * interval;
  frac = frac / interval;
  int16_t ret = second % 2 == 0 ? (int16_t)(maxstren - frac * diffstren) : (int16_t)(frac * diffstren + minstren);
  return ret;
}

void loop() {
  uint32_t now = millis();
  int16_t decipercent = triangleWave(now);
  motor1.drive(decipercent);
  //Serial.println(decipercent);
}