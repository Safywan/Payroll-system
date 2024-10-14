#include <iostream>
#include <fstream>

#include "Utilities.h"

using namespace std;

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
                Utilities::loadData(&payroll);
                break;
            case 'n':
                Utilities::initialisePayroll(&payroll);
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
        Utilities::initialisePayroll(&payroll);
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
            Utilities::addNewEmployee(&payroll);
            break;
        case 3: // Remove an Employee
            Utilities::removeEmployee(&payroll);
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
            Utilities::viewEmployeeDetails(payroll);
            break;
        case 8: // View Employee details
            Utilities::saveData(payroll);
            break;
        default:
            cout << "Invalid number";
        }
        cout << "\n\n";
    } while (response != 1);

    return 0;
}
