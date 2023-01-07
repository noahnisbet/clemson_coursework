/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

Cipher.h file that connects the driver and the Cipher class
*/
#include <string>
#include <iostream>
#include "Queue.h"
#include <vector>

using namespace std;

#ifndef CIPHER_H
#define CIPHER_H

// Cipher class
class Cipher{
private:
  // Private member variables
  Queue keyQueue;
  int size;
  vector<int> keyVector;
  int *cipherPtr;
  const char ALPHABET[26] = {'a','b','c','d','e','f','g','h','i','j','k',
			   'l','m','n','o','p','q','r','s','t','u','v',
			   'w','x','y','z'};
public:
  // default constructor
  Cipher();
  // setSipher, takes in an int for the size of the key and a pointer to the start of a pointer
  // array holding the keys.
  void setCipher(int, int*);
  // returns the pointer to the beginning of the pointer array holding the keys
  int* getCipher();
  // encodes an input string using the key set.
  string encodeMessage(string);
  // decodes an input string using the key set.
  string decodeMessage(string);
  // resets the queue back to the default starting position.
  void resetQueue();
  
};
#endif
