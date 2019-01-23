#include "vector.h"
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
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
  int msArray[7] = {38,27,43,3,9,82,10};
  cout << "Vectors : " << endl;

  cout << "condensed vector traversal : " << endl;
  for(int &x : practiceVec){cout << x << " ";}
  cout << endl;

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
  printArray2(msArray);
  cout << "Merge Sort" << endl;
  mergeSort(msArray, 0, 6);
  printArray2(msArray);
  cout << "Swap numbers with no temp : " << endl;
  vector<tuple<int,int>> swapVector;
  int a = 5;
  int b = 2;
  swapVector = notempSwap(a,b);
  cout << a << " : " << b << endl;
  cout << get<0>(swapVector[0]) << " : " << get<1>(swapVector[0]) << endl;

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

void vectors::printArray2(int msArray[7])
{
  for(int i = 0; i < 7; i++)
  {
    cout << msArray[i] << ",";
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

void vectors::mergeSortMerge(int *msArray, int start, int middle, int end)
{
  int i = start;
  int j = middle + 1;
  int k = 0;

  //temporary array
  int *temp = new int[end-start+1];

  while (i <= middle && j <= end)
  {
    if(msArray[i] <= msArray[j])
    {
      temp[k++] = msArray[i++];
    }
    else
    {
      temp[k++] = msArray[j++];
    }
  }
  //put remaining elements of temporary array back into msArray
  while(i <= middle)
  {
    temp[k++] = msArray[i++];
  }
  while(j <= end)
  {
    temp[k++] = msArray[j++];
  }
  //copy newly merged temporary array back into msArray
  for(k = 0, i = start; i <= end; ++i, ++k)
  {
    msArray[i] = temp[k];
  }
  delete []temp;
}

void vectors::mergeSort(int *msArray, int start, int end)
{
  int middle;
  if(start < end)
  {
    //Obtain middle of vector without overflow
    middle = (start + end) / 2;
    //Sort first and second halves
    mergeSort(msArray,start,middle);
    mergeSort(msArray,middle+1,end);

    mergeSortMerge(msArray,start,middle,end);
  }
  return;

}

vector<tuple<int,int>> vectors::notempSwap(int a, int b)
{
  vector<tuple<int,int>> swapVector;
  //swap two numbers without any temp arrays etc.
  a = a - b;
  b = b + a;
  a = b - a;
  swapVector.push_back(make_tuple(a,b));
  return swapVector;
}
