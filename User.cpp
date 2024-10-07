#include "User.h"

User::User(const std::string& name, int employeeID, int age, bool isActive) 
    : name(name), employeeID(employeeID), age(age), isActive(isActive) {}

std::string User::getName() const {
    return name;
}

int User::getEmployeeID() const {
    return employeeID;
}

int User::getAge() const {
    return age;
}

bool User::getIsActive() const {
    return isActive;
}
