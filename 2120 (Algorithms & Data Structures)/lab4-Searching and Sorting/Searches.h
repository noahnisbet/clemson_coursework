/*
 * Name: Noah Nisbet
 * Date Submitted: Feb 20, 2023
 * Lab Section: 004
 * Assignment Name: Lab 4 Searching and Sorting
 */

#pragma once

#include <vector>

/*
 * linearSearch function
 * implements a simple linear search
 */
template <class T>
int linearSearch(std::vector<T> data, T target){
  // loop over data, check if current element is target, return if so
  for (int i=0; i<data.size(); i++)
    {
      if (data[i] == target)
	{
	  return i;
	}
    }

  // otherwise return -1
  return -1;
}


/*
 * binarySeach function
 * implements the binarySeach algorithm
 */
template <class T>
int binarySearch(std::vector<T> data, T target){

  // find half top and bottom indicies
  int half = data.size() / 2;
  int top = data.size();
  int bottom = 0;
  T curVal = data[half];

  // while the curVar isnt the target split the data in half.
  while (curVal != target){
    // if the target is greater than curVar go in the top split
    if (target > curVal)
      {
	bottom = half;
	// if the before half equals the half after split return -1
	// update half otherwise
	if (half != (top+bottom) / 2)
	  half = (top+bottom) / 2;
	else
	  return -1;
      }
    // otherwise go in bottom split
    else
      {
	top = half;
	// if the before half equals the half after split return -1
        // update half otherwise
	if (half != (top+bottom) / 2)
	  half = (half + bottom) / 2;
	else
	  return -1;
      }
    // update curVal
    curVal = data[half];
  }
  return half;
}
