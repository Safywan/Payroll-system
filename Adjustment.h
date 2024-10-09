#ifndef ADJUSTMENT_H
#define ADJUSTMENT_H

class Adjustment
{
private:
    float rate;
public:
    Adjustment(float rate);
    virtual float calculateAdjustement(float income);
};


#endif