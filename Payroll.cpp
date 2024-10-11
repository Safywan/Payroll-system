#include "Payroll.h"

#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;

// Constructor that initialises company fund
Payroll::Payroll(double companyFund) { this->companyFund = companyFund; }

void Payroll::processPayRoll() {
  if (companyFund < totalPayRollCost) {
    cout << "Insufficient fund!. Please try again!" << endl;
  }
  cout << "The fund is processed! Thank you!" << endl;

  cout << "Your fund is currently: " << companyFund << endl;
}
// Calculates the total money needed from the company fund
float Payroll::calculateTotalCost() {
  // Go through the employees and calculate their total cost
  for (int i = 0; i < employees.size(); i++) {
    totalPayRollCost =
        totalPayRollCost +
        employees[i].calculateTotalPayment();  // Add the employee payrate ????
  }
}
// Add employees
void Payroll::addEmployee(Employee employee) {
  // Add employees to the array in the payroll system
  employees.push_back(employee);
}

// Remove employees
void Payroll::removeEmployee(Employee employee) {
  // We need to make the employee ID as the index number row in the array
  int target = employee.getEmployeeID();

  int index;  // Store the position of the employee in the vector

  // Search through the array to find the index
  for (int i = 0; i < employees.size(); i++) {
    if (target == employees[i].getEmployeeID()) {
      index = i;
    }
  }
  // Remove the employee from the array
  employees.erase(employees.begin() + index);
}

// Add payslip to the payslip array
void Payroll::addPaySlip(PaySlip payslip) {
  payslips.push_back(payslip);
}

// Generate payslips of different employees


// Getter functions defined

// Get number of employees
int Payroll::getNumberOfEmployees() { return employees.size(); }
double Payroll::getTaxRate() { return taxRate; }
double Payroll::getCompanyFund() {
  // Return the balance of company fund
  return companyFund;
}
double Payroll::getTotalCost() { return totalPayRollCost; }
