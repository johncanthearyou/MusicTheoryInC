#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "IO.h"
#include "Scale.h"

int main()
{
	// Prompt user for a key
	char *key = (char *)malloc(5 * sizeof(char));
	int keyIndex = makeUserSelectKey(key);
	if (keyIndex == -1)
	{
		free(key);
		return 0;
	}
	printf("Selected %s Major (chromatic note #%d)\n", key, getIndexForNote(key) + 1);

	// Build scale instance from key, scale, and mode selection
	char *scale[7];
	int scaleIndex = 0;
	for (int i = 0; i < 12; i++)
	{
		if (diatonicMask[i % 12])
		{
			scale[scaleIndex++] = chromaticScale[(keyIndex + i) % 12];
		}
	}
	printScale(scale);

	// for (int i = 0; i < 7; i++)
	// {
	// 	char *chord[3] = { major[i], major[(i+2)%7], major[(i+4)%7] };
	// 	printf("%s %s %s\n", chord[0], chord[1], chord[2]);
	// }

	free(key);
	return 0;
}