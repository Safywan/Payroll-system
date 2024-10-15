// This unit test ensures that call the compononents in the payroll class is
// working without any errors
#include <iostream>

#include "Payroll.h"
using namespace std;

class PayRollTest {
 private:
  // Using default constructor for unit test
  Payroll payroll;

  void testDefinedConstructor() {
    // Parameterised constructor
    Payroll payFund(99000);
    if (payFund.getCompanyFund() < 0) {
      cout << "Company fund was not updated. Test failed!" << endl;
    } else {
      cout << "Company fund initialised! The current fund is: "
           << payFund.getCompanyFund() << endl;
    }
    // Current employee cost should be 0 without any calculations
    if (payFund.getTotalCost() > 0) {
      cout << "The cost for employees is not $0! Test failed!" << endl;
    } else {
      cout << "The current cost for employee is $0. Test passed!" << endl;
    }
  }

  // Adding employee feature unit test
  void testAddEmployee() {
    cout << "Testing adding employee feature..." << endl;
    cout << "\n";
    // Create different employees
    Employee employee1("Jacky", 1, 33, true, "Sales", FullTime, 32500,
                       40);  // Constructor from the employee class
    Employee employee2("Anna", 2, 29, false, "Marketing", PartTime, 28.5, 25);
    Employee employee3("Brian", 3, 45, true, "HR", FullTime, 40.0, 38);
    Employee employee4("Sophia", 4, 22, true, "Engineering", FullTime, 60000,
                       40);
    Employee employee5("Michael", 5, 38, false, "Finance", PartTime, 33.223,
                       20);
    Employee employee6("Emily", 6, 50, true, "Management", FullTime, 55.2,
                       45000);
    // Add employee
    payroll.addEmployee(employee1);
    payroll.addEmployee(employee2);
    payroll.addEmployee(employee3);
    payroll.addEmployee(employee4);
    payroll.addEmployee(employee5);
    payroll.addEmployee(employee6);

    for (int i = 0; i < payroll.getNumberOfEmployees(); i++) {
      if (i < payroll.getNumberOfEmployees()) {
        cout << "Employee " << i + 1 << " added succesfully!" << endl;
      } else {
        cout << "Employee " << i + 1 << " could not be added!" << endl;
      }
    }
  }

  // Calculate employee salary test
  void testTotalCost() {
    cout << "\n";
    cout << "Testing the calculations system for employess..." << endl;
    cout << "\n";
    // Check the total cost before calculation
    if (payroll.getTotalCost() > 0) {
      cout << "Variable not initialised!" << endl;
    } else {
      cout << "Variable is set to 0 as calculations has not been done! Test "
              "passed!"
           << endl;
    }
    payroll.calculateTotalCost();
    double totalSalary = payroll.getTotalCost();

    cout << "After calculations, the total cost for the above employees is: $"
         << totalSalary << endl;
  }

  // Unit test removeEmployee
  void testRemoveEmployee() {
    cout << "\n";
    cout << "Testing removing employee feature..." << endl;
    cout << "\n";

    // Get the number of employees before removing
    int totalEmployees = payroll.getNumberOfEmployees();
    cout << "The number of employees before removing from the system is: "
         << totalEmployees << endl;
    // Remove employee
    bool deleteEmployee = payroll.removeEmployee(2);

    if (deleteEmployee == true) {
      cout << "Employee removed successfully! Current number of employees in "
              "the system is: "
           << payroll.getNumberOfEmployees() << endl;
    } else {
      cout << "Employee id could not be found or failed to remove employee!"
           << endl;
    }
  }

  // Unit test processPayroll
  // ADD MORE TESTS!!
  /*
  Test the following functions:
  1. processPayroll
  2. removeEmployee [Done]
  3. addPayslip
  4. getEmployeeDetails
  5. generatePayslips
  */

 public:
  void runTests() {
    testDefinedConstructor();
    testAddEmployee();
    testTotalCost();
    testRemoveEmployee();
  }
};
// Testing in main function
int main() {
  PayRollTest payrolltests;

  cout << "Starting unit test for payroll class..." << endl;
  cout << "\n";

  // Test all the functionalities
  payrolltests.runTests();

  return 0;
}