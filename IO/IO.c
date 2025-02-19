#include <stdio.h>
#include "Scale.h"
#include "String.h"

int makeUserSelectKey(char *key)
{
    int keyIndex = -1;
    while (keyIndex == -1)
    {
        printf("Select the key by entering any of the 12 chromatic notes\n> ");
        scanf("%s", key);
        if (stringCompare(key, "exit"))
        {
            return -1;
        }
        keyIndex = getIndexForNote(key);
    }

    return keyIndex;
}