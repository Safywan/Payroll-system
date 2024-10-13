#include "Payroll.h"

using namespace std;

// Constructor that initialises company fund
Payroll::Payroll(double companyFund) { this->companyFund = companyFund; }

// Pays the outstanding PayRollCost and returns true if funds are sufficent. Returns false if not
bool Payroll::processPayRoll()
{
  if (companyFund < totalPayRollCost)
  {
    return false;
  }
  else
    companyFund -= totalPayRollCost;
  totalPayRollCost = 0;
  return true;
}

// Calculates the total money needed from the company fund
void Payroll::calculateTotalCost()
{
  // Reset the cost to 0
  totalPayRollCost = 0;

  // Go through the employees and calculate their total cost using an iterator to iterate over the vector
  for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it)
  {
    totalPayRollCost += it->calculateTotalPayment();
  }
}

// Add an Employee object to the vector
void Payroll::addEmployee(Employee employee)
{
  employees.push_back(employee);
}

/* Takes an employeeID and removes the relevant employee from the payroll and returns true.
 Returns false if no such employee exists. */
bool Payroll::removeEmployee(int employeeID)
{
  // Search through the array to find the index using an iterator to iterate over the vector
  for (vector<Employee>::iterator it = employees.begin(); it != employees.end();)
  {
    if (employeeID == it->getEmployeeID())
    {
      employees.erase(it);
      return true;
    }
    else
    {
      ++it;
    }
  }
  return false;
}

// Add payslip to the payslip array
void Payroll::addPaySlip(PaySlip payslip)
{
  payslips.push_back(payslip);
}

// Generate payslips of all employees and add to outstanding cost
void Payroll::generatePaySlips()
{
  for (PaySlip payslip : payslips)
  { // Iterates over all Payslips in the "payslip" vector and stores in variable payslip
    payslip.generateSlip();
  }
  calculateTotalCost();
}

// Getter functions defined
int Payroll::getNumberOfEmployees() { return employees.size(); }
double Payroll::getTaxRate() { return taxRate; }
double Payroll::getCompanyFund() { return companyFund; }
double Payroll::getTotalCost() { return totalPayRollCost; }
