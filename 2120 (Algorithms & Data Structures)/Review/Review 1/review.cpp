/*
Noah Nisbet
Review 1
January 22, 2023

review.cpp file that implements the functions created in review.h
 */

#include "review.h"
#include "string"
#include "iostream"
#include "vector" 

using namespace std;

int Fibonacci(int a)
{
  if (a==1){return 1;}
  if (a==0){return 0;}
  return Fibonacci(a-2)+Fibonacci(a-1);
}
