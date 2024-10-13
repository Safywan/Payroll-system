#ifndef PAYSLIP_H
#define PAYSLIP_H

#include <vector>
#include <string>

#include "Adjustment.h"

using namespace std;

class PaySlip
{
private:
    vector<Adjustment> adjustments;
    int employeeID;
    float grossPay, netPay;

public:
    PaySlip();
    PaySlip(int employeeID, int grossPay);

    void addAdjustment(Adjustment adjustemnet);
    void removelastAdjustment();

    float getGrossPay();
    float getNetPay();

    void setGrossPay(float grossPay);
    void setNetPay(float grossPay);

    void generateSlip();
};

#endif