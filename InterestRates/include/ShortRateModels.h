#pragma once

#include <cmath>


class ShortRateModel
{
public:
    virtual double dr(double r, double dt) = 0;
};


class VasicekModel : public ShortRateModel
{
public:
    double dr(double r, double dt) override
    {
        double delta_r = a * (b - r) * dt + sigma * ((rand() % 2) - 0.5) * sqrt(dt);
        return delta_r;
    }

    double a = 0.20;
    double b = 0.05;
    double sigma = 0.03;
};


class CoxIngersollRossModel : public ShortRateModel
{
public:
    double dr(double r, double dt) override
    {
        double delta_r = a * (b - r) * dt + sigma * sqrt(r) * ((rand() % 2) - 0.5) * sqrt(dt);
        return delta_r;
    }

    double a = 0.20;
    double b = 0.05;
    double sigma = 0.03;
};
