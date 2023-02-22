/*
Noah Nisbet
Review 1
January 22, 2023

review.h file that prototypes functions to be implemented in review.cpp
 */

#pragma once

#include <string>
#include <vector>


int add(int a, int b);
void ReadStdIn();
int WriteOut(std::string output);
int WriteOut(int output);
int WriteOut(double output);
std::vector <int> InitializeArray(int size);
void ReadStdIn2();
void ReadWrite();
void LoopThrough(double * data, int size);
int Fibonacci(int a);
