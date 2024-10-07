#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;
    int employeeID;
    int age;
    bool isActive;

public:
    User(const std::string& name, int employeeID, int age, bool isActive);
    
    virtual ~User() {}

    std::string getName() const;
    int getEmployeeID() const;
    int getAge() const;
    bool getIsActive() const;
};

#endif
