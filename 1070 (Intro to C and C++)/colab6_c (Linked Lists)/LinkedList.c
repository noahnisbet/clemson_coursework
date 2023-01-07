/*
Noah Nisbet
Colab 6C
Byte Club
November 29, 2022
CPSC 1071, section 2

This file defines the methods created in the LinkedList header file.
*/

#include "Node.h"
#include "LinkedList.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 300

/*
printList takes in the head of a linked list and prints
out the nodes in a good format.
 */
void printList(struct node *head){
  // temp node for traversing list
  struct node *tempNode;
  // used to get number of nodes in the list
  int numNodes = 0;
  // dont do anything if list is empty
  if (head == NULL) {
    puts("");
  }
  else {
    // set temp node to head to start
    tempNode = head;
    // while the next node in list is not the null node
    // increase the numNodes variable by one.
    while (tempNode->next != NULL){
      tempNode = tempNode->next;
      numNodes++;
    }

    // set temp node back to the head for traversing
    tempNode = head;
    // if there is only one node print this way.
    if (numNodes == 1)
      printf("You've entered the following node: %s\n", head->data);
    // if there is only 2 nodes print this way.
    if (numNodes == 2){
      printf("You've entered the following nodes: %s and %s\n",
	     head->data, head->next->data);
    }
    // if there are more than 2 nodes print this way.
    if (numNodes > 2) {
      printf("You've entered the following nodes: ");
      // loop over all nodes and systematically print them out
      // depending on the postion of the node in the list.
      for (int i=0; i<numNodes; i++){
	if (i == 0)
	  printf("%s" , tempNode->data);
	else if (i == (numNodes-1))
	  printf(", and %s\n", tempNode->data);
	else
	  printf(", %s", tempNode->data);
	tempNode = tempNode->next; 
      }
    }
  }
  
  return;
}

/*
makeList creates a linked list based on the user inputs
until the user inputs a -99.
 */
struct node* makeList(){
  // define the head node.
  struct node *head;
  // allocate the head node memory.
  head = (struct node *)malloc(sizeof(struct node));
  // create curNode used in traversing the list.
  struct node *curNode = head;
  // create c-string to hold current use inputs.
  char input[MAX];

  // while the input is not -99 add nodes.
  while (strcmp(input, "-99") != 0){
    // use fget to get user input to allow for whitespace.
    printf("Enter a word or phrase, or -99 to end: ");
    fgets(input, MAX, stdin);
    // add the null character for c string to indicate the end.
    input[strlen(input)-1] = '\0';
    // if the input is not -99 create a new node.
    if (strcmp(input, "-99") != 0){
      // copy the c-string to the data member in the node struct.
      strcpy(curNode->data,input);
      // create the next node and allocate it some memory.
      struct node *nextNode;
      nextNode = (struct  node *)malloc(sizeof(struct node));
      // set the value of nextNode's next member to the null pointer
      // to indicate the end of the list.
      nextNode->next = NULL;
      // set the curNode's next member to the next node
      curNode->next = nextNode;
      // use nextNode as curNode from now on.
      curNode = nextNode;
    }
  }

  return head;
}

/*
deleteList function that loops over a linked list and deallocates all
the memory the linked list holds.
 */
void deleteList(struct node *head){
  // define a curNode and prevNode to use for deallocating memory
  struct node *curNode;
  struct node *prevNode;
  // if the head is the null pointer free the head only and return
  if (head == NULL) {
    free(head);
    return;
  }
  // otherwise traverse the list and free the current node using prevNode
  // and move to the next node.
  else {
    curNode = head;
    while (curNode != NULL){
      prevNode = curNode;
      curNode = curNode->next;
      free(prevNode);
    }
  }
  return;
}
