#include "Utilities.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void Utilities::removeEmployee(Payroll *payroll_ptr) {
  if (payroll_ptr->getNumberOfEmployees() == 0) {
    cout << "You currently have no employees in your payroll system." << endl;
  } else {
    // Remove Employee from payroll by prompting user for employeeID
    int id;
    cout << "Enter the ID of the Employee you are trying to remove: ";
    id = Utilities::getNonNegativeNumber<int>();
    if (payroll_ptr->removeEmployee(id)) {
      cout << "Employee removed successfully" << endl;
    } else {
      cout << "Invalid Employee ID. Try again" << endl;
    }
  }
}

void Utilities::addNewEmployee(Payroll *payroll_ptr) {
  // Create new Employee by prompting user for the details and add it to the
  // payroll
  std::string name, position;
  int employeeID, age, work_type_int;
  WorkType work_type;
  double pay_rate;

  // prompting the user for all the details
  cout << "Enter the Name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Enter the EmployeeID: ";
  employeeID = Utilities::getNonNegativeNumber<int>();
  cout << "Enter the Employee's age: ";
  age = Utilities::getNonNegativeNumber<int>();
  cout << "Enter the Employee's position: ";
  cin.ignore();
  getline(cin, position);
  cout << "Enter the Pay Rate (per hour): ";
  pay_rate = Utilities::getNonNegativeNumber<int>();

  cout << "Enter if the Employee works Full Time(0), PartTime(1), Casual(2) or "
          "Contact(3): ";
  work_type_int = Utilities::sanitizeInput<int>();
  while (work_type_int < 0 or work_type_int > 3) {
    cout << "Invalid input. The number should be 0,1,2 or 3. Try again: ";
    work_type_int = Utilities::sanitizeInput<int>();
  }

  work_type = static_cast<WorkType>(work_type_int);

  // Add new employee to payroll
  // cout << name << " " << employeeID << ' ' << age << " " << position << " "
  // << work_type_int << " "<< work_type << " " << pay_rate << endl;
  Employee newEmployee =
      Employee(name, employeeID, age, true, position, work_type, pay_rate, 0);
  payroll_ptr->addEmployee(newEmployee);
}

void Utilities::viewEmployeeDetails(Payroll payroll) {
  int number_employees = payroll.getNumberOfEmployees();
  cout << "The current number of employees in the Payroll is: "
       << number_employees << endl;

  if (number_employees > 0) {
    std::string *details = payroll.getEmployeeDetails();

    cout << "\nid | name | position | age" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < number_employees; i++) {
      cout << details[i] << endl;
    }

    delete[] details;
  }
}

void Utilities::saveData(Payroll payroll) {
  /* Saves The data in the following format: The first line will be the company
  account, followed by the number of employees. Then, it will be ID, Name,
  Position, Age, isActive, work_type, pay_rate,  and hours_worked all in
  separate lines*/

  ofstream employee_file;
  employee_file.open("employees.txt");
  if (!employee_file.is_open()) {
    cout << "Error while opening file. Please Try again" << endl;
  } else {
    // First line is the company account
    employee_file << payroll.getCompanyFund() << endl;

    // The second line should be the number of Employees
    int number_employees = payroll.getNumberOfEmployees();
    employee_file << number_employees << endl;

    // Iterate over all the employees
    vector<Employee> employees = payroll.getEmployees();
    for (Employee employee : employees) {
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

void Utilities::loadData(Payroll *payroll_ptr) {
  ifstream employee_file;
  employee_file.open("employees.txt");
  if (!employee_file.is_open()) {
    // TODO: Test what happens when file does not exist
    cout << "Error while opening file. Please Try again" << endl;
  } else {
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
    for (int i = 0; i < num_employees; i++) {
      employee_file >> id;
      employee_file >> name;
      employee_file >> position;
      employee_file >> age;
      employee_file >> is_active;
      employee_file >>
          buffer;  // We need the buffer as work_type is a custom enum
      employee_file >> pay_rate;
      employee_file >> hours_worked;

      work_type = static_cast<WorkType>(buffer);

      // Create the Employee
      payroll_ptr->addEmployee(Employee(name, id, age, is_active, position,
                                        work_type, pay_rate, hours_worked));
    }
    employee_file.close();

    if (num_employees == payroll_ptr->getNumberOfEmployees()) {
      cout << "Successfully loaded all employees" << endl;
    } else {
      cout << "Error loading all Employees";
    }
  }
}

Employee *Utilities::getEmployeeFromId(Payroll payroll) {
  Employee *employee_ptr = nullptr;

  while (employee_ptr == nullptr) {
    cout << "Enter the ID: ";
    int id;
    id = Utilities::getNonNegativeNumber<int>();
    employee_ptr = payroll.getEmployee(id);
    if (employee_ptr == nullptr) {
      cout << "Invalid ID. Try again" << endl;
    }
  }
  return employee_ptr;
}

void Utilities::CreatePayslip(Payroll *payroll_ptr) {
  cout << "Retrieving the data of the relevant Employee..";

  // Use the below function to validate the ID and get the employee
  Employee *employee_ptr = Utilities::getEmployeeFromId(*payroll_ptr);

  cout << "Creating Payslip for: " << employee_ptr->getName();

  // Initialise the payslip
  PaySlip payslip = PaySlip(employee_ptr->getEmployeeID(),
                            employee_ptr->calculateTotalPayment());

  int response;
  do {
    // give a bit of background
    cout << employee_ptr->getName() << " has worked for "
         << employee_ptr->getHoursWorked() << " hours at an hourly rate of "
         << employee_ptr->getPayRate() << endl;
    cout << "They will be paid: $" << employee_ptr->calculateTotalPayment()
         << endl
         << endl;

    // Print options
    cout << "Enter the number of the option you wish to do:" << endl;
    cout << "1. Cancel" << endl;
    cout << "2. View all Employee Details";
    cout << "3. Modify work hours" << endl;
    cout << "4. Add taxes" << endl;
    cout << "5. Add super" << endl;
    cout << "6. Save Payslip" << endl;

    response = Utilities::getNonNegativeNumber<int>();
    cout << endl;
    string super_provider;

    switch (response) {
      case 1:  // Exit
        cout << "Heading back" << endl;
        break;
      case 2:  // view details
        cout << "ID: " << employee_ptr->getEmployeeID() << endl;
        cout << "Name: " << employee_ptr->getName() << endl;
        cout << "Position: " << employee_ptr->getPosition() << endl;
        cout << "Age: " << employee_ptr->getAge() << endl;
        cout << "PayRate: " << employee_ptr->getPayRate() << endl;
        cout << "Hours Worked: " << employee_ptr->getHoursWorked() << endl;

        break;
      case 3:  // set hours worked
        cout << "Enter Number of Hours: ";
        int hours;
        hours = Utilities::getNonNegativeNumber<int>();
        employee_ptr->setHoursWorked(hours);
        cout << "Hours set successfully";
        break;
      case 4: {
        cout << "Enter the tax rate: ";
        float tax_rate;
        tax_rate = Utilities::getNonNegativeNumber<float>();
        Taxes *tax_ptr = new Taxes(tax_rate);
        payslip.addAdjustment(tax_ptr);
        break;
      }
      case 5: {
        cout << "Enter the super rate: ";
        float super_rate;
        super_rate = Utilities::getNonNegativeNumber<float>();
        cout << "Enter the provider";
        cin >> super_provider;
        SuperAnnuation *super_ptr =
            new SuperAnnuation(super_rate, super_provider);
        payslip.addAdjustment(super_ptr);
        break;
      }
      case 6: {
        cout << "Saving Payslip" << endl;
        payroll_ptr->addPaySlip(payslip);
        break;
      }
      default:
        cout << "Invalid option" << endl;
        break;
    }
    cout << endl << endl;
  } while (response != 1 and response != 6);
}
void Utilities::initialisePayroll(Payroll *payroll_ptr) {
  // Ask how much is in the company account
  double initCompanyAmount;
  cout << "Creating new Payroll..." << endl;
  cout << "How much is in the company account: $";
  initCompanyAmount = Utilities::getNonNegativeNumber<double>();
  // Initialise Payroll
  *payroll_ptr = Payroll(initCompanyAmount);
}

// Add more fund if needed by manager
void Utilities::addCompanyFund(Payroll *payroll_ptr) {
  double addFund;
  cout << "Add money to your account:$ ";
  addFund = Utilities::getNonNegativeNumber<double>();

  // Update the account
  payroll_ptr->setCompanyFund(addFund);

  // Show how much was added
  cout << "$" << std::fixed << addFund << " was added to your account!" << endl;
  cout << "Your current balance is: " << "$" << payroll_ptr->getCompanyFund()
       << endl;
}

// Takes an input and ensures it is the right type. If it is not, it will keep
// prompting the user till its right
template <typename T>
T Utilities::sanitizeInput() {
  T response;
  while (!(cin >> response)) {
    // Clear the error flags on the input stream.
    cin.clear();

    // leave the rest of the line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Data type of response is unexpected. A number was expected. "
            "Please try again: ";
  }
  return response;
}

template <typename T>
T Utilities::getNonNegativeNumber() {
  T response = Utilities::sanitizeInput<T>();
  while (response < 0) {
    cout << "The response must be non-negative. Try again: ";
    response = Utilities::sanitizeInput<T>();
  }
  return response;
}
