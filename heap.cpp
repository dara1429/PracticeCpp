#include "heap.h"
#include <iostream>
#include <vector>
using namespace std;
//needed for heap operations/
#include <algorithm>

heap::heap()
{
  //init
}

heap::~heap()
{
  //deinit
}

void heap::heapBasics()
{
  vector<int> v1 = {1,6,11,3,5};
  vector<int> v2 = {12,10,5,4,1};

  make_heap(v1.begin(), v1.end());
  make_heap(v2.begin(), v2.end());

  //display max element of heap
  cout << "Max of v1 : " << v1.front() << endl;
  v1.push_back(20);
  push_heap(v1.begin(),v1.end());
  cout << "New max of v1 : " << v1.front() << endl;

  //delete max element of heap
  pop_heap(v1.begin(),v1.end());
  v1.pop_back();
  cout << "New max after deleting max : " << v1.front() << endl;

  //sort heap (least->greatest, container is not a heap anymore)
  cout << " v2 : " << endl;
  for(int &x : v2){cout << x << " ";}
  cout << endl;
  cout << " v2 aftering sort_heap (not a heap now) : " << endl;
  sort_heap(v2.begin(),v2.end());
  for(int &x : v2){cout << x << " ";}
  cout << endl;

  if(is_heap(v1.begin(),v1.end()) == true)
  {
    cout << "container v1 is heap" << endl;
  }

  if(is_heap(v2.begin(),v2.end()) == true)
  {
    cout << "container is heap" << endl;
  }
  else {cout << "container v2 is not a heap" << endl;}

  vector<int>::iterator it1;
  auto it2 = is_heap_until(v2.begin(),v2.end());
  cout << "Heap elements in vector : " << endl;
  for(it1 = v2.begin(); it1 != it2; it1++)
  {
    cout << *it1 << " ";
  }
  cout << endl;
  return;

}
