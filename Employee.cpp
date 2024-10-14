#include "Employee.h"

// Constructor initialization
Employee::Employee(const std::string &name, int employeeID, int age, bool isActive,
                   std::string position, WorkType workType, float payRate, int hoursWorked)
    : User(name, employeeID, age, isActive),
      position(position), workType(workType), payRate(payRate), hoursWorked(hoursWorked)
{
}

// Getter for payRate
float Employee::getPayRate() const
{
    return payRate;
}

// Getter for workType
WorkType Employee::getWorkType() const
{
    return workType;
}

// Getter for hoursWorked
int Employee::getHoursWorked() const
{
    return hoursWorked;
}

// Getter for position
std::string Employee::getPosition() const
{
    return position;
}

// Setter for hoursWorked
void Employee::setHoursWorked(int hours)
{
    this->hoursWorked = hours;
}

// Method to calculate total payment
float Employee::calculateTotalPayment() const
{
    if (workType == FullTime)
    {
        // Full-time employees have a fixed salary (payRate represents salary)
        return payRate;
    }
    else
    {
        // For other work types, payRate is hourly, so multiply by hours worked
        return payRate * hoursWorked;
    }
}
