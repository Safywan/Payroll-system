#include "User.h"

// Constructor
User::User(const std::string &name, int employeeID, int age, bool isActive)
    : name(name), employeeID(employeeID), age(age), isActive(isActive) {}

// Getters and setters for user
std::string User::getName() const
{
    return name;
}

int User::getEmployeeID() const
{
    return employeeID;
}

int User::getAge() const
{
    return age;
}

bool User::getIsActive() const
{
    return isActive;
}
