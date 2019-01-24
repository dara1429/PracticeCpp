#include "hashe.h"

hashE::hashE(int key, int value)
{
  this->key = key;
  this->value = value;
}

int hashE::getKey()
{
  return key;
}

int hashE::getValue()
{
  return value;
}
