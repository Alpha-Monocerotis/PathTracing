#include "RNG.h"
#include <ctime>
#include <stdlib.h>
#define N 999
RNG::RNG() {
    srand(time(NULL));
    offset = 1;
}

double RNG::getRandomFloat() {
    return rand() % (N + 1) / (float)(N + 1);
}