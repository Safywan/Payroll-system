#include "PaySlip.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

PaySlip::PaySlip() : PaySlip(0, 0) {}

PaySlip::PaySlip(int employeeID, int grossPay)
    : employeeID(employeeID), grossPay(grossPay) {}

void PaySlip::addAdjustment(Adjustment* adjustment_ptr) {
  adjustment_ptrs.push_back(adjustment_ptr);
}

void PaySlip::removeLastAdjustment() {
  delete adjustment_ptrs.back();  // free up dynamic memory
  adjustment_ptrs.pop_back();
}

float PaySlip::getGrossPay() { return grossPay; }

float PaySlip::getNetPay() {
  // Update NetPay
  netPay = grossPay;

  // Calculate the Adjustment
  for (Adjustment* adjustment_ptr : adjustment_ptrs) {
    netPay += adjustment_ptr->calculateAdjustment(grossPay);
  }

  return netPay;
}

void PaySlip::setGrossPay(float grossPay) { this->grossPay = grossPay; }

void PaySlip::setNetPay(float netPay) { this->netPay = netPay; }

void PaySlip::generateSlip() {
  std::string filename = to_string(employeeID) + ".txt";
  // TODO: Finalize file format
  ofstream outfile;
  outfile.open(filename);
  if (outfile.is_open()) {
    outfile << "Employee ID: " << employeeID << endl;
    outfile << "Gross Pay: $" << grossPay << endl;
    outfile << "Net Pay: $" << netPay << endl;
    outfile.close();
  } else {
    cerr << "Error opening file" << endl;
  }
}
