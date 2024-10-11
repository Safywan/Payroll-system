#include "Payroll.h"

#include <algorithm>
#include <iostream>

using namespace std;

void 

float Payroll::calculateTotalCost() {
  // Go through the employees and calculate their total cost
  for (int i = 0; i < employees.size(); i++) {
    totalPayRollCost = totalPayRollCost; // Add the employee payrate ????
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
// Getter functions defined

// Get number of employees
int Payroll::getNumberOfEmployees() { return employees.size(); }
double Payroll::getTaxRate() { return taxRate; }
double Payroll::getCompanyFund() {
  // Return the balance of company fund
  return companyFund;
}
double Payroll::getTotalCost() {
    return totalPayRollCost;
}
