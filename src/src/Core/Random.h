#pragma once

class CRandom
{
public:
    static void Seed(int seed = 0);

    static int RandRange(int stop);

    static int RandRange(int start, int stop, int step = 1);

    int RandInt(int a, int b);
};
