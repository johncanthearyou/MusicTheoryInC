#include <stdio.h>
#include <stdlib.h>
#include "Chord.h"
#include "Scale.h"
#include "String.h"
#include "UserInput.h"

static char key[5];
static char mode[10] = "Ionian";
static char *scale[7];
static char *chord[3];
static char buffer[32];

int main()
{
	loadKeyFromUser(key);
	loadModeFromUser(mode);

	buildScale(key, mode, scale);
	sequenceToString(scale, 7, buffer);
	printf("%s %s: %s\n\n", key, mode, &buffer);

	while (1)
	{
		loadChordFromUser(scale, chord);
		sequenceToString(chord, 3, buffer);
		printf("%s %s: %s\n\n", chord[0], getChordQuality(chord), buffer);
	}

	return 0;
}