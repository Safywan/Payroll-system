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
    float payRate;   // Hourly or salary rate depending on the work type
    int hoursWorked; // Track the number of hours worked

public:
    Employee(const std::string &name, int employeeID, int age, bool isActive, std::string position, WorkType workType, float payRate, int hoursWorked = 0);

    // Getter for payRate
    float getPayRate() const;

    // Getter for workType
    WorkType getWorkType() const;

    // Getter for hoursWorked
    int getHoursWorked() const;

    // Getter for position
    std::string getPosition() const;

    // Method to calculate total payment based on work type and pay rate
    float calculateTotalPayment() const;

    // Method to set hours worked
    void setHoursWorked(int hours);
};

#endif
