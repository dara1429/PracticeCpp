CPP = g++
CFLAGS = -std=c++11 -Wall
FILES = main.o vector.o tree.o hash.o struc.o heap.o que.o

practice: $(FILES)
	$(CPP) $(CFLAGS) $(FILES) -o practice

main.o: main.cpp
	$(CPP) -c main.cpp

vector.o: vector.cpp vector.h
	$(CPP) -c vector.cpp

tree.o: tree.cpp tree.h
	$(CPP) -c tree.cpp

hash.o: hash.cpp hash.h
	$(CPP) -c hash.cpp

struc.o: struc.cpp struc.h
	$(CPP) -c struc.cpp

heap.o: heap.cpp heap.h
	$(CPP) -c heap.cpp

que.o: que.cpp que.h
	$(CPP) -c que.cpp

clean:
	rm *.o practice
