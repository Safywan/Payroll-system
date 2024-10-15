#ifndef Utilities_h
#define Utilities_h

#include <fstream>
#include <iostream>

#include "Employee.h"
#include "PaySlip.h"
#include "Payroll.h"
#include "SuperAnnuation.h"
#include "Taxes.h"

class Utilities {
 public:
  static void removeEmployee(Payroll *payroll_ptr);
  static void addNewEmployee(Payroll *payroll_ptr);

  static void viewEmployeeDetails(Payroll payroll);

  static void saveData(Payroll payroll);
  static void loadData(Payroll *payroll_ptr);

  static void initialisePayroll(Payroll *payroll_ptr);

  static Employee *getEmployeeFromId(Payroll payroll);
  static void CreatePayslip(Payroll *payroll_ptr);
  static void addCompanyFund(Payroll *payroll_ptr);
};

#endif