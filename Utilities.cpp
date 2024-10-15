#include "Utilities.h"

using namespace std;

void Utilities::removeEmployee(Payroll *payroll_ptr)
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

void Utilities::addNewEmployee(Payroll *payroll_ptr)
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

void Utilities::viewEmployeeDetails(Payroll payroll)
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

void Utilities::saveData(Payroll payroll)
{

    /* Saves The data in the following format: The first line will be the company account, followed by the number of employees.
    Then, it will be ID, Name, Position, Age, isActive, work_type, pay_rate,  and hours_worked all in separate lines*/

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

void Utilities::loadData(Payroll *payroll_ptr)
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
            cout << "Error loading all Employees";
        }
    }
}

void Utilities::initialisePayroll(Payroll *payroll_ptr)
{
    // Ask how much is in the company account
    double initCompanyAmount;
    cout << "Creating new Payroll..." << endl;
    cout << "How much is in the company account:$ ";
    cin >> initCompanyAmount;

    // Initialise Payroll
    *payroll_ptr = Payroll(initCompanyAmount);
}

// Add more fund if needed by manager
void Utilities::addCompanyFund(Payroll *payroll_ptr) {
      double addFund;
  cout << "Add money to your account: ";
  cin >> addFund;

  // Update the account
  payroll_ptr->setCompanyFund(addFund);

  // Show how much was added
  cout << "$" << addFund << " was added to your account!" << endl;
  cout << "Your current balance is: " << "$" << payroll_ptr->getCompanyFund()
       << endl;

}