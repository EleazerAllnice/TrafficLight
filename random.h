#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <iostream>
#include <random>

class Random{

    static std::mt19937 rng;
public:
    Random(int seedNumber);
    static double getRandomDouble(double low, double high);
};

#endif
