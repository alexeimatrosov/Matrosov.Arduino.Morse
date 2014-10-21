#include "Arduino.h"
#include "MorseController.h"

const int MORSE_PIN = 13;
MorseController _controller(MORSE_PIN, "AB");

void setup()
{
    _controller.Setup();
}

void loop()
{
    _controller.Loop();
}
