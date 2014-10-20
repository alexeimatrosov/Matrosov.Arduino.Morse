#include "Arduino.h"
#include "MorseController.h"

const int MORSE_PIN = 5;
MorseController _controller(MORSE_PIN, "ab cde");

void setup()
{
    _controller.Setup();
}

void loop()
{
    _controller.Loop();
}
