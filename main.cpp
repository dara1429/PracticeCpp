#include "vector.h"
#include "tree.h"
#include "hash.h"
#include "struc.h"
#include "heap.h"
#include "que.h"
#include "llist.h"
#include "graph.h"
#include <iostream>
using namespace std;

int main () {
    // inits
    vectors v;
    tree t;
    hashes h;
    struc s;
    heap he;
    que q;
    llist l;
    //number of verticies in graph.
    int n = 9;
    graph g(n);
    // menu
    int command = 0;
    while(command != 9)
    {

      cout << "\n" << "Menu : " << endl;
      cout << "1. Arrays and Vectors" << endl;
      cout << "2. Binary Trees" << endl;
      cout << "3. Hashmaps and Dictionaries" << endl;
      cout << "4. Structs and Pointers" << endl;
      cout << "5. Heaps" << endl;
      cout << "6. Queues and Stacks" << endl;
      cout << "7. Linked Lists" << endl;
      cout << "8. Graphs" << endl;
      cout << "9. Exit Program" << "\n" << endl;

      cin >> command;
      if(cin.fail())
      {
        cin.clear();
        cin.ignore();
      }

      switch(command)
      {
        case 1:
          v.vectorsMain();
          break;
        case 2:
          t.treeMain();
          break;
        case 3:
          h.hashMain();
          break;
        case 4:
          s.strucMain();
          break;
        case 5:
          he.heapMain();
          break;
        case 6:
          q.queMain();
          q.stackMain();
          break;
        case 7:
          l.llistMain();
          break;
        case 8:
          g.graphPrint(g,n);
          g.dijkstra();
          break;
        case 9:
          cout << "Bye" << endl;
          break;
        default:
          cout << "\n" << "Invalid command" << "\n" << endl;
      }
    }
    return 0;
}
