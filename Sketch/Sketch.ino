#include "Arduino.h"
#include "MorseController.h"

const int CONST_HIGH_PIN = 7;
const int MORSE_PIN = 13;
const int DOT_PERIOD = 400;
MorseController _controller(MORSE_PIN, DOT_PERIOD, "SOS");

void setup()
{
	pinMode(CONST_HIGH_PIN, OUTPUT);
	digitalWrite(CONST_HIGH_PIN, HIGH);
    _controller.Setup();
}

void loop()
{
    _controller.Loop();
}
