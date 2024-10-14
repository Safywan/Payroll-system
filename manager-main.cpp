#include "Employee.h"
#include "Payroll.h"
#include "PaySlip.h"
#include "SuperAnnuation.h"
#include "Taxes.h"

#include <iostream>
#include <fstream>

#define DEBUG

using namespace std;

void removeEmployee(Payroll *payroll_ptr)
{
    // Remove Employee from payroll by prompting user for employeeID
    int id;
    cout << "Enter the ID of the Employee you are trying to remove: ";
    cin >> id;
    if (payroll_ptr->removeEmployee(id))
    {
        cout << "Employee removed successfully" << endl;
    }
    else
    {
        cout << "Invalid Employee ID. Try again" << endl;
    }
}

void addNewEmployee(Payroll *payroll_ptr)
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

    cout << "Enter if the Employee works Full Time(0), PartTime(1), Casual(2) or Contact(3): ";
    cin >> work_type_int;

    work_type = static_cast<WorkType>(work_type_int);

    // Add new employee to payroll
    // cout << name << " " << employeeID << ' ' << age << " " << position << " " << work_type_int << " "<< work_type << " " << pay_rate << endl;
    Employee newEmployee = Employee(name, employeeID, age, true, position, work_type, pay_rate, 0);
    payroll_ptr->addEmployee(newEmployee);
}

void viewEmployeeDetails(Payroll payroll)
{
    int number_employees = payroll.getNumberOfEmployees();
    cout << "The current number of employees in the Payroll is: " << number_employees << endl;

    if (number_employees > 0)
    {
        std::string *details = payroll.getEmployeeDetails();

        cout << "\nid | name | position | age" << endl;
        cout << "----------------------------" << endl;
        for (int i = 0; i < number_employees; i++)
        {
            cout << details[i] << endl;
        }

        delete[] details;
    }
}

/*
Saves The data in the following format: The first line will be the company account, followed by the number of employees.
Then, it will be ID, Name, Position, Age, isActive, work_type, pay_rate,  and hours_worked all in separate lines*/
void saveData(Payroll payroll)
{
    ofstream employee_file;
    employee_file.open("employees.txt");
    if (!employee_file.is_open())
    {
        cout << "Error while opening file. Please Try again" << endl;
    }
    else
    {
        // First line is the company account
        employee_file << payroll.getCompanyFund() << endl;

        // The second line should be the number of Employees
        int number_employees = payroll.getNumberOfEmployees();
        employee_file << number_employees << endl;

        // Iterate over all the employees
        vector<Employee> employees = payroll.getEmployees();
        for (Employee employee : employees)
        {
            employee_file << employee.getEmployeeID() << endl;
            employee_file << employee.getName() << endl;
            employee_file << employee.getPosition() << endl;
            employee_file << employee.getAge() << endl;
            employee_file << employee.getIsActive() << endl;
            employee_file << employee.getWorkType() << endl;
            employee_file << employee.getPayRate() << endl;
            employee_file << employee.getHoursWorked() << endl;
        }

        employee_file.close();
        cout << "Successfully saved data" << endl;
    }
}

void loadData(Payroll *payroll_ptr)
{
    ifstream employee_file;
    employee_file.open("employees.txt");
    if (!employee_file.is_open())
    {
        // TODO: Test what happens when file does not exist
        cout << "Error while opening file. Please Try again" << endl;
    }
    else
    {
        // Get company account and initialise payroll
        double company_account;
        employee_file >> company_account;
        *payroll_ptr = Payroll(company_account);

        // Get Number of Employees
        int num_employees;
        employee_file >> num_employees;

        int id, age, hours_worked, buffer;
        float pay_rate;
        string name, position;
        bool is_active;
        WorkType work_type;
        // Create each employee
        for (int i = 0; i < num_employees; i++)
        {
            employee_file >> id;
            employee_file >> name;
            employee_file >> position;
            employee_file >> age;
            employee_file >> is_active;
            employee_file >> buffer; // We need the buffer as work_type is a custom enum
            employee_file >> pay_rate;
            employee_file >> hours_worked;

            work_type = static_cast<WorkType>(buffer);

            // Create the Employee
            payroll_ptr->addEmployee(Employee(name, id, age, is_active, position, work_type, pay_rate, hours_worked));
        }
        employee_file.close();

        if (num_employees == payroll_ptr->getNumberOfEmployees())
        {
            cout << "Successfully loaded all employees" << endl;
        }
        else
        {
#ifdef DEBUG
            __throw_logic_error("Employees not fully loaded");
#endif
        }
    }
}

void initialisePayroll(Payroll *payroll_ptr)
{
    // Ask how much is in the company account
    double initCompanyAmount;
    cout << "Creating new Payroll..." << endl;
    cout << "How much is in the company account: " << endl;
    cin >> initCompanyAmount;

    // Initialise Payroll
    *payroll_ptr = Payroll(initCompanyAmount);
}

int main()
{
    // Check if save files exist
    ifstream employeeFile("employees.txt");

    Payroll payroll;
    // if it exists, allow the user to load data
    if (employeeFile.is_open())
    {
        employeeFile.close();
        char response;
        cout << "Save file detected. Do you want to load from the saved data? (y/n): ";
        cin >> response;
        do
        {
            switch (response)
            {
            case 'y':
                loadData(&payroll);
                break;
            case 'n':
                initialisePayroll(&payroll);
                break;
            default:
                cout << "Invalid option";
                break;
            }
        } while (response != 'y' and response != 'n');
    }
    else
    {
        cout << "No save file detected. Initialising new payroll" << endl;
        initialisePayroll(&payroll);
    }

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
        cout << "8. Save data" << endl;
        cout << "Enter your response: ";

        cin >> response;
        cout << endl;
        switch (response)
        {
        case 1: // Exit
            cout << "Exiting program..." << endl;
            break;
        case 2: // Add a New Employee
            addNewEmployee(&payroll);
            break;
        case 3: // Remove an Employee
            removeEmployee(&payroll);
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
            saveData(payroll);
            break;
        default:
            cout << "Invalid number";
        }
        cout << "\n\n";
    } while (response != 1);

    return 0;
}
