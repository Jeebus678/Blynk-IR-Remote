#ifndef hex_h
#define hex_h

#include <Arduino.h>
#include <String.h>

#define HEXBIT_SIZE 16

char hexbits[HEXBIT_SIZE];
uint8_t binBase = 2;
uint8_t hexBase = 16;
uint8_t bitPosition = 0;
uint8_t accumulator = 0;
uint8_t hexbitPosition;
uint8_t hexbitLength = 0; 

char hexTable[16][2] = {
    {0, '0'},
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
    {10, 'A'},
    {11, 'B'},
    {12, 'C'},
    {13, 'D'},
    {14, 'E'},
    {15, 'F'}};

void clearHexbits()
{
    for (int iterator = 0; iterator < HEXBIT_SIZE; iterator++)
    {
        hexbits[iterator] = '\0';
    }
}

String hexToReadable(char *inputArray)
{
    return String(inputArray);
}

void binToHex(int binaryArray[], int binBits)
{
    // hexbits[HEXBIT_SIZE - (binBits / 4) - 1]
    hexbitPosition = 0;
    bitPosition = 0; 
    accumulator = 0; 
    hexbitLength = 0; 
    while (bitPosition < binBits)
    {
        if (binaryArray[bitPosition] == 1)
        {
            accumulator += 8;
        }
        if (binaryArray[bitPosition + 1] == 1)
        {
            accumulator += 4;
        }
        if (binaryArray[bitPosition + 2] == 1)
        {
            accumulator += 2;
        }
        if (binaryArray[bitPosition + 3] == 1)
        {
            accumulator += 1;
        }
        hexbits[hexbitPosition] = hexTable[accumulator][1];
        bitPosition += 4;
        accumulator = 0;
        hexbitPosition++;
        hexbitLength++;
        yield();
    }
}

#endif