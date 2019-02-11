#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Node* NodePointer;
void setNext(Node *currentNode,Node *nextNode);
void traverseList(Node *node);
int selectNext(Node *currentNode);
void insertAfter(Node *currentNode,Node *nodeAfter);

struct Node{
  int value;
  Node* next;
};
//Title:
//Linklist
//
//Description:
//A simple linked list implmentation in C without using minimal libraries
//
//Blog:
//This was also my first program in C and first program written using Vim
//I had a lot of fun with my first project. I had to learn pointers and was hard for me to learn
//as a java programmer. Nevertheless I think i have a good grasp of it. Programming in Vim
//was also a challenge. I still find moving the caret using hkjl awkward but i think
//I'm getting used to it. I am going to implement Stacks and Queues in C next.
//
//Date and Time:
//2/11/2019 - 9:45PM
int main(){
  NodePointer firstNode=NULL;
  Node node2;
  node2.value=2;
  Node node3;
  node3.value=3;
  Node node4;
  node4.value=4;
  Node node1;
  firstNode=malloc(sizeof(Node));
  firstNode=&node1;
  node1.value=1;
  setNext(&node1,&node2);
  setNext(&node2,&node4);
  traverseList(firstNode); 
  insertAfter(&node2,&node3);
  traverseList(firstNode); 
  
}

void setNext(Node *currentNode,Node *nextNode){
  currentNode->next=nextNode;
  nextNode->next=malloc(sizeof(Node));
  nextNode->next=NULL;
}

void insertAfter(Node *currentNode,Node *nodeAfter){
  NodePointer nodeHolder=NULL;
  nodeHolder=currentNode->next;
  currentNode->next=nodeAfter;
  nodeAfter->next=nodeHolder;
}

void traverseList(Node *node){
  Node *tempNode=node;
  while(tempNode!=NULL){
    printf("%d\n",tempNode->value); 
    tempNode=tempNode->next;
  }
  printf("End of list\n\n");
}

int selectNext(Node *currentNode){
  if(currentNode->next==NULL){
    return -1;
  }
  currentNode=currentNode->next;
  return 0;
}
