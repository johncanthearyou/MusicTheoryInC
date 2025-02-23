#include <stdio.h>
#include "String.h"

char *chromaticScale[12] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
int diatonicMask[12] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};
char *modes[7] = {"Ionian", "Dorian", "Phrygian", "Lydian", "Mixolydian", "Aeolian", "Locrian"};

int getIndexForNote(char *note)
{
    return getIndexOfStringInArray(note, chromaticScale, 12);
}

int getIndexForMode(char *mode)
{
    return getIndexOfStringInArray(mode, modes, 7);
}

void sequenceToString(char **sequence, int length, char buffer[32])
{
    int sequenceIndex = 0;
    int bufferIndex = 0;
    buffer[bufferIndex++] = '[';
    while (sequenceIndex < length)
    {
        buffer[bufferIndex++] = *sequence[sequenceIndex];
        buffer[bufferIndex++] = ',';
        buffer[bufferIndex++] = ' ';
        sequenceIndex++;
    }
    buffer[bufferIndex - 2] = ']';
    buffer[bufferIndex - 1] = '\0';
}

int getNthOneInMask(int n, int mask[12])
{
    if (n < 0 || n > 6)
    {
        puts("n must be between 0 and 6, inclusive");
        return -1;
    }

    int oneCounter = -1;
    for (int i = 0; i < 12; i++)
    {
        if (mask[i])
        {
            oneCounter++;
            if (oneCounter == n)
            {
                return i;
            }
        }
    }

    return -1;
}

void buildScale(char key[5], char mode[10], char *scaleToLoad[7])
{
    int keyIndex = getIndexForNote(key);
    int modeOffset = getNthOneInMask(getIndexForMode(mode), diatonicMask);

    int scaleIndex = 0;
    for (int i = 0; i < 12 && scaleIndex < 7; i++)
    {
        if (diatonicMask[(i + modeOffset) % 12])
        {
            scaleToLoad[scaleIndex++] = chromaticScale[(keyIndex + i) % 12];
        }
    }
}

void buildChord(int chordSelection, char *scale[7], char *chordToLoad[3])
{
    for (int i = 0; i < 3; i++)
    {
        chordToLoad[i] = scale[(chordSelection + 2 * i - 1) % 7];
    }
}