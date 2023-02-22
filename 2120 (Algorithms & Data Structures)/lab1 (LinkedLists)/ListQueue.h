/*
 * Name: Noah Nisbet
 * Date Submitted: January 26, 2023
 * Lab Section: 004
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

//This class represents a Queue implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListQueue{

 private:
  List<T> queue;

 public:
  ListQueue();
  ~ListQueue();
  int size();
  bool empty();
  void enqueue(T);
  T dequeue();
  //Print the name and this ListQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    queue.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListQueue by initializing this ListQueue's instance variables
template <class T>
ListQueue<T>::ListQueue(){
  // Nothing to be done here.
}

//Destroy all nodes in this ListQueue to prevent memory leaks
template <class T>
ListQueue<T>::~ListQueue(){
  // Nothing to be done here.
}

//Return the size of this ListQueue
template <class T>
int ListQueue<T>::size(){
  // simply call the size function from List
  return queue.size();
}

//Return true if this ListQueue is empty
//Otherwise, return false
template <class T>
bool ListQueue<T>::empty(){
  // simply call the empty function from List
  return queue.empty();
}

//Create a new node with value, and insert that new node
//into this ListQueue in its correct position
template <class T>
void ListQueue<T>::enqueue(T value){
  // FILO method, so insert at the end and only remove from the front.
  queue.insertEnd(value);
}

//Dequeue an element from the queue.
//Note that here that means both removing it from the list
//AND returning the value
template <class T>
T ListQueue<T>::dequeue(){
  // FILO method, so insert at the end and only remove from the front.
  T last = queue.getFirst();
  queue.removeStart();
  return last;
}
