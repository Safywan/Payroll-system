# The main .cpp files and .h files
cpp_files := Utilities.cpp Payroll.cpp PaySlip.cpp Adjustment.cpp SuperAnnuation.cpp Taxes.cpp Employee.cpp User.cpp
h_files := Utilities.h Payroll.h PaySlip.h Adjustment.h SuperAnnuation.h Taxes.h Employee.h User.h

all:
	g++ -Wall -std=c++11 -o manager.out manager-main.cpp $(cpp_files)
	g++ -Wall -std=c++11 -o employee.out employee-main.cpp $(cpp_files) 

manager: manager-main.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o manager.out manager-main.cpp $(cpp_files) 

employee: employee-main.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o employee.out employee-main.cpp $(cpp_files) 
# The testing .cpp files and .h files
testPayroll: testPayroll.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o testPayroll.out testPayroll.cpp $(cpp_files)

testEmployee:
	g++ -Wall -std=c++11 -o testEmployee.out testEmployee.cpp $(cpp_files)

testSuperAnnuation: testSuperAnnuation.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o testSuperAnnuation.out testSuperAnnuation.cpp $(cpp_files)

testTaxes: testTaxes.cpp Taxes.cpp Adjustment.cpp
	g++ -Wall -std=c++11 -o testTaxes.out testTaxes.cpp Taxes.cpp Adjustment.cpp

testUser: testUser.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o testUser.out testUser.cpp $(cpp_files)

clean : 
	rm *.out
cleanSlips:
	rm *.txt