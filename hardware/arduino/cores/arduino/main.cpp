#include <Arduino.h>
#include "Serial.h"

#ifndef QT_ANDROID

int argc;
char **argv;

extern void setup(void);
extern void loop(void);

int main(int _argc, char **_argv)
{

    argc = _argc;
    argv = _argv;
    init();
    setup();
    
    for (;;) {
        loop();
        if (serialEventRun) serialEventRun();
    }
        
    return 0;
}

#endif

