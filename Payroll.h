#ifndef PAYROLL_H
#define PAYROLL_H

#include <vector>

#include "Employee.h"
#include "PaySlip.h"

class Payroll {
 private:
  float taxRate;           // Tax rate
  float totalPayRollCost;  // Cost of total wages
  float companyFund;  // Salaries are paid from the company fund
  // Array of payslips
  vector<PaySlip> payslips;
  // Number of employees in the company
  vector<Employee> employees;

 public:
  // Constructor
  Payroll();
  Payroll(long double companyFund);
  // Process payroll
  bool processPayRoll();      // Process the payroll for all employees
  void calculateTotalCost();  // Calculates the total cost (including tax and
                              // superannuation)
  void addEmployee(Employee employee);  // Add employee to the payroll system
  bool removeEmployee(int employeeID);  // Remove employee to the payroll system
  void generatePaySlips();              // Generates payslips for employees
  // Remove employee to the payroll system

  void addPaySlip(PaySlip payslip);
  std::string *getEmployeesDetails();

  Employee *getEmployee(int employeeID);

  // If fund is low, manager can add fund
  void setCompanyFund(double addFund);

  // Getter functions for data members
  double getTaxRate();
  double getTotalCost();
  long double getCompanyFund();
  int getNumberOfEmployees();
  vector<Employee> getEmployees();
};

#endif