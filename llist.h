#ifndef LLIST_H
#define LLIST_H

struct node
{
 int value;
 node *next;
};


class llist
{
  public:
    llist();
    ~llist();
    void llistMain();
    void llistAdd(int value);
    void llistInsert(int value, int option);
    void llistDelete(int option);
    void llistPrint(node *head);
  private:
    //linked list start and end
    node *head;
    node *tail;
  protected:
};

#endif //LLIST.H
