#ifndef ADJUSTMENT_H
#define ADJUSTMENT_H

class Adjustment
{
protected:  // Changed this from private to protected
    float rate;

public:
    Adjustment(float rate);
    virtual float calculateAdjustement(float income);
};

#endif
