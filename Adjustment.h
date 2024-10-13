#ifndef ADJUSTMENT_H
#define ADJUSTMENT_H

//Adjustement is an abstract and fully virtual class that Superannuition and Taxes Inherit from
class Adjustment
{
protected:  
    float rate;

public:
    Adjustment(float rate);
    virtual float calculateAdjustement(float income);
};

#endif
