#ifndef USER_H
#define USER_H

#include <string>

// User is an abstract class from which Employees will Inherit
class User
{
protected:
    std::string name;
    int employeeID;
    int age;
    bool isActive;

public:
    User(const std::string &name, int employeeID, int age, bool isActive);

    std::string getName() const;
    int getEmployeeID() const;
    int getAge() const;
    bool getIsActive() const;
};

#endif
