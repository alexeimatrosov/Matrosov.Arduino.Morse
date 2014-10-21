#include "Arduino.h"
#include "MorseController.h"

const int MORSE_PIN = 13;
const int DOT_PERIOD = 500;
MorseController _controller(MORSE_PIN, DOT_PERIOD, "SOS");

void setup()
{
    _controller.Setup();
}

void loop()
{
    _controller.Loop();
}
