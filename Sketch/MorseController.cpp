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

const char* MorseController::Numbers[] = {
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
};

MorseController::MorseController(int pin, int dotPeriod, char* message)
    : _switch(pin)
{
    _dot = dotPeriod;
    _dash = _dot*3;
    _interGap = _dot;
    _shortGap = _dot*3;
    _mediumGap = _dot*7;
    _message = message;
}

void MorseController::Setup()
{
    // _previousLoopMillis = millis();
}

void MorseController::Loop()
{
	for (int i = 0; _message[i]; ++i)
	{
		const char* code = GetCharCode(_message[i]);

        if (code == NULL)
        {
            Off(_mediumGap);
            continue;
        }

		for (int j = 0; code[j]; ++j)
		{
			On(code[j] == '.' ? _dot : _dash);

			if (code[j+1] != '\0')
			{
				Off(_interGap);
			}
		}

		if (_message[i+1] != ' ' && _message[i+1] != '\0')
		{
			Off(_shortGap);
		}
	}

	Off(_mediumGap);

    // unsigned long currentMillis = millis();

    // if ((currentMillis - _previousLoopMillis) > 400)
    // {
    //     _traffic->ShowInconclusive();
    // }
}

const char* MorseController::GetCharCode(char c)
{
    if ('A' <= c && c <= 'Z')
    {
        return Letters[c - 'A'];
    }

    if ('a' <= c && c <= 'z')
    {
        return Letters[c - 'a'];
    }

    if ('0' <= c && c <= '9')
    {
        return Numbers[c - '0'];
    }

    return NULL;
}

void MorseController::On(int period)
{
    _switch.On();
    delay(period);
}

void MorseController::Off(int period)
{
    _switch.Off();
    delay(period);
}