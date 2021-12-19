#ifndef _AIRWELL_H_
#define _AIRWELL_H_

#include <Arduino.h>

#define AIRWELL_SIZE = 36; 

int airwell[AIRWELL_SIZE] = {
    0, 0, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 1, 0
};

// 0 = auto
// 1 = min
// 2 = med
// 3 = high
void setAirwellFan(int speed)
{
    switch (speed)
    {
    case (0):
        airwell[6] = 0;
        airwell[7] = 0;
    case (1):
        airwell[6] = 0;
        airwell[7] = 1;
    case (2):
        airwell[6] = 1;
        airwell[7] = 0;
    case (3):
        airwell[6] = 1;
        airwell[7] = 1;
    }
}

// 0 = cool
// 1 = dry
// 2 = auto
// 3 = heat
// 4 = fan
void setAirwellMode(int mode)
{
    switch (mode)
    {
    case (0):
        airwell[3] = 0;
        airwell[4] = 0;
        airwell[5] = 1;
    case (1):
        airwell[3] = 1;
        airwell[4] = 0;
        airwell[5] = 0;
    case (2):
        airwell[3] = 0;
        airwell[4] = 1;
        airwell[5] = 1;
    case (3):
        airwell[3] = 0;
        airwell[4] = 1;
        airwell[5] = 0;
    case (4):
        airwell[3] = 1;
        airwell[4] = 0;
        airwell[5] = 1;
    }
}


void setAirwellTemperature(int temp)
{
    int addBits = temp - 16;
    int bitPosition; // Last bit of segment
    for (int iterator = 0; iterator < addBits; iterator++)
    {
        bitPosition = 16;
        airwell[bitPosition]++;
        while (airwell[bitPosition] > 1)
        {
            airwell[bitPosition] = 0;
            airwell[bitPosition--]++;
            bitPosition--; 
        }
    }
}

void setAirwellPower(bool status)
{
    if (status)
    {
        airwell[2] = 1;
    }
    else
        airwell[2] = 0;
}


void setAirwellState(bool status, int temp, int mode, int fan)
{
    setAirwellPower(status);
    setAirwellTemperature(temp);
    setAirwellFan(fan);
    setAirwellMode(mode);
    // for (int i = 0; i < COOLIX_SIZE; i++)
    // {
    //     Serial.print(coolix[i]);
    // }
    // Serial.println("");
}

#endif