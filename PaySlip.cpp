#include "PaySlip.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

PaySlip::PaySlip() : PaySlip(0, 0) {}

PaySlip::PaySlip(int employee_id, int gross_pay)
    : employee_id(employee_id), gross_pay(gross_pay) {}

void PaySlip::addAdjustment(Adjustment* adjustment_ptr) {
  adjustment_ptrs.push_back(adjustment_ptr);
}

void PaySlip::removeLastAdjustment() {
  delete adjustment_ptrs.back();  // free up dynamic memory
  adjustment_ptrs.pop_back();
}

float PaySlip::getGrossPay() { return gross_pay; }

float PaySlip::getNetPay() {
  // Update NetPay
  net_pay = gross_pay;

  // Calculate the Adjustment
  for (Adjustment* adjustment_ptr : adjustment_ptrs) {
    net_pay += adjustment_ptr->calculateAdjustment(gross_pay);
  }

  return net_pay;
}

void PaySlip::setGrossPay(float gross_pay) { this->gross_pay = gross_pay; }

void PaySlip::setNetPay(float net_pay) { this->net_pay = net_pay; }

void PaySlip::generateSlip() {
  std::string filename = to_string(employee_id) + ".txt";
  // TODO: Finalize file format
  ofstream outfile;
  outfile.open(filename);
  if (outfile.is_open()) {
    outfile << "Employee ID: " << employee_id << endl;
    outfile << "Gross Pay: $" << gross_pay << endl;
    outfile << "Net Pay: $" << net_pay << endl;
    outfile.close();
  } else {
    cerr << "Error opening file" << endl;
  }
}
