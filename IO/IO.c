#include <stdio.h>
#include "Scale.h"
#include "String.h"

int makeUserSelectKey()
{
    char key[5];
    int keyIndex = -1;
    while (keyIndex == -1)
    {
        printf("Select the key by entering any of the 12 chromatic notes\n> ");
        scanf("%s", key);
        if (stringCompare(key, "exit"))
        {
            return -1;
        }
        keyIndex = getIndexForNote(key);
    }

    printf("Selected Key of %s (Chromatic Note #%d)\n", chromaticScale[keyIndex], keyIndex + 1);
    return keyIndex;
}

int makeUserSelectScale()
{
    char scaleType[20];
    while (1)
    {
        printf("Select the desired scale type (diatonic, harmonicMajor, harmonicMinor, doubleHarmonicMajor, doubleHarmonicMinor)\n> ");
        scanf("%s", scaleType);
        if (stringCompare(scaleType, "exit"))
            return -1;
        else if (stringCompare(scaleType, "diatonic"))
            return diatonicMask;
        else if (stringCompare(scaleType, "harmonicMajor"))
            return harmonicMajorMask;
        else if (stringCompare(scaleType, "harmonicMinor"))
            return harmonicMinorMask;
        else if (stringCompare(scaleType, "doubleHarmonicMajor"))
            return doubleHarmonicMajorMask;
        else if (stringCompare(scaleType, "doubleHarmonicMinor"))
            return doubleHarmonicMinorMask;
    }

    return -1;
}

int makeUserSelectMode()
{
    int mode;
    while (1)
    {
        printf("Select the desired mode (1-7)\n> ");
        scanf("%d", &mode);
        if (mode >= 1 || mode <= 7)
            return mode;
    }

    return mode;
}