#include "MorseController.h"

const char* MorseController::Letters[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
};

MorseController::MorseController(int pin, char* message)
    : _switch(pin)
{
    _message = message;
}

void MorseController::Setup()
{
    // _lastLoopMillis = millis();
}

void MorseController::Loop()
{
	for (int i = 0; _message[i]; ++i)
	{
		if (_message[i] == ' ')
		{
			_switch.Off();
			delay(MediumGap);
			continue;
		}

		int index = _message[i] - 'A';
		const char* code = Letters[index];

		for (int j = 0; code[j]; ++j)
		{
			_switch.On();
			delay(code[j] == '.' ? Dot : Dash);

			if (code[j+1] != '\0')
			{
				_switch.Off();
				delay(InterGap);
			}
		}

		if (_message[i+1] != ' ' && _message[i+1] != '\0')
		{
			_switch.Off();
			delay(ShortGap);
		}
	}

	_switch.Off();
	delay(MediumGap);

    // unsigned long currentMillis = millis();

    // if ((currentMillis - _lastLoopMillis) > 400)
    // {
    //     _traffic->ShowInconclusive();
    // }
}