#include "Payroll.h"

#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;

// Constructor that initialises company fund
Payroll::Payroll(double companyFund) { this->companyFund = companyFund; }

void Payroll::processPayRoll()
{
  if (companyFund < totalPayRollCost)
  {
    cout << "Insufficient fund!. Please try again!" << endl;
  }
  cout << "The fund is processed! Thank you!" << endl;

  cout << "Your fund is currently: " << companyFund << endl;
}
// Calculates the total money needed from the company fund
void Payroll::calculateTotalCost()
{

  // Reset the cost to 0
  totalPayRollCost = 0;

  // Go through the employees and calculate their total cost using an iterator to iterate over the vector
  for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it)
  {
    totalPayRollCost += it->calculateTotalPayment(); // Add the employee payrate ????
  }
}
// Add employees
void Payroll::addEmployee(Employee employee)
{
  // Add employees to the array in the payroll system
  employees.push_back(employee);
}

// Remove employees
void Payroll::removeEmployee(int employeeID)
{
  // Search through the array to find the index using an iterator to iterate over the vector
  for (vector<Employee>::iterator it = employees.begin(); it != employees.end();)
  {
    if (employeeID == it->getEmployeeID())
    {
      employees.erase(it);
    }
    else
    {
      ++it;
    }
  }
}

// Add payslip to the payslip array
void Payroll::addPaySlip(PaySlip payslip)
{
  payslips.push_back(payslip);
}

// Generate payslips of different employees
void Payroll::generatePaySlips()
{
  // TODO: Implement function
}

// Getter functions defined

// Get number of employees
int Payroll::getNumberOfEmployees() { return employees.size(); }
double Payroll::getTaxRate() { return taxRate; }
double Payroll::getCompanyFund()
{
  // Return the balance of company fund
  return companyFund;
}
double Payroll::getTotalCost() { return totalPayRollCost; }
