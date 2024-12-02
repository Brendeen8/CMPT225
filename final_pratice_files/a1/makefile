run: PlayList.o Song.o main.o
	g++ -g -o run PlayList.o Song.o main.o

PlayList.o: PlayList.cpp PlayList.h
	g++ -c PlayList.cpp

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

a1main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm -f *.o playlist
