#include "tree.h"
#include <iostream>
using namespace std;

tree::tree()
{
  root = NULL;
}

tree::~tree()
{
  clearTree();
}

void tree::treeMain()
{
  cout << "creating example tree" << endl;
  insert(8);
  insert(3);
  insert(11);
  insert(1);
  insert(2);
  insert(9);
  insert(14);

  cout << "searching for 3 ... " << endl;
  search(3);

  cout << "inorder traversal ... " << endl;
  inorderPrint();

  cout << "deleting 11 ... " << endl;
  deleteNode(11);
  inorderPrint();

}

void tree::clearTree()
{
  clearTree(root);
}

void tree::clearTree(treeNode *leaf)
{
  if(leaf != NULL)
  {
    clearTree(leaf->left);
    clearTree(leaf->right);
    delete leaf;
  }
}

treeNode *tree::search(int value)
{
  return search(value, root);
}

treeNode *tree::search(int value, treeNode *leaf)
{
  if(leaf != NULL)
  {
    if(value == leaf->value)
    {
      cout << "  found : " << leaf->value << endl;
      return leaf;
    }
    if(value < leaf->value)
    {
      return search(value, leaf->left);
    }
    else
    {
      return search(value, leaf->right);
    }
  }
  else
  {
    return NULL;
  }
}

void tree::inorderPrint()
{
  inorderPrint(root);
  cout << "\n";
  return;
}

void tree::inorderPrint(treeNode *leaf)
{
  if(leaf != NULL)
  {
    inorderPrint(leaf->left);
    cout << leaf->value << ",";
    inorderPrint(leaf->right);
  }
}
void tree::insert(int value)
{
  if(root != NULL)
  {
    insert(value,root);
  }
  else
  {
    root = new treeNode;
    root->value = value;
    root->left = NULL;
    root->right = NULL;
  }
}

void tree::insert(int value, treeNode *leaf)
{
  if(value < leaf->value)
  {
    if(leaf->left != NULL)
    {
      insert(value, leaf->left);
    }
    else
    {
      leaf->left = new treeNode;
      leaf->left->value = value;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  }

  else if(value >= leaf->value)
  {
    if(leaf->right != NULL)
    {
      insert(value, leaf->right);
    }
    else
    {
      leaf->right = new treeNode;
      leaf->right->value = value;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}

struct treeNode* tree::minValueNode(struct treeNode* leaf)
{
    struct treeNode* minNode = leaf;

    /* loop down to find the leftmost leaf */
    while (minNode->left != NULL)
        minNode= minNode->left;

    return minNode;
}

void tree::deleteNode(int value)
{
  deleteNode(value,root);
  return;
}

struct treeNode* tree::deleteNode(int value, struct treeNode *leaf)
{
  if(leaf == NULL)
  {
    cout << "empty tree" << endl;
  }

  if(value < leaf->value)
  {
    leaf->left = deleteNode(value,leaf->left);
  }

  else if(value > leaf->value)
  {
    leaf->right = deleteNode(value,leaf->right);
  }

  else
  {
    //value matches so delete current treeNode
    //if you have one child
    if(leaf->left == NULL)
    {
      struct treeNode *temp = leaf->right;
      delete(leaf);
      return temp;
    }
    else if(leaf->right == NULL)
    {
      struct treeNode *temp = leaf->left;
      free(leaf);
      return temp;
    }
    //if you have two children, get smallest in right subtree
    treeNode* temp = minValueNode(leaf->right);
    //copy the next smallest node content to current node
    leaf->value = temp->value;
    //delete the next smallest minNode
    leaf->right = deleteNode(temp->value, leaf->right);
  }

  return leaf;
}
