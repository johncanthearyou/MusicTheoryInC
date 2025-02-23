#include <stdlib.h>
#include <stdio.h>
#include "Chord.h"
#include "Scale.h"
#include "String.h"
#include "LogicFlow.h"

void loadKeyFromUser(char keyToLoad[5])
{
    do
    {
        printf("Please select a key\nOptions are [C, C#/Db, D, D#/Eb, E, F, F#/Gb, G, G#/Ab, A, A#/Bb, B, exit]\n> ");
        scanf("%5s", keyToLoad);
        handleExit(keyToLoad);
    } while (getIndexForNote(keyToLoad) == -1);
}

void loadModeFromUser(char modeToLoad[10])
{
    do
    {
        printf("Please select a mode\nOptions are [Ionian, Dorian, Phrygian, Lydian, Mixolydian, Aeolian, Locrian, exit]\n> ");
        scanf("%10s", modeToLoad);
        handleExit(modeToLoad);
    } while (getIndexOfStringInArray(modeToLoad, modes, 7) == -1);
}

void loadChordFromUser(char *scale[7], char *chordToLoad[3])
{
    int chordSelection;
    do
    {
        char userInput[5];
        printf("Please select a chord\nOptions are [1, 2, 3, 4, 5, 6, 7, exit]\n> ");
        scanf("%5s", &userInput);
        handleExit(userInput);
        chordSelection = atoi(userInput);
    } while (chordSelection < 1 || chordSelection > 7);

    buildChord(chordSelection, scale, chordToLoad);
}