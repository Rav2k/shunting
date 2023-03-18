#include <iostream>
#include <cstring>

using namespace std;

class node{
 public:
  node *left;
  node *right;
  node *next;
  node *previous;
  char *numOrSym;
  node(node * next, node *left, node *right, char *numOrSym);
  node(char *numOrSym);
  node();
}
