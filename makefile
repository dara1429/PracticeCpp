CPP = g++
CFLAGS = -std=c++0x -Wall

practice: main.o vector.o
	$(CPP) $(CFLAGS) main.o vector.o -o practice

main.o: main.cpp
	$(CPP) -c main.cpp

vector.o: vector.cpp vector.h
	$(CPP) -c vector.cpp

clean:
	rm *.o practice
