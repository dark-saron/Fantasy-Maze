#include <cstdlib>
#include <ctime>
#include <assert.h>

#include "Random.h"

void CRandom::Seed(int seed)
{
    if (seed == 0)
    {
        time_t t = time(0);
        srand((unsigned int) t);
    }
    else
    {
        srand(seed);
    }
}

//return of a random int number between the set max and 0
int CRandom::RandRange(int stop)
{
    return CRandom::RandRange(0, stop);
}

//return of a random int number between the set max and set min
int CRandom::RandRange(int start, int stop, int step)
{
    return start + (rand() % ((stop - start) / step))* step;
}

// Return a random integer N such that a <= N <= b.
int CRandom::RandInt(int a, int b)
{
    return CRandom::RandRange(a - 1, b + 1);
}