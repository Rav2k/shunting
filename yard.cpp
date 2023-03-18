#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdio.h>

using namespace std;

struct queue{
  node *head = NULL;
  node *tail = NULL;
  void enqueue(char* symbol){
    node *user =  new node(symbol);//create node for the symbol;
    tail = user;
    tail = tail ->next;
  }
  char* dequeue(){
    if(tail == NULL){
      cout<<"put in an equation!!"<<endl;
      return;
    }
    node *tempQ;
    tempQ = tail;
    tail = tail->previous;
    tail-> next  = NULL;
    return tempQ;
  }

}

struct stack{
  node *headS = NULL;
  int index = 0;

  void push(char* numVal){
    int index++;
    node *userNode =  new node(numVal);//create node for the number
    userNode->next = headS;//set the next of the pointer to head
    headS = userNode;// set the head node to user because it is a stack
  }
  char* pop(){
    if(headS = NULL){//checking if there is anything to delete
      cout<<"There are no numbers here"<<endl;
      return 0;
    }
    else{//if there is then make a temp node and delete that node and replace the head node with the next node from 
      node *tempS;
      tempS = headS;
      headS = headS->next;
      delete tempS;
    }
  }
  char* peek(){
    if(headS == NULL){
      cout<<"nothing to print"<<endl;
      return 0;
    }
    char *print = new char[30];
    print = headS(numOrSym);
    return print;
  }
  char* display(){
    if(headS == NULL){
      cout<<"Enter an equation first"<<endl;
      return;
    }
    node *printer;
    printer = headS;
    char *printing = new char[30];
    for(int i = 0; i<index; i++){
       printing = printer(numOrSym);
       printer = printer->next;
       return printer;
    }
  }
  }
}

int main(){
  char *equation = new char[40];
  char *numsaver = new char[20];
  int data = 0;
  node *head;
  do{
  cout<<"enter equation(don't add spaces )"<<endl;
  cin.get(equation, 40);
  for(int i = 0; i<40;i++){
    if(isdigit(equation[i])){
      stack stack2;
      stack2.push(equation[i]);
    }
    else{
      queue queue2;
      queue2.enqueue(equation[i]);
    }
  }
 }while(head != NULL)
 
}

char* postfix(){
  
}

