#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

node::node(node *next, node *left, node *right, char* numOrSym) {
  this->left = left;
  this->right = right;
  this->next = next;
  strcpy(numOrSym, numOrSym);
}
//for characters 
node::node(char* numOrSym) {
  strcpy(numOrSym, numOrSym);
  left = NULL;
  right = NULL;
  next = NULL;
}
//default constructor
node::node() {
  left = NULL;
  right = NULL;
  next = NULL;
  numOrSym = ' ';
}
