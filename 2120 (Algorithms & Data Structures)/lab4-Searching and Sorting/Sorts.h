/*
 * Name: Noah Nisbet
 * Date Submitted: Feb 20, 2023
 * Lab Section: 004
 * Assignment Name: Lab 4 Searching and Sorting
 */

#pragma once

#include <vector>
#include <stdlib.h>
#include <time.h>

/*
 * Helper function for swapping values in vector
 * used in quickSort 
 */
template <class T>
void swap(std::vector<T> &lst, int idx1, int idx2){
  T temp = lst[idx2];
  lst[idx2] = lst[idx1];
  lst[idx1] = temp;
}

/*
 * Merge Sort function
 * Implements the merge sort algorithm recursively
 */
template <class T>
std::vector<T> mergeSort(std::vector<T> lst){

  // base case
  // if the vector is of size 1 return the vector
  if (lst.size() <= 1){
    return lst;
  }

  // split the vector into halves
  std::vector<T> half1;
  std::vector<T> half2;
  int middle = static_cast<int> (lst.size()/2);

  for (int i=0; i<middle; i++)
    half1.push_back(lst[i]);
  
  for (int i=middle; i<lst.size(); i++)
    half2.push_back(lst[i]);

  // recursively call mergeSort on each half
  half1 = mergeSort(half1);
  half2 = mergeSort(half2);

  // big vector for combining the smaller sorted vectors
  std::vector<T> mergingTime;

  // combine the smaller vectors using while loops
  int j=0;
  int i=0;
  while((i < half1.size()) && (j<half2.size()))
    {
      if (half1[i] < half2[j])
	{
	  mergingTime.push_back(half1[i]);
	  i++;
	}
      else if (half1[i] >= half2[j])
	{
	  mergingTime.push_back(half2[j]);
	  j++;
	}
    }

  // add in the leftover elements
  while(i < half1.size())
    {
       mergingTime.push_back(half1[i]);
       i++;
    }

  while(j < half2.size())
    {
       mergingTime.push_back(half2[j]);
       j++;
    }

  // return 
  return mergingTime;
}

/*
 * quickSort function
 * Implementation of the quickSort algorithm recursively
 */
template <class T>
std::vector<T> quickSort(std::vector<T> lst){

  // seed the random class
  srand(time(NULL));

  // base case
  // if the size of the vector is zero return
  if (lst.size() <= 1)
    return lst;

  // create pivotIndex and pivotValue using rand()
  int pivotIndex = rand() % lst.size();
  T pivotValue = lst[pivotIndex];

  // swap the pivot with the first value
  swap(lst, 0, pivotIndex);
  pivotIndex = 0;

  // swap elements with pivotIndex if the value is less than the pivot value
  for (int i=1; i<lst.size(); i++)
    {
      if (lst[i] < pivotValue)
        {
	  pivotIndex++;
	  swap(lst, i, pivotIndex);
	}
    }

  // swap the pivot into the pivot index
  swap(lst, 0, pivotIndex);

  // split the big vector into halves based on the location of the pivot value
  std::vector<T> half1;
  for (int i=0; i<pivotIndex; i++)
    half1.push_back(lst[i]);

  std::vector<T> half2;
  for (int i=pivotIndex+1; i<lst.size(); i++)
    half2.push_back(lst[i]);

  // recursively sort the smaller halves
  half1 = quickSort(half1);
  half2 = quickSort(half2);

  // combine the halves back together
  half1.push_back(lst[pivotIndex]);

  for (int i=0; i<half2.size(); i++)
    half1.push_back(half2[i]);

  // return
  return half1;
}
