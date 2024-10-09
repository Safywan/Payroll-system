#include "Employee.h"

Employee::Employee(const std::string &name, int employeeID, int age, bool isActive,
                   std::string position, WorkType worktype, float payRate)
    : position(position), workType(workType), payRate(payRate),
      User(name, employeeID, age, isActive)
{
}