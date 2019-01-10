CPP = g++
CFLAGS = -std=c++0x -Wall

practice: main.o vector.o tree.o
	$(CPP) $(CFLAGS) main.o vector.o tree.o -o practice

main.o: main.cpp
	$(CPP) -c main.cpp

vector.o: vector.cpp vector.h
	$(CPP) -c vector.cpp

tree.o: tree.cpp tree.h
	$(CPP) -c tree.cpp
	
clean:
	rm *.o practice
