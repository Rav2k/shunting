#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include "node.h"


using namespace std;

int precedence(char sym);
node* treeMaking(queue2 Queue);
void printTree(node*cur, int layer);
void postfix(node *currentNode);
void prefix(node *cur);
void infix(node *current);

struct stackNode {

  node *head = NULL;
  //inserts node into the stack
  void push(node *node) {
    node *newnode = new node(node);
    if (head == NULL) {
      head = newnode;
      return;
    }
    newnode->next = head;
    head = newnode;
  }

  //removes the head of the stack
  void pop() {
    if (head == NULL) {
      return;
    }
    node *tempN;
    tempN = head;
    head = head->next;
    delete tempN;
  }

  //looks into and returns the head of the stack
  node *peek() {
    if (head == NULL) {
      return NULL;
    }
    return head->root;
  }

};

struct queue{
  node *head = NULL;
  node *tail = NULL;
  
  void enqueue(char symbol){
    node *user =  new node(symbol);//create node for the symbol;
    if(head == NULL){
      head = user;
      tail = head;
      return;
    }
    tail->next = user;//the node after the tail should be the new node
    tail = user;//the latest symbol added should be the tail
  };
  char dequeue(){
    if(tail == NULL){
      cout<<"put in an equation!!"<<endl;
      return 'e';//'e' for empty
    }
    node *tempQ;
    tempQ = tail;
    tail = tail->previous;
    tail->next  = NULL;
    return tempQ->numOrSym;
  };
  void dequeueDel(){
    if(tail == NULL){
      cout<<"put in an equation!!"<<endl;
      return;
    }
    node *tempQ;
    tempQ = tail;
    tail = tail->previous;
    tail->next  = NULL;
    delete tempQ;
  };
  char peek() {
    if (head == NULL) {
      return '\0';
    }
    return head->numOrSym;
  };
  void display() {
    node *cur = head;
    while (cur != NULL) {
      cout << cur->numOrSym;
      cur = cur->next;
    }
    cout << "done"<<endl;
  };

};

struct stack{
  node *headS = NULL;
  void push(char numVal){
    node *userNode =  new node(numVal);//create node for the number
    if(headS == NULL){
      headS = userNode;
      return;
    }
    userNode->next = headS;//set the next of the pointer to head
    headS = userNode;// set the head node to user because it is a stack
  };
  char pop(){
    if(headS = NULL){//checking if there is anything to delete
      cout<<"There are no numbers here"<<endl;
      return'\0';
    }
    else{//if there is then make a temp node and delete that node and replace the head node with the next node from
      node *tempS;
      tempS = headS;
      headS = headS->next;
      return tempS->numOrSym;
    }
  };
  char peek(){
    if(headS == NULL){
      cout<<"nothing to print"<<endl;
      return '\0';
    }
    headS->numOrSym;
  };
  void display(){
    if(headS == NULL){
      cout<<"Enter an equation first"<<endl;
      return;
    }
    node *printer;
    printer = headS;
    while(printer != NULL){
      cout<<printer->numOrSym;
      printer = printer->next;
    }
    cout<<"done printing"<<endl;
  };
};


int main(){
  char *equation = new char[40];
  char *numsaver = new char[20];
  stack stack2;
  queue queue2;
  cout<<"enter equation(don't add spaces )"<<endl;
  cin.get(equation, 40);
  for(int i = 0; i<strlen(equation);i++){
    if(equation[i] == ' '){
      //ignore
    }
    else if(isdigit(equation[i]) == 1){
      queue2.enqueue(equation[i]);
    }
    else{
      char data = equation[i];
      int dominance = precedence(data);
      if(data == '('){//put the start of the parenthesis in the stack
	stack2.push(data);
      }
      else if(data == ')'){//when you get to the end of the parenthesis then pop out the symbol
	char head  = stack2.peek();
	while(head != '\0' && head != '('){
	  stack2.pop();
	  queue2.enqueue(head);
	  head = stack2.peek();
	}
	if(head == '('){
	  stack2.pop();
	}
      }
       else{
	char head2 = stack2.peek();
	int maths = precedence(head2);
	while (head2!='\0'&&head2!='('&&(maths>dominance||(maths==dominance && input != '^'))){//other math symbols
	  stack2.pop();
	  queue2.enqueue(top);
	  head2 = operators.peek();
	  maths = precedence(head2);
	}
	stack2.push(input);
    }
  }
 
}
  while(stack2.peek() != '\0'){
    queue2.enqueue(stack2.peek());//putting the rest of the stack into the queue
    stack2.pop();
  }

  char *userInput = new char[20];
  
  queue2.display();

  node *root = treeMaking(queue2);

  printTree(root, 0);

  cout<<"Choose one, 'infix', 'postfix', or 'prefix': "<<endl;
  cin.getline(userInput, 20);

  if(strcmp(userInput, "infix") == 0){
    infix(root);
  }
  else if(strcmp(userInput, "postfix") == 0){
    postfix(root);
  }
  else if(strcmp(userInput,"prefix") == 0){
    prefix(root);
  }
  else{
    cout<<"type a valid choice remember to not have any spaces."<<endl;
  }
  return 0;
}


int precedence(char sym) {//I chose to use a number system to rank the precednece of each sign

  if (sym == '+' || sym == '-') {//least precendence
    return 1;
  }
  else if (sym == '*' || sym == '/') {
    return 2;
  }
  else if (sym == '^') {
    return 3;
  }
  else if (sym == '(' || sym == ')') {//greatest precedence
    return 4;
  }
  else {
    return 0;
  }
  
}

node* treeMaking(queue2 Queue){
  char sym = Queue.peek();//make the sym equal to the top of the queue 
  stackNode nodeStack;
  while(sym != '\0'){
    if(isdigit(sym)){//digit
      node *Tnode = new node(sym);
      nodeStack.push(Tnode);
    }
    else{//operator
      node *rightChild = nodeStack.peek();
      nodeStack.pop();//remove the node after it's been given to the rightchild
      node *leftChild = nodeStack.peek();
      nodeStack.pop();//remove the node after it's been given to the leftchild
      node *noding = new node(leftChild, rightChild, sym);
      nodeStack.push(noding);
    }
    queue.dequeueDel();
    sym = queue.peek();
  }
}

void printTree(node*cur, int layer){
  if (cur == NULL){
    return;
  }

  printTree(cur->right, layer +1);
  
  for(int i =0; i<layer;i++){
    cout<<"    ";
  }
  cout<<cur->numOrSym;

  printTree(cur->left, layer +1);

  
}

void postfix(node *currentNode){//using psuedo-code
  if(currentNode == NULL){
    return;
  }
  postfix(currentNode->left);
  postfix(currentNode->right);
  cout<<postfix->numOrSym;
}

void prefix(node *cur){
  if(cur == NULL){
    return;
  }
  cout<<prefix->numOrSym;
  prefix(cur->left);
  prefix(cur->right);
}

void infix(node *current){
  if(current == NULL){
    return;
  }
  infix(current->right);
  cout<<current->numOrSym;
  infix(current->left);
}

