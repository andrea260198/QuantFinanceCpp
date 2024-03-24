#pragma once

#include <cmath>


class CoxIngersollRossModel
{
public:
    double dr(double r, double dt)
    {
        double delta_r = a * (b - r) * dt + sigma * sqrt(r) * ((rand() % 2) - 0.5) * sqrt(dt);
        return delta_r;
    }

    double a = 0.20;
    double b = 0.05;
    double sigma = 0.03;
};
