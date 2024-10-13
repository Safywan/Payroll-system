#ifndef TAXES_H
#define TAXES_H

#include "Adjustment.h"

class Taxes : public Adjustment {
public:
    Taxes(float rate);
    float calculateAdjustement(float income);  // Override to calculate tax based on income
};

#endif
