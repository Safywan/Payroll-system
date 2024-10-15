#ifndef PAYSLIP_H
#define PAYSLIP_H

#include <string>
#include <vector>

#include "Adjustment.h"

using namespace std;

class PaySlip {
 private:
  vector<Adjustment *> adjustment_ptrs;
  int employeeID;
  float grossPay, netPay;

 public:
  PaySlip();
  PaySlip(int employeeID, int grossPay);

  void addAdjustment(Adjustment *adjustment);
  void removeLastAdjustment();

  float getGrossPay();
  float getNetPay();

  void setGrossPay(float grossPay);
  void setNetPay(float grossPay);

  void generateSlip();
};

#endif