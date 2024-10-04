undo: StringList.o StringListTest.o 
	g++ -g -o undo StringList.o StringListTest.o 

StringList.o: StringList.cpp StringList.h
	g++ -c StringList.cpp

StringListTest.o: StringListTest.cpp
	g++ -c StringListTest.cpp


clean:
	rm -f *.o undo
