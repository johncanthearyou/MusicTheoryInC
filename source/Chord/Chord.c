#include <stdio.h>
#include <stdlib.h>
#include "Scale.h"
#include "String.h"

char *getChordQuality(char *scale[3])
{
    int indices[3] = {getIndexForNote(scale[0]), getIndexForNote(scale[1]), getIndexForNote(scale[2])};
    if (indices[1] == (indices[0] + 3) % 12)
    {
        // 1st interval is a minor 3rd (3 semitones), must be minor or diminished
        if (indices[2] == (indices[1] + 3) % 12)
            return "diminished";
        else if (indices[2] == (indices[1] + 4) % 12)
            return "minor";
    }
    else if (indices[1] == (indices[0] + 4) % 12)
    {
        // 1st interval is a major 3rd (4 semitones), must be major or augmented
        if (indices[2] == (indices[1] + 3) % 12)
            return "major";
        else if (indices[2] == (indices[1] + 4) % 12)
            return "augmented";
    }

    // fallback
    return "unknown";
}