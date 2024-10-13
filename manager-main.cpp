#include "Employee.h"
#include "Payroll.h"
#include "PaySlip.h"
#include "SuperAnnuation.h"
#include "Taxes.h"

#include <iostream>

using namespace std;

void removeEmployee(Payroll payroll)
{
    // Remove Employee from payroll by prompting user for employeeID
    int id;
    cout << "Enter the ID of the Employee you are trying to remove: ";
    cin >> id;
    if (payroll.removeEmployee(id))
    {
        cout << "Employee removed successfully" << endl;
    }
    else
    {
        cout << "Invalid Employee ID. Try again" << endl;
    }
}

void addNewEmployee(Payroll payroll)
{
    // Create new Employee by prompting user for the details and add it to the payroll
    std::string name, position;
    int employeeID, age, work_type_int;
    WorkType work_type;
    double pay_rate;

    // prompting the user for all the details
    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the EmployeeID: ";
    cin >> employeeID;
    cout << "Enter the Employee's age: ";
    cin >> age;
    cout << "Enter the Employee's position: ";
    cin >> position;
    cout << "Enter the Pay Rate (per hour): ";
    cin >> pay_rate;

    cout << "Enter if the Employee works Full Time(1), PartTime(2), Casual(3) or Contact(4)";
    cin >> work_type_int;
    switch (work_type_int)
    {
    case 1:
        work_type = FullTime;
        break;
    case 2:
        work_type = PartTime;
        break;
    case 3:
        work_type = Casual;
        break;
    case 4:
        work_type = Contract;
        break;

    default:
        break;
    }

    // Add new employee to payroll
    Employee newEmployee = Employee(name, employeeID, age, true, position, work_type, pay_rate);
    payroll.addEmployee(newEmployee);
}

void viewEmployeeDetails(Payroll payroll)
{
    int number_employees = payroll.getNumberOfEmployees();
    cout << "The current number of employees in the Payroll is: " << number_employees << endl;

    if (number_employees > 0)
    {
        std::string *details = payroll.getEmployeeDetails();

        cout << "id|name|position|age" << endl;
        for (int i = 0; i < number_employees; i++)
        {
            cout << details[i] << endl;
        }

        delete[] details;
    }
}

int main()
{
    // Ask how much is in the company account
    double initCompanyAmount;
    cout << "Creating new Payroll..." << endl;
    cout << "How much is in the company account: " << endl;
    cin >> initCompanyAmount;

    // Initialise Payroll
    Payroll payroll = Payroll(initCompanyAmount);
    int response;

    do // Iterate over all the options until the user exits the program
    {
        // Print options and ask user for response
        cout << "What do you want to do? (Select the number of the option you want)" << endl;
        cout << "1. Exit" << endl;
        cout << "2. Add a new Employee" << endl;
        cout << "3. Remove an Employee" << endl;
        cout << "4. Output total company cost" << endl;
        cout << "5. Process Payroll and pay outstanding balance" << endl;
        cout << "6. Generate Payslips for all Employees" << endl;
        cout << "7. View Details of all Employees" << endl;
        cout << "Enter your response: ";

        cin >> response;
        cout << endl;
        switch (response)
        {
        case 1: // Exit
            cout << "Exiting program..." << endl;
            break;
        case 2: // Add a New Employee
            addNewEmployee(payroll);
            break;
        case 3: // Remove an Employee
            removeEmployee(payroll);
            break;
        case 4: // Output total company cost
            cout << "The total cost is: " << payroll.getTotalCost() << endl;
            break;
        case 5: // Process Payroll
            if (payroll.processPayRoll())
            {
                cout << "The fund is processed! Thank you!" << endl;
            }
            else
            {
                cout << "Insufficient fund!. Please try again!" << endl;
            }
            cout << "Your fund is currently: " << payroll.getCompanyFund() << endl;
            break;
        case 6: // Generate payslips
            cout << "Generating Payslips for all Employees." << endl;
            payroll.generatePaySlips();
            break;
        case 7: // View number of employees
            viewEmployeeDetails(payroll);
            break;
        case 8: // View Employee details
            // TODO: Implement getEmployee(employeeID) function and put it here
            break;
        default:
            cout << "Invalid number";
        }
        cout << "\n\n";
    } while (response != 1);

    return 0;
}
