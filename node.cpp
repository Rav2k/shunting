#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

node::node(node *next, node *left, node *right, char numOrSym) {
  this->left = left;
  this->right = right;
  this->next = next;
  this->numOrSym = numOrSym;
}
//for characters 
node::node(char numOrSym) {
  this->numOrSym = numOrSym;
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

node::node(node *root) {
  this->root = root;
  left = NULL;
  right = NULL;
  next = NULL;
  numOrSym = '\0';
}

node::node(node*left, node*right, char sym){
  this->left = left;
  this->right = right;
  this->root= NULL;
  this->numOrSym = numOrSym;
  next = NULL;
}
