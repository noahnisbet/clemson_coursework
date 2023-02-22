/*
 * Noah Nisbet 
 * Queue Implementation Using a Circular Array
 * Feb 17, 2023
 * CPSC 2120
 */

#include "IntegerArrayQueue.h"

/*
 * Enqueue function
 * adds value to circular queue
 */
bool IntegerArrayQueue::enqueue(int value)
{
  // check if the queue is full
  if ((front==back+2) || ((back==(size-2)) && (front==0)))
    return false;

  // check if the queue needs to look around to index 0 of array
  if (back == size-1)
    {
    array[0] = value;
    back = 0;
    }

  // otherwise just increment back and add the value at back+1 in array queue
  else
    {
    array[back+1] = value;
    back++;
    }
  return true;
}

/*
 * Dequeue function
 * removes value from front of queue 
 */
int IntegerArrayQueue::dequeue()
{
  // temp variable for holding the front of the array
  int toReturn = array[front];

  // if the queue is empty return 0
  if ((front==back+1) || ((back==(size-1)) && (front==0)))
    return 0;

  // check if the queue needs to circle back around to index 0
  if (front == size-1)
    front = 0;

  // otherwise increment front
  else
    front++;

  // return the temp variable
  return toReturn;
}
