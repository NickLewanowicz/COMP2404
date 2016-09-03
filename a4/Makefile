OBJ = main.o BMScontrol.o UImanager.o DList.h BookArray.o Book.o Course.o Calculator.o Pen.o Comp.o Product.o ProductArray.o Account.o Admin.o Employee.o Student.o Professor.o

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

Product.o: Product.cc Product.h
	g++ -c Product.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h
	g++ -c UImanager.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

ProductArray.o:	ProductArray.cc ProductArray.h Book.h
	g++ -c ProductArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

Book.o:	Book.cc Book.h Product.h defs.h
	g++ -c Book.cc

Calculator.o:	Calculator.cc Calculator.h Product.h defs.h
	g++ -c Calculator.cc

Pen.o:	Pen.cc Pen.h Product.h defs.h
	g++ -c Pen.cc

Comp.o:	Comp.cc Comp.h Product.h defs.h
	g++ -c Comp.cc

Account.o:	Account.cc Account.h defs.h
	g++ -c Account.cc

Admin.o:	Admin.cc Admin.h Account.h defs.h
	g++ -c Admin.cc

Employee.o:	Employee.cc Employee.h Account.h defs.h
	g++ -c Employee.cc

Student.o:	Student.cc Student.h Account.h defs.h
	g++ -c Student.cc

Professor.o:	Professor.cc Professor.h Account.h defs.h
	g++ -c Professor.cc


clean:
	rm -f *.o a4
