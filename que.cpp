#include "que.h"
#include <queue>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

que::que()
{
 //init
}

que::~que()
{
  //deinit
}

void que::queMain()
{
  //create queue
  queue <string> qu;

  //check if queue is empty
  if(qu.empty())
  {
    cout << "Queue created. It is empty. " << endl;
  }

  //insert element into queue (FIFO). There's two methods.
  qu.push("Bronze");
  qu.push("Iron");
  qu.push("Steel");
  qu.push("Black");
  qu.emplace("Mithril");
  qu.emplace("Adamant");
  qu.emplace("Rune");
  qu.emplace("Dragon");

  //get size of queue
  int quSize = qu.size();
  cout << "Elements added. Queue size is : " << quSize << endl;

  //get front and back of que
  cout << qu.front() << " = front of Queue" << endl;
  cout << qu.back() << " = back of Queue" << endl;

  //pop an element off the queue
  qu.pop();
  cout << qu.front() << " = new front of Queue after pop" << endl;

  //print queue (have to make copy of queue).
  //not efficient in code if you need to print the queue frequently.
  cout << "Printing Queue : " << endl;
  queue <string> quCopy = qu;
  while(!quCopy.empty())
  {
    cout << quCopy.front() << endl;
    quCopy.pop();
  }

  return;
}

void que::stackMain()
{
  //create stack
  stack <int> st;

  //basic stack operations (mostly similar to queue). All O(1)!
  if(st.empty())
  {
    cout << endl;
    cout << "Stack created. It is empty. " << endl;
  }

  st.push(5);
  st.push(3);
  st.push(9);
  st.push(6);
  st.push(7);
  st.push(1);

  int stSize = st.size();
  cout << "Stack size = " << stSize << endl;

  cout << "Top of stack = " << st.top() << endl;
  cout << st.top() << endl;

  cout << "Printing out stack : " << endl;
  while(!st.empty())
  {
    cout << st.top() << endl;
    st.pop();
  }


  return;
}
