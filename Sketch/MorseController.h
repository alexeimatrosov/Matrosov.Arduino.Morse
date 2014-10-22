#include "Switch.h"

#ifndef MorseController_h
#define MorseController_h

class MorseController
{
    private:
        static const char* Letters[];
        static const char* Numbers[];

        Switch _switch;
        int _dot;
        int _dash;
        int _interGap;
        int _shortGap;
        int _mediumGap;
        char* _message;

    public:
        MorseController(int pin, int dorPeriod, char* message);
        void Setup();
        void Loop();

    private:
        const char* GetCharCode(char c);
        void On(int period);
        void Off(int period);
};

#endif