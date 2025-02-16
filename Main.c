#include <stdio.h>

char *key = "C";
int keyIndex = 0;
char *notes[12] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
int diatonicMask[12] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};
int harmonicMajorMask[12] = {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1};
int doubleHarmonicMajorMask[12] = {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1};
int harmonicMinorMask[12] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1};

int getIndexForNote(char *note)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; notes[j - 1] != "\0"; j++)
		{
			printf("notes[i][j]: %s\n", notes[i][j]);
			printf("note[j]: %s\n", note[j]);
			if (notes[i][j] != note[j])
			{
				break;
			}
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

int main()
{
	char *scale[7];
	int scaleIndex = 0;
	for (int i = 0; i < 12; i++)
	{
		if (harmonicMinorMask[i % 12])
		{
			scale[scaleIndex++] = notes[(keyIndex + i) % 12];
		}
	}
	printScale(scale);
	printf("%d\n", getIndexForNote("D#"));

	// for (int i = 0; i < 7; i++)
	// {
	// 	char *chord[3] = { major[i], major[(i+2)%7], major[(i+4)%7] };
	// 	printf("%s %s %s\n", chord[0], chord[1], chord[2]);
	// }

	return 0;
}