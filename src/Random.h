#pragma once

class CRandom
{

public:
    
	int CRandom::RandInt(int a, int b);
	static int RandRange(int stop);
    static int RandRange(int start, int stop, int step = 1);
    static void Seed(int seed = 0);
    
};
