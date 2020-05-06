#ifndef __RANDOM_CPP__
#define __RANDOM_CPP__

#include <iostream>
#include <random>
#include "random.h"

std::mt19937 Random::rng;
Random::Random(int seedNumber)
{
 rng.seed(seedNumber);
}
 double Random::getRandomDouble(double low, double high)
{
        std::uniform_real_distribution<double> uni(low, high);
        return uni(rng);
}

#endif
