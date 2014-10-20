#include "MorseController.h"

MorseController::MorseController(int pin, char* message)
    : _switch(pin)
{
    _message = message;
}

void MorseController::Setup()
{
    _lastLoopMillis = millis();
}

void MorseController::Loop()
{
    // unsigned long currentMillis = millis();

    // if ((currentMillis - _lastLoopMillis) > 400)
    // {
    //     _traffic->ShowInconclusive();
    // }
}