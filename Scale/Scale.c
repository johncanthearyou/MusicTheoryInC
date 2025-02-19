#include <stdio.h>
#include "String.h"

char *chromaticScale[12] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
int diatonicMask = 0b101011010101;
int harmonicMajorMask = 0b101011011001;
int harmonicMinorMask = 0b101101011001;
int doubleHarmonicMajorMask = 0b110011011001;
int doubleHarmonicMinorMask = 0b101100111001;

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

void loadScale(int keyIndex, int scaleMask, int modeOffset, char *scaleToLoad[7])
{
    printf("keyIndex: %d\n", keyIndex);
    printf("scaleMask: %d\n", scaleMask);
    printf("modeOffset: %d\n", modeOffset);

    int scaleIndex = 0;
    for (int i = 0; i < 12; i++)
    {
        int foo = (scaleMask / (i + modeOffset)) % 2;
        printf("%d", foo);
    }
}

void printScale(char *scale[7])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%s ", scale[i]);
    }
    puts("");
}