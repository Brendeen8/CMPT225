myStack: my_stack_array.o my_stack_linked_list.o main.o
	g++ -std=c++17 -o myStack my_stack_array.o my_stack_linked_list.o main.o

my_stack_array.o: my_stack_array.h my_stack_array.cpp
	g++ -c my_stack_array.h my_stack_array.cpp

my_stack_linked_list.o: my_stack_linked_list.h my_stack_linked_list.cpp
	g++ -c my_stack_linked_list.h my_stack_linked_list.cpp

main.o: main.cpp 
	g++ -c main.cpp

clean: 
	rm -f *.o myStack
