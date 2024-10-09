#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

enum WorkType
{
    FullTime,
    PartTime,
    Casual,
    Contract
};

class Employee : public User
{
private:
    std::string position;
    WorkType workType;
    float payRate;

public:
    Employee(const std::string &name, int employeeID, int age, bool isActive, std::string position, WorkType worktype, float payRate);
   
   // TODO: Implement the following in Payroll class with EmployeeID
    // float calculateGrossPay();
    // float calculateNetPay();
    // void getPayDetails();
};

#endif