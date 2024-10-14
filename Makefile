# The main .cpp files and .h files
cpp_files := Utilities.cpp Payroll.cpp PaySlip.cpp Adjustment.cpp SuperAnnuation.cpp Taxes.cpp Employee.cpp User.cpp
h_files := Utilities.h Payroll.h PaySlip.h Adjustment.h SuperAnnuation.h Taxes.h Employee.h User.h

# The testing .cpp files and .h files
testPayroll:
	g++ -Wall -std=c++11 -o testPayroll.out testPayroll.cpp $(cpp_files)

all:
	g++ -Wall -std=c++11 -o manager.out manager-main.cpp $(cpp_files)
	g++ -Wall -std=c++11 -o employee.out employee-main.cpp $(cpp_files) 


manager.out : manager-main.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o manager.out manager-main.cpp $(cpp_files) 

employee.out : employee-main.cpp $(cpp_files) $(h_files)
	g++ -Wall -std=c++11 -o employee.out employee-main.cpp $(cpp_files) 

clean : 
	rm *.out