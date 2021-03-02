#include "counter.h"

static int counter = 0;

void incrementa(void)
{
    counter++;
}

void decrementa(void)
{
    counter--;
}

int stato(void)
{
    return counter;
}
