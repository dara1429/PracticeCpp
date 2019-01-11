CPP = g++
CFLAGS = -std=c++11 -Wall

practice: main.o vector.o tree.o hash.o
	$(CPP) $(CFLAGS) main.o vector.o tree.o hash.o -o practice

main.o: main.cpp
	$(CPP) -c main.cpp

vector.o: vector.cpp vector.h
	$(CPP) -c vector.cpp

tree.o: tree.cpp tree.h
	$(CPP) -c tree.cpp

hash.o: hash.cpp hash.h
	$(CPP) -c hash.cpp

clean:
	rm *.o practice
