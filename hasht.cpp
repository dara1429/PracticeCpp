#include "hasht.h"
#include <string>
#include <iostream>
using namespace std;

hashT::hashT()
{
  table = new hashE*[TABLE_SIZE];
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    table[i] = NULL;
  }
}

hashT::~hashT()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(table[i] != NULL)
    {
      delete table[i];
    }
  }
  delete[] table;
}

void hashT::hashtMain()
{
  cout << endl;
  cout << "Hash Table : " << endl;
  cout << "Adding (0,2),(1,4),(2,7),(3,4),(3,5) into hash table..." << endl;
  put(0,2);
  put(1,4);
  put(2,7);
  put(3,4);
  put(3,5);
  cout << "Retrieving keys 0,1,2,3..." << endl;
  cout << get(0) << "," << get(1) << "," << get(2) << "," << get(3) << endl;
}

int hashT::get(int key)
{
  int hash = (key % TABLE_SIZE);
  while(table[hash] != NULL & table[hash]->getKey() != key)
  {
    hash = (hash + 1) % TABLE_SIZE;
  }
  if(table[hash] == NULL)
  {
    return -1;
  }
  else
  {
    return table[hash]->getValue();
  }
}

void hashT::put(int key, int value)
{
  int hash = (key % TABLE_SIZE);
  while(table[hash] != NULL && table[hash]->getKey() != key)
  {
    hash = (hash + 1) % TABLE_SIZE;
  }
  if(table[hash] != NULL)
  {
    delete table[hash];
  }
  table[hash] = new hashE(key,value);
}
