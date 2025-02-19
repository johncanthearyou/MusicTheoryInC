#include <stdio.h>
#include "String.h"
#include "Scale.h"

char *chromaticScale[12] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
int diatonicMask[12] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};
int harmonicMajorMask[12] = {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1};
int doubleHarmonicMajorMask[12] = {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1};
int harmonicMinorMask[12] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1};

int getIndexForNote(char *note)
{
    // For every note in the chromatic scale
    for (int i = 0; i < 12; i++)
    {
        if (stringCompare(chromaticScale[i], note))
        {
            return i;
        }
    }

    return -1;
}

void printScale(char *scale[7])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%s ", scale[i]);
    }
    puts("");
}