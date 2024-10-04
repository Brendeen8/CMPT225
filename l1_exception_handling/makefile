exception: ArrayClass.o ExceptionLab.o
	g++ -g -o exeption ArrayClass.o ExceptionLab.o

ArrayClass.o: ArrayClass.cpp ArrayClass.h
	g++ -c ArrayClass.cpp

ExceptionLab.o: ExceptionLab.cpp
	g++ -c ExceptionLab.cpp

clean: 
	rm -f *.o exception 
