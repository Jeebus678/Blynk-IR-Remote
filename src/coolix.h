#ifndef _COOLIX_H_
#define _COOLIX_H_

#define COOLIX_SIZE 24

static int coolix[COOLIX_SIZE] = {
    1, 0, 1, 1,
    0, 0, 1, 0,
    1, 0, 0, 1,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0};


// 0 = auto
// 1 = min
// 2 = med
// 3 = high
void setCoolixFan(int speed)
{
    switch (speed)
    {
    case (0):
        coolix[8] = 1;
        coolix[9] = 0;
        coolix[10] = 1;
        break;
    case (1):
        coolix[8] = 1;
        coolix[9] = 0;
        coolix[10] = 0;
        break;
    case (2):
        coolix[8] = 0;
        coolix[9] = 1;
        coolix[10] = 0;
        break;
    case (3):
        coolix[8] = 0;
        coolix[9] = 0;
        coolix[10] = 1;
        break;
    }
}

void setCoolixTemperature(int temp)
{
    if (temp >= 25)
    {
        coolix[16] = 1;
    }
    else
    {
        coolix[16] = 0;
    }
    if ((temp >= 21) && (temp <= 26))
    {
        coolix[17] = 1;
    }
    else
    {
        coolix[17] = 0;
    }
    if (((19 <= temp) && (temp <= 22)) || (temp >= 29))
    {
        coolix[18] = 1;
    }
    else
    {
        coolix[18] = 0;
    }
    if (((temp - 18) % 4 == 0) || ((temp - 19) % 4 == 0) || (temp == 18) || (temp == 19))
    {
        coolix[19] = 1;
    }
    else
    {
        coolix[19] = 0;
    }
}

void setCoolixPower(bool status)
{
    if (status)
    {
        coolix[9] = 0; 
        coolix[13] = 1;
    }
    else
    {
        coolix[9] = 1;
        coolix[10] = 1;
        coolix[13] = 0;
        coolix[16] = 1;
        coolix[17] = 1; 
        coolix[18] = 1; 
    }
}

// 0 = cool
// 1 = dry
// 2 = auto
// 3 = heat
// 4 = fan
void setCoolixMode(int mode)
{
    switch (mode)
    {
    case (0):
        coolix[20] = 0;
        coolix[21] = 0;
        coolix[22] = 0;
        break;
    case (1):
        coolix[8] = 0;
        coolix[9] = 0;
        coolix[10] = 0;
        coolix[20] = 0;
        coolix[21] = 1;
        coolix[22] = 0;
        break;
    case (2):
        coolix[8] = 0;
        coolix[9] = 0;
        coolix[10] = 0;
        coolix[20] = 1;
        coolix[21] = 0;
        coolix[22] = 0;
        break;
    case (3):
        coolix[20] = 1;
        coolix[21] = 1;
        coolix[22] = 0;
        break;
    case (4):
        coolix[16] = 1;
        coolix[17] = 1;
        coolix[18] = 1;
        coolix[20] = 0;
        coolix[21] = 1;
        coolix[22] = 0;
        break;
    default:
        break;
    }
}

void setCoolixState(bool status, int temp, int mode, int fan)
{
    setCoolixPower(status);
    setCoolixTemperature(temp);
    setCoolixFan(fan);
    setCoolixMode(mode);
    // for (int i = 0; i < COOLIX_SIZE; i++)
    // {
    //     Serial.print(coolix[i]);
    // }
    // Serial.println("");
}

#endif