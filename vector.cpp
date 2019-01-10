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
  cout << "Vectors : " << endl;
  practiceVec = addElement(practiceVec);
  printVector(practiceVec);
  practiceVec = insertElement(practiceVec);
  printVector(practiceVec);
  practiceVec = insertAt(practiceVec);
  printVector(practiceVec);
  practiceVec = deleteElement(practiceVec);
  printVector(practiceVec);
  cout << "Arrays : " << endl;
  printArray(practiceArray);
  practiceArray[10] = arrayInsertDelete(practiceArray);
  printArray(practiceArray);
  cout << "Algorithms : " << endl;
  cout << "Merge Sort" << endl;
  //mergeSort(msVector, 0, 6);
  return;
}

void vectors::printVector(vector<int> practiceVec)
{
  for(int i = 0; i < practiceVec.size(); i++)
  {
    cout << practiceVec[i] << ",";
  }
  cout << endl;
  return;
}

void vectors::printArray(int practiceArray[10])
{
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
  cout << "pushed back 5 into vector." << endl;
  //Fast, o(1).
  return practiceVec;
}

vector<int> vectors::insertElement(vector<int> practiceVec)
{
  int input = 3;
  practiceVec.insert(practiceVec.begin(),input);
  cout << "inserted 3 into beginning of vector." << endl;
  //Medium, moves every element after inserted element.
  return practiceVec;
}

vector<int> vectors::insertAt(vector<int> practiceVec)
{
  int input = 8;
  practiceVec.at(1) = input;
  cout << "replaced position 1 in vector with 8" << endl;
  //Fast, replaces element.
  return practiceVec;
}

vector<int> vectors::deleteElement(vector<int> practiceVec)
{
  practiceVec.erase(practiceVec.begin() + 2);
  cout << "erased position 2 in vector" << endl;
  //Medium, need to shift elements down but very simple with vectors.
  return practiceVec;
}

int vectors::arrayInsertDelete(int practiceArray[10])
{
  int input = 9;
  practiceArray[1] = input;

  for(int i = 3; i < 9; i++)
  {
    practiceArray[i] = practiceArray[i+1];
  }
  practiceArray[9] = 0;
  cout << "added 9 to 2nd position in array and deleted the 4th position" << endl;
  return practiceArray[10];
}

void vectors::mergeSortMerge(int *msVector, int start, int middle, int end)
{
  int i, j, k;
  int n1 = middle - start + 1;
  int n2 = end - middle;
  //temporary vectors
  vector<int> l;
  vector<int> r;

  //copy elements into temp Arrays
  for(i = 0; i < n1; i++)
  {
    l.push_back(msVector[start+i]);
  }
  for(j = 0; j < n2; j++)
  {
    r.push_back(msVector[middle + 1 + j]);
  }

  //merge temporary vectors back into msVector sorted
  i = 0;
  j = 0;
  k = 1;
  while (i < n1 && j < n2)
  {
    if(l[i] <= r[j])
    {
      msVector[k] = l[i];
      i++;
    }
    else
    {
      msVector[k] = r[j];
      j++;
    }
    k++;
  }
  //put remaining elements of l[] and r[] back into msVector
  while(i < n1)
  {
    msVector[k] = l[i];
    i++;
    k++;
  }
  while(j < n2)
  {
    msVector[k] = r[i];
    j++;
    k++;
  }
}

void vectors::mergeSort(int *msVector, int start, int end)
{
  int middle;
  if(start < end)
  {
    //Obtain middle of vector without overflow
    middle = (start + end)/ 2;
    //Sort first and second halves
    mergeSort(msVector,start,middle);
    mergeSort(msVector,middle+1,end);

    mergeSortMerge(msVector,start,middle,end);
  }

}
