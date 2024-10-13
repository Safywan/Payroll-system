cpp_files := Payroll.cpp PaySlip.cpp Adjustment.cpp SuperAnnuation.cpp Taxes.cpp Employee.cpp User.cpp
h_files := Payroll.h PaySlip.h Adjustment.h SuperAnnuation.h Taxes.h Employee.h User.h

manager.out : manager-main.cpp $(cpp_files) $(h_files)
	g++ -Wall -o manager.out manager-main.cpp $(cpp_files)

clean : 
	rm *.out