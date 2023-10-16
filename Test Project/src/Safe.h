#ifndef Safe_h
#define Safe_h

#include <Arduino.h>

class Safe{
    public:
        Safe();
        void compareCode(int *buf,String entry);
        char getChar(int i);
    private:
        char _passcode[5];
};

#endif