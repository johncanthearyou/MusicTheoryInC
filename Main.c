#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "IO.h"
#include "Scale.h"

int main()
{
	// Prompt user for key
	int keyIndex = makeUserSelectKey();
	if (keyIndex == -1)
		return 0;
	// Prompt user for scale type
	int scaleMask = makeUserSelectScale();
	if (scaleMask == -1)
		return 0;
	// Prompt user for mode
	int mode = makeUserSelectMode();
	if (mode == -1)
		return 0;

	// Build scale instance from key, scale, and mode selection
	char *scale[7];
	loadScale(keyIndex, scaleMask, mode, scale);
	// printScale(scale);

	// for (int i = 0; i < 7; i++)
	// {
	// 	char *chord[3] = {scale[i], scale[(i + 2) % 7], scale[(i + 4) % 7]};C
	// 	printf("%s %s %s (TODO: quality)\n", chord[0], chord[1], chord[2]);
	// }

	return 0;
}