#include "vector.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vectors::vectors()
{
  //init class
}

vectors::~vectors()
{
  //destruct class
}

void vectors::vectorsMain()
{
  vector<int> practiceVec = {2,3,9,6,1};
  int practiceArray[10] = {1,5,8,4,3,0,0,0,0,0};
  practiceVec = addElement(practiceVec);
  printVector(practiceVec);
  practiceVec = insertElement(practiceVec);
  printVector(practiceVec);
  printArray(practiceArray);
  return;
}

void vectors::printVector(vector<int> practiceVec)
{
  cout << "printing vector : " << endl;
  for(int i = 0; i < practiceVec.size(); i++)
  {
    cout << practiceVec[i] << ",";
  }
  cout << endl;
  return;
}

void vectors::printArray(int practiceArray[10])
{
  cout << "printing array : " << endl;
  for(int i = 0; i < 10; i++)
  {
    cout << practiceArray[i] << ",";
  }
  cout << endl;
  return;
}
vector<int> vectors::addElement(vector<int> practiceVec)
{
  int input = 5;
  practiceVec.push_back(input);
  cout << "pushed back 5 into vector (Fast)." << endl;
  return practiceVec;
}

vector<int> vectors::insertElement(vector<int> practiceVec)
{
  int input = 3;
  practiceVec.insert(practiceVec.begin(),input);
  cout << "inserted 3 into beginning of vector (Medium, moves every element after inserted element)." << endl;
  return practiceVec;
}
