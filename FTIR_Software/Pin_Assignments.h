#ifndef PIN_ASSIGNMENTS_H
#define PIN_ASSIGNMENTS_H


const int LD_CTRL = 13; // enable photodiodes
const int PD_1 = 22; // IR detector
const int PD_2 = 23; // visible detector

const int LAMP_CTRL = 14; // turn on IR source

///// stepper motor (unused) /////

const int BUCK_EN = 33; // enable buck converter on motor
const int M_STEP = 37;
const int M_CLK = 36;
const int M_DIR = 38;

// unused motor

const int MS1_CTRL = 31;
const int MS2_CTRL = 30;
const int UART = 34; // optional UART for motor
////////////////////////

#endif // pin assignments