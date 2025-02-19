// Fields
extern char *chromaticScale[12];
extern int diatonicMask;
extern int harmonicMajorMask;
extern int doubleHarmonicMajorMask;
extern int harmonicMinorMask;
extern int doubleHarmonicMinorMask;

// Methods
int getIndexForNote(char *note);
void loadScale(int keyIndex, int scaleMask, int modeOffset, char *scaleToLoad[7]);
void printScale(char *scale[7]);