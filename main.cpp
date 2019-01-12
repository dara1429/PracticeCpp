#include "vector.h"
#include "tree.h"
#include "hash.h"
#include "struc.h"
#include <iostream>
using namespace std;

int main () {
    // inits
    vectors v;
    tree t;
    hashes h;
    struc s;
    // menu
    int command = 0;
    while(command != 8)
    {

      cout << "\n" << "Menu : " << endl;
      cout << "1. Arrays and Vectors" << endl;
      cout << "2. Binary Trees" << endl;
      cout << "3. Hashmaps and Dictionaries" << endl;
      cout << "4. Structs and Pointers" << endl;
      cout << "5. Heaps" << endl;
      cout << "6. Queues and Stacks" << endl;
      cout << "7. Linked Lists" << endl;
      cout << "8. Exit Program" << "\n" << endl;

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
        case 8:
          cout << "Bye" << endl;
          break;
        default:
          cout << "\n" << "Invalid command" << "\n" << endl;
      }
    }
    return 0;
}
