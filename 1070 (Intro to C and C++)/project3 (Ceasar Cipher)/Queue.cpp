/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

Queue.cpp file that defines the prototyped functions in Queue.h
This file was copied from the textbook.
*/

#include "Queue.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//************************
// Constructor. *
//************************
Queue::Queue()
{
  front = nullptr;
  rear = nullptr;
}

//************************
// Destructor. *
//************************
Queue::~Queue()
{
  QueueNode * garbage = front;
  while (garbage != nullptr)
    {
      front = front->next;
      garbage->next = nullptr;
      delete garbage;
      garbage = front;
    }
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void Queue::enqueue(int num)
{
  if(!isFull()){
    if (isEmpty())
      {
	front = new QueueNode(num);
	rear = front;
	counter++;
      }
    else
      {
	rear->next = new QueueNode(num);
	rear = rear->next;
	counter++;
      }
  }
}
//**********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//**********************************************
void Queue::dequeue(int &num)
{
  QueueNode *temp = nullptr;
  if (!isEmpty()){
      num = front->value;
      temp = front;
      front = front->next;
      counter--;
      delete temp;
    }
}
//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool Queue::isEmpty() const
{
  if (front == nullptr)
    return true;
  else
    return false;
}

bool Queue::isFull() const
{
  if (counter > 99){
    return true;
  }
  return false;


}
//********************************************
// Function clear dequeues all the elements *
// in the queue. *
//********************************************
void Queue::clear()
{
  int value; // Dummy variable for dequeue 
  while (!isEmpty())
    dequeue(value);
}
