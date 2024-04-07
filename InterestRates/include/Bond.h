#pragma once

#include <iostream>
#include <cmath>
#include <random>
#include <future>
#include "ShortRateModels.h"


class Bond
{
public:
    Bond(double mat)
        : maturity(mat)
    {
    }

    double calcBondPrice();
    double calcYield();


private:
    double calcExponentialOfIntegral(int seed);
    std::future<double> calcExponentialOfIntegralAsync(int seed);

    CoxIngersollRossModel model;
    double bondPrice;
    double r0 = 0.1;
    double r;
    double dt = 0.001;
    double dr;
    double integral_r_dt;
    int M = 100'000;
    int seed = 0;
    double maturity = 10;
};


