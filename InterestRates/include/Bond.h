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

    CoxIngersollRossModel model;
    double bondPrice;
    double r0 = 0.1;
    double r;
    double dt = 0.001;
    double a = 0.20;
    double b = 0.05;
    double sigma = 0.03;
    double dr;
    double integral_r_dt;
    int M = 20;
    int seed = 0;
    double maturity = 10;
};


