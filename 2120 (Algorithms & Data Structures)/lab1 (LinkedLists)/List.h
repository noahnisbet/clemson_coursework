/*
 * Name: Noah Nisbet
 * Date Submitted: January 26, 2023
 * Lab Section: 004
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues 
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){ 
  // initializing
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  // loop until last node and delete previous node as I loop through
  Node<T> *curNode = start;
  for (int i=1; i<mySize; i++){
      Node<T> *tempNode = curNode;
      curNode = curNode->next;
      delete tempNode;
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if (mySize == 0) {
    return true;
  }
  else {
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  // create new start/head node and allocate memory for it.
  Node<T> * newHead = new Node<T> (value);
  // the next value in newHead is now the start node
  newHead->next = start;
  // pointer to start is now the new head
  start = newHead;
  // increase size
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  // if the list is empty use insertStart
  if (mySize == 0){
    insertStart(value);
  }
  // otherwise loop through the list until the last node
  // then allocate a new node and set pointer from last node to the
  // new end
  else{
    Node<T> * curNode = start;
    for (int i=1; i<mySize; i++){
      curNode = curNode->next;
    }
    Node<T> * newNode = new Node<T> (value);
    curNode->next = newNode;
    mySize++;
  }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  // if the index is zero insert at the start.
  if (j == 0)
    {
      insertStart(value);
    }
  // if the index is out of bounds print "invalid index"
  else if((j > (mySize-1)) || (j < 0))
    {
      cout<<"invalid index"<<endl;
    }
  // if the index is valid loop through the list looking for the
  // correct index
  else if ((j > 0) && (j<(mySize)))
    {
      int sentinel = 0;
      // since j != 0 start on 2nd node and use the 1st node as a
      // previous node
      Node<T> * curNode = start->next;
      Node<T> * previousNode = start;
      Node<T> * newNode = new Node<T> (value);
      for (int i=1; (i<(mySize)) && (sentinel != 1); i++){
	// once the index of the current node equals the node we are looking
	// for use the previous node and current node to add in a new node.
	if (i == j)
	    {
	      newNode->next = curNode;
	      previousNode->next = newNode;
	      sentinel = 1;
	    }
	// otherwise continue iterating curNode and previousNode
	else
	  {
	    cout<<i<<endl;
	    curNode = curNode->next;
	    previousNode = previousNode->next; 
	  }
      }
      // add 1 to mySize
      mySize++;
    }
  // otherwise print invalid index
  else
    {
      cout<<"Invalid index"<<endl;
    }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  // if the list has nodes then delete first node
  if (mySize > 0){
    // save pointer to start for later deallocation
    Node<T> *tempNode = start;
    // set pointer to start to start.next
    start = start->next;
    // deallocate old start from memory
    delete tempNode;
    // subtract 1 from mySize
    mySize--;
  }
  // otherwise print error
  else{
    cout<<"invalid because no start to list."<<endl;
  }
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node<T> *curNode = start;
  // if only one node in the list deallocate the start node
  if (mySize == 1){
    delete start;
    start = nullptr;
  }
  // if more than one node iterate to last node then deallocate it
  else if (mySize > 1){  
    for (int i=1; i<mySize-1; i++){
      curNode = curNode->next;
    }
    Node<T> *tempNode = curNode->next;
    curNode->next = nullptr;
    delete tempNode;
    mySize--;
  }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  // if index passed is zero use removeStart function
  if (j == 0){
    removeStart();
  }
  // if index is the last index in the list use removeEnd function
  else if (j == (mySize-1)){
    removeEnd();
  }
  // if index is between 0 and the end of the list then loop to index
  else if ((j < (mySize-1)) && (j > 0))
    {
      // create pointer to current node and loop until the next node is index j
      Node<T> *curNode = start;
      for (int i=1; i<(j); i++){
	curNode = curNode->next;
      }
      // create a tempNode to hold the pointer of node at index j
      Node<T> *tempNode = curNode->next;
      // set curNode.next to curNode.next.next to skin node at index j
      curNode->next = curNode->next->next;
      // deallocate the node at the address pointed to by tempNode
      delete tempNode;
      // subtract one from mySize
      mySize--;
    }
  // otherwise print "invalid index"
  else {
    cout<<"invalid index"<<endl;
  }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  // loop to the last node in the list
  Node<T> *curNode = start;
  for (int i=1; i<mySize; i++){
    curNode = curNode->next;
  }
  // return the value of the last node
  return curNode->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  // loop until the node at index j
  Node<T> *curNode = start;
  for (int i=0; i<j; i++){
      curNode = curNode->next;
    }
  // return the value of that node
  return curNode->value;
}


//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  // create curNode for looping through the list and curPos for returning an index.
  Node<T> *curNode = start;
  int curPos = 0;
  // loop through entire list and check if any node.value equals the key
  for (int i=1; i<mySize; i++){
    // if a node does equal the key return the current position variable
    if (curNode->value == key)
      {
	return curPos;
      }
    curNode = curNode->next;
    curPos++;
  }
  // if key not found return -1
  return -1;
}
