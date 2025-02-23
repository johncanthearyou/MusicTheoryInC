#include <stdio.h>

char getLowercaseChar(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
}

char getUppercaseChar(char ch)
{
    return (ch >= 'a' && ch <= 'z') ? ch - 32 : ch;
}

int stringEqualsignoreCase(char *string1, char *string2)
{
    if (!string1 || !string2)
        return 0;

    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0')
    {
        if (getLowercaseChar(string1[i]) != getLowercaseChar(string2[i]))
            return 0;
        i++;
    }
    if (string1[i] != '\0' || string2[i] != '\0')
        return 0;

    return 1;
}

int getIndexOfStringInArray(char *string, char **array, int arrayLength)
{
    if (!string || !array)
        return -1;

    // For every note in the chromatic scale
    for (int i = 0; i < arrayLength; i++)
    {
        if (stringEqualsignoreCase(array[i], string))
            return i;
    }

    return -1;
}