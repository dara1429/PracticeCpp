#ifndef TREE_H
#define TREE_H

struct treeNode
{
  int value;
  treeNode *left;
  treeNode *right;
};

class tree
{

  public:
    tree();
    ~tree();
    void treeMain();
    void insert(int value);
    void deleteNode(int value);
    treeNode *search(int value);
    void inorderPrint();
    void clearTree();
  private:
    void clearTree(treeNode *leaf);
    void insert(int value, treeNode *leaf);
    struct treeNode *minValueNode(struct treeNode* leaf);
    struct treeNode *deleteNode(int value, struct treeNode *leaf);
    treeNode *search(int value, treeNode *leaf);
    void inorderPrint(treeNode *leaf);
    treeNode *root;
  protected:

};

#endif
