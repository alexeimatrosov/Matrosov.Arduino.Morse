#include "Switch.h"

#ifndef MorseController_h
#define MorseController_h

class MorseController
{
    private:
    	static const int Dot = 400;
    	static const int Dash = Dot*3;
    	static const int SendDelay = Dot;
    	static const int CharDelay = Dot*3;
    	static const int WordDelay = Dot*7;

        unsigned long _lastLoopMillis;
        Switch _switch;
        char* _message;

    public:
        MorseController(int pin, char* message);
        void Setup();
        void Loop();
};

#endif