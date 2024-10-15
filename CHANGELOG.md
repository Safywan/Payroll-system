# CHANGE LOG

This file gives a brief but exhaustive list on the deviations between the project plan and the completed source code.

## Utilities Class

As the program was to be interfaced using two different executables, several functionalities had to be reused among both the [manager-main.cpp](manager-main.cpp) file and the [employee-main.cpp](employee-main.cpp) file, certain snippets were extracted into functions. Following OOP principles, the functions were implemented as static functions in a Utilities class, with a separate [.h file](Utilities.h) and [.cpp file](Utilities.h).

## [User Class](User.h)

- Changed `user_id` to `employee_id` to reflect the use of the variable better.

## [Payroll Class](Payroll.h)

- The return type of `processPayRoll()` was changed from `void` to `bool` to communicate if the company had enough funds in the payroll to pay off fees
- `addPaySlip(Payslip)` was added as previously, no method of adding a payslip to `payslips` existed.
- `std::string *getEmployeesDetails()` was implemented to get a string of employee details and to demonstrate useful use of dynamic memory.

## [Employee Class](Employee.h)

- Removed functions `calculateNetPay()` and `getPayDetails()` as this could be easily taken from the [`PaySlip` class](PaySlip.h).
- Added attribute `int hoursWorked` to store the hours work and help calculate gross pay.
