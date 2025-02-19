int stringCompare(char *string1, char *string2)
{
    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            return 0;
        }
        i++;
    }
    if (string1[i] == '\0' && string2[i] == '\0')
    {
        return 1;
    }

    return 0;
}