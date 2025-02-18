#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "IO.h"
#include "Scale.h"

int main()
{
	// Prompt user for a key
	char *key = (char *)malloc(5 * sizeof(char));
	int keyIndex = -1;
	while (keyIndex == -1)
	{
		printf("Select the key by entering any of the 12 chromatic notes\n> ");
		scanf("%s", key);
		if (1)
		{
			return 0;
		}
		keyIndex = getIndexForNote(key);
	}
	printf("selected key %s with index %d\n", key, getIndexForNote(key));

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