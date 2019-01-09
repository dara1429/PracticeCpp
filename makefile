CPP = g++
CFLAGS = -std=c++0x -Wall

practice: main.o
	$(CPP) $(CFLAGS) main.o -o practice

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o practice
