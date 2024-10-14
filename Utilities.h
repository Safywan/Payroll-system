#ifndef Utilities_h
#define Utilities_h

#include <iostream>
#include <fstream>

#include "Payroll.h"
#include "Employee.h"
#include "Payroll.h"
#include "PaySlip.h"
#include "SuperAnnuation.h"
#include "Taxes.h"

class Utilities
{
public:
    static void removeEmployee(Payroll *payroll_ptr);
    static void addNewEmployee(Payroll *payroll_ptr);

    static void viewEmployeeDetails(Payroll payroll);
    
    static void saveData(Payroll payroll);
    static void loadData(Payroll *payroll_ptr);

    static void initialisePayroll(Payroll *payroll_ptr);

};


#endif