﻿#include "include/Bond.h"


double Bond::calcBondPrice()
{
    double sum = 0;

    std::vector<std::future<double>> futures;

    for (int i = 0; i < M; i++)
    {
        seed++;
        futures.push_back(calcExponentialOfIntegralAsync(seed));
    }

    for (auto &future : futures)
    {
        sum += future.get();
    }

    double bondPrice = sum / M;
    return bondPrice;
}


double Bond::calcYield()
{
    return -log(calcBondPrice()) / maturity;
}


std::future<double> Bond::calcExponentialOfIntegralAsync(int seed)
{
    return std::async(
        std::launch::async, 
        &Bond::calcExponentialOfIntegral, 
        *this, 
        seed
    );
}


double Bond::calcExponentialOfIntegral(int seed)
{
    CoxIngersollRossModel model;
    srand(seed);
    r = r0;
    integral_r_dt = 0;

    for (double t = 0.0; t < maturity; t += dt)
    {
        dr = model.dr(r, dt);
        r += dr;

        integral_r_dt += r * dt;
    }

    return exp(-integral_r_dt);
}
