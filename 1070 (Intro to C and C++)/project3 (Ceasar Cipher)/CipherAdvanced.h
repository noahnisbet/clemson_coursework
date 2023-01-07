/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

CipherAdvanced.h file that connects the driver and the CipherAdvanced class
*/
#include <string>
#include <iostream>
#include "Queue.h"
#include "Cipher.h"
#include <vector>

using namespace std;

#ifndef CIPHERADVANCED_H
#define CIPHERADVANCED_H

/*
CipherAdvanced class which is a child to the Cipher class.
 */
class CipherAdvanced : public Cipher{

 public:
  // Unknown scramble takes in an encoded string and prints potential decoded words
  void unknownScramble(string);
  // Splits a string by whitespace
  vector<string> splitString(string);
  // checks if the key found in allRepeatingKeys repeats throughout an entire encoding.
  bool checkPatternRepeats(vector<string>, vector<string>);
  // Gets all keys that repeat from a vector of keys (maximum size of key is 5) 
  vector<string> allRepeatingKeys(vector<string>);
  // Checks if two keys could be the same.
  bool checkKeysMatch(string, string);
  // gets the encoding that maps the input string to a word of the same length
  string getInputEncodingKey(string, string);
};

#endif
