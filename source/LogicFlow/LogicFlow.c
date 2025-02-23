#include <stdlib.h>
#include "String.h"

void handleExit(char *input)
{
    if (stringEqualsignoreCase(input, "exit"))
        exit(0);
}