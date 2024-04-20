#pragma once

#include <cmath>


class ShortRateModel
{
public:
    double dX(double dt) {
        int bernoulli_rv = rand() % 2;
        return (2 * bernoulli_rv - 1) * sqrt(dt);
    }

    virtual double dr(double r, double dt) = 0;
};


class VasicekModel : public ShortRateModel
{
public:
    double dr(double r, double dt) override
    {
        double delta_r = a * (b - r) * dt + sigma * dX(dt);
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
        double delta_r = a * (b - r) * dt + sigma * sqrt(r) * dX(dt);
        return delta_r;
    }

    double a = 0.20;
    double b = 0.05;
    double sigma = 0.03;
};
