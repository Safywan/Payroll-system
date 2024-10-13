#include "PaySlip.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

PaySlip::PaySlip() : PaySlip(0, 0) {}

PaySlip::PaySlip(int employeeID, int grossPay) : employeeID(employeeID), grossPay(grossPay) {}

void PaySlip::addAdjustment(Adjustment adjustemnet)
{
  adjustments.push_back(adjustemnet);
}

void PaySlip::removelastAdjustment() { adjustments.pop_back(); }

float PaySlip::getGrossPay() { return grossPay; }

float PaySlip::getNetPay() { return netPay; }

void PaySlip::setGrossPay(float grossPay) { this->grossPay = grossPay; }

void PaySlip::setNetPay(float netPay) { this->netPay = netPay; }

void PaySlip::generateSlip()
{
  std::string filename = to_string(employeeID) + ".txt";
  // TODO: Finalise file format
  ofstream outfile(filename);
  outfile << "Employee ID: " << employeeID << endl;
  outfile << "Gross Pay: " << grossPay << endl;
  outfile << "Net Pay: " << netPay << endl;
  outfile.close();
}
