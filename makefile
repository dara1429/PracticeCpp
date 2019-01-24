CPP = g++
CFLAGS = -std=c++11 -Wall
FILES = main.o vector.o tree.o hash.o hashe.o hasht.o struc.o heap.o que.o llist.o graph.o

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

hashe.o: hashe.cpp hashe.h
	$(CPP) -c hashe.cpp

hasht.o: hasht.cpp hasht.h
	$(CPP) -c hasht.cpp

struc.o: struc.cpp struc.h
	$(CPP) -c struc.cpp

heap.o: heap.cpp heap.h
	$(CPP) -c heap.cpp

que.o: que.cpp que.h
	$(CPP) -c que.cpp

llist.o: llist.cpp llist.h
	$(CPP) -c llist.cpp

graph.o: graph.cpp graph.h
	$(CPP) -c graph.cpp

clean:
	rm *.o practice
