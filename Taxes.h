#ifndef TAXES_H
#define TAXES_H

#include "Adjustment.h"

class Taxes : public Adjustment {
public:
    Taxes(float rate);
    virtual float calculateAdjustement(float income) override;  // Override to calculate tax based on income
};

#endif
