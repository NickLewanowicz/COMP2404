OBJ = main.o BMScontrol.o UImanager.o DList.o BookArray.o Book.o Course.o Calculator.o Pen.o Comp.o Product.o ProductArray.o

a1:	$(OBJ)
	g++ -o a3 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

Product.o: Product.cc Product.h
	g++ -c Product.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h
	g++ -c UImanager.cc

DList.o:	DList.cc DList.h Course.h
	g++ -c DList.cc

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
clean:
	rm -f *.o a3
