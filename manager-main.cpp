#include <fstream>
#include <iostream>

#include "Utilities.h"

using namespace std;

int main() {
  // Check if save files exist
  ifstream employeeFile("employees.txt");

  Payroll payroll;
  // if it exists, allow the user to load data
  if (employeeFile.is_open()) {
    employeeFile.close();
    char response;
    cout << "Save file detected. Do you want to load from the saved data? "
            "(y/n): ";
    cin >> response;
    do {
      switch (response) {
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
  } else {
    cout << "No save file detected. Initialising new payroll" << endl;
    Utilities::initialisePayroll(&payroll);
  }

  int response;

  do  // Iterate over all the options until the user exits the program
  {
    // Print options and ask user for response
    cout << "What do you want to do? (Select the number of the option you want)"
         << endl;
    cout << "0. Save and Exit" << endl;
    cout << "1. Add a new Employee" << endl;
    cout << "2. Remove an Employee" << endl;
    cout << "3. Output total company cost" << endl;
    cout << "4. Process Payroll and pay outstanding balance" << endl;
    cout << "5. Generate Payslips for all Employees" << endl;
    cout << "6. View Details of all Employees" << endl;
    cout << "7. Add fund to the company account" << endl;
    cout << "8. Check your fund" << endl;
    cout << "9. Create a Payslip for an employee" << endl;
    cout << "Enter your response: ";

    cin >> response;
    cout << endl;
    switch (response) {
      case 0:  // Exit
        Utilities::saveData(payroll);
        cout << "Exiting program..." << endl;
        break;
      case 1:  // Add a New Employee
        Utilities::addNewEmployee(&payroll);
        break;
      case 2:  // Remove an Employee
        Utilities::removeEmployee(&payroll);
        break;
      case 3:  // Output total company cost
        cout << "The total cost is: " << payroll.getTotalCost() << endl;
        break;
      case 4:  // Process Payroll
        if (payroll.processPayRoll()) {
          cout << "The fund is processed! Thank you!" << endl;
        } else {
          cout << "Insufficient fund!. Please try again!" << endl;
          // Suggestion -> Ask manager to add fund
          Utilities::addCompanyFund(&payroll);
        }
        cout << "Your fund is currently: " << payroll.getCompanyFund() << endl;
        break;
      case 5:  // Generate payslips
        cout << "Generating Payslips for all Employees." << endl;
        payroll.generatePaySlips();
        break;
      case 6:  // View number of employees
        Utilities::viewEmployeeDetails(payroll);
        break;
      case 7:  // Add fund to the company account
        Utilities::addCompanyFund(&payroll);
        break;
      case 8:
        cout << "Your account balance:$" << payroll.getCompanyFund() << endl;
        break;
      case 9:  // Create Payslip
        Utilities::CreatePayslip(&payroll);
      default:
        cout << "Invalid number";
    }
    cout << "\n\n";
  } while (response != 0);

  return 0;
}
