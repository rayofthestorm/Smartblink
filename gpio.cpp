#include "gpio.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handel = lgGpiochipOpen(CHIP); /* get a handle to the GPIO */

    int init_state = 0;
    for(int pin : LEDS) //Keine Klammer noetig
        lgGpioClaimOutput(m_handel, LFLAGS, pin, init_state);
}

Gpio::~Gpio()
{
    //switch leds off
    int state = 0;
    for(int pin : LEDS) //Keine Klammer noetig
        lgGpioWrite(m_handel, pin, state);
    lgGpiochipClose(m_handel);
}

void Gpio::set(int pin, int state)
{
    lgGpioWrite(m_handel, pin, state);
}


