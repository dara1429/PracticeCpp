#include "llist.h"
#include <string>
#include <iostream>
using namespace std;

llist::llist()
{
  head = NULL;
  tail = NULL;
}

llist::~llist()
{
    node* del = head;
    while(del != NULL)
    {
      node* next = del->next;
      delete del;
      del = next;
    }
}

void llist::llistMain()
{
  llistAdd(1);
  llistAdd(6);
  llistAdd(2);
  llistAdd(10);
  llistAdd(5);
  llistAdd(15);
  llistAdd(9);
  llistPrint(head);
  cout << "After inserts/deletes : " << endl;
  llistInsert(8,1);
  llistDelete(1);
  llistDelete(2);
  llistPrint(head);
  return;
}

void llist::llistAdd(int value)
{
  node *temp = new node;
  temp->value = value;
  temp->next = NULL;

  //if linked list is empty
  if(head == NULL)
  {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
  return;
}

void llist::llistInsert(int value, int option)
{
  node *temp = new node;
  temp->value = value;
  int position = 4;

  //insert node at head of linked list
  if(option == 0)
  {
    temp->next = head;
    head = temp;
  }
  //insert node in the middle of the list (position in this example is 4th)
  else if(option == 1)
  {
    node *after = head;
    node *before = NULL;
    for(int i = 0; i < position-1; i++)
    {
      before = after;
      after = after->next;
    }
    temp->next = after;
    before->next = temp;
  }

  //insert node at end of list is same as llistAdd
  return;
}

void llist::llistDelete(int option)
{
  node *temp = head;
  int position = 2;

  //delete head of linked list
  if(option == 0)
  {
    head = head->next;
    delete temp;
  }
  //delete tail of the linked list (much easier with doubly linked)
  else if(option == 1)
  {
    node *current = head;
    node *previous = current;
    while(current->next != NULL)
    {
      previous = current;
      current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
  }
  //delete node in the middle of the linked list (position 2nd for example)
  else
  {
    node *current = head;
    node *previous = current;
    for(int i = 0; i < position-1; i++)
    {
      previous = current;
      current = current->next;
    }
    previous->next = current->next;
    delete current;
  }
  return;
}

void llist::llistPrint(node *head)
{
  cout << "Printing linked list : " << endl;
  node *temp = head;
  while(temp != NULL)
  {
    cout << temp->value << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
  delete temp;
  return;
}
