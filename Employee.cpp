#include "Employee.h"

// Constructor initialization
Employee::Employee(const std::string &name, int employeeID, int age, bool isActive,
                   std::string position, WorkType workType, float payRate)
    : position(position), workType(workType), payRate(payRate),
      User(name, employeeID, age, isActive)
{
}

// Getter for payRate
float Employee::getPayRate() const {
    return payRate;
}

// Method to calculate total payment
float Employee::calculateTotalPayment(int hoursWorked) const {
    if (workType == FullTime) {
        // Full-time employees have a fixed salary (payRate represents salary)
        return payRate;
    } else {
        // For other work types, payRate is hourly, so multiply by hours worked
        return payRate * hoursWorked;
    }
}
