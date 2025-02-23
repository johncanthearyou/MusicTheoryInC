// Fields
extern char *chromaticScale[12];
extern int diatonicMask[12];
extern char *modes[7];

// Methods
int getIndexForNote(char *note);
int getIndexForMode(char *mode);
void sequenceToString(char **sequence, int length, char buffer[32]);
void buildScale(char key[5], char mode[10], char *scaleToLoad[7]);
void buildChord(int chordSelection, char *scale[7], char *chordToLoad[3]);