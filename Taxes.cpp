#include "Taxes.h"

Taxes::Taxes(float rate) : Adjustment(rate) {}

float Taxes::calculateAdjustement(float income)
{
    // Example calculation: Flat tax rate
    // You can modify this to include tax brackets or other logic
    return income * rate; // Simply apply the tax rate to the income
}
