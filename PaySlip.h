#ifndef PAYSLIP_H
#define PAYSLIP_H

#include <string>
#include <vector>

#include "Adjustment.h"

using namespace std;

class PaySlip {
 private:
  vector<Adjustment *> adjustment_ptrs;
  int employee_id;
  float gross_pay, net_pay;

 public:
  PaySlip();
  PaySlip(int employee_id, int gross_pay);

  void addAdjustment(Adjustment *adjustment);
  void removeLastAdjustment();

  float getGrossPay();
  float getNetPay();

  void setGrossPay(float gross_pay);
  void setNetPay(float gross_pay);

  void generateSlip();
};

#endif