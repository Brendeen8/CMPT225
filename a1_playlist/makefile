playlist: PlayList.o Song.o a1main.o
	g++ -g -o playlist PlayList.o Song.o a1main.o

PlayList.o: PlayList.cpp PlayList.h
	g++ -c PlayList.cpp

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

a1main.o: a1main.cpp
	g++ -c a1main.cpp

clean: 
	rm -f *.o playlist
