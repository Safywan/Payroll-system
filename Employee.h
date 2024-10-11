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
    float payRate;  // Hourly or salary rate depending on the work type

public:
    Employee(const std::string &name, int employeeID, int age, bool isActive, std::string position, WorkType worktype, float payRate);
    
    // Getter for payRate
    float getPayRate() const;
    
    // Method to calculate total payment based on work type and pay rate
    float calculateTotalPayment(int hoursWorked) const;
};

#endif
