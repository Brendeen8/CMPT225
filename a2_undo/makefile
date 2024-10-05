undo: StringList.o StringListTest.o
	g++ -std=c++17 -o undo StringList.o StringListTest.o

StringList.o: StringList.cpp StringList.h
	g++ -std=c++17 -Wall -c StringList.cpp

StringListTest.o: StringListTest.cpp StringList.h
	g++ -std=c++17 -Wall -c StringListTest.cpp

clean:
	rm -f *.o undo

