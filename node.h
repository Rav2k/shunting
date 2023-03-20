#include <iostream>
#include <cstring>

using namespace std;

class node{
 public:
  node *left;
  node *right;
  node *next;
  node *previous;
  char numOrSym;
  node(node * next, node *left, node *right, char numOrSym);
  node(char numOrSym2);
  node(node *root);//i call it root but it's the tree node, I don't feel like going back and changing the name right now.
  node();
  node *root;
  node(node*left, node*right, char sym);
};
