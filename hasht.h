#ifndef HASHT_H
#define HASHT_H
#include "hashe.h"

const int TABLE_SIZE = 256;

class hashT
{
  public:
    hashT();
    ~hashT();
    void hashtMain();
    //hashtable functions
    int get(int key);
    void put(int key, int value);
  private:
    hashE **table;
  protected:

};

#endif //HASHT_H
