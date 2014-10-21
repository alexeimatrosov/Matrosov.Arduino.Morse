#include "Switch.h"

#ifndef MorseController_h
#define MorseController_h

class MorseController
{
    private:
    	static const int Dot = 500;
    	static const int Dash = Dot*3;
    	static const int InterGap = Dot;
    	static const int ShortGap = Dot*3;
    	static const int MediumGap = Dot*7;
        static const char* Letters[];

        //unsigned long _lastLoopMillis;
        Switch _switch;
        char* _message;

    public:
        MorseController(int pin, char* message);
        void Setup();
        void Loop();
};

#endif