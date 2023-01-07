/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

Cipher.cpp file that defines the functions prototyped in the
Cipher.h file.
*/
#include <iostream>
#include <string>
#include "Cipher.h"
#include "Queue.h"
#include <vector>

using namespace std;

// constuctor sets default key to 1,2,3,4
Cipher::Cipher(){
  int input[4] = {1,2,3,4};
  setCipher(4,input);
}
/*
  resetQueue uses the cipherPtr pointer array to reset the queue
  this is needed because sometimes the queue is out of order if you
  need to decode right after encoding
  returns and takes in no input.
*/
void Cipher::resetQueue(){
  keyQueue.clear();
  for (int i=0;i<size; i++){
    keyQueue.enqueue(cipherPtr[i]);
  }
}

/*
Takes in an array of ints and the size of the input array.
fills the queue and defines the pointer array, where the head of that 
array is cipherPtr.
returns nothing. 
*/
void Cipher::setCipher(int inputSize, int input[]){
  size = inputSize;
  keyQueue.clear(); 
  cipherPtr = new int[size];
  for (int i=0;i<size; i++){
    cipherPtr[i] = input[i];
    keyQueue.enqueue(input[i]);
  }
}

/*
returns the cipherPtr member variable.
This is the head to the pointer array that stores the keys
for the cipher.
 */
int* Cipher::getCipher(){
  return cipherPtr;
}

/*
takes an input string and uses the key queue to encode the messages
once the entire input string is cleaned then encoded it returns
an encoded string.
 */
string Cipher::encodeMessage(string in){
  int len = in.length();
  int curCipherMovement = 0;
  int curInputValue;
  char curChar;
  string newin = "";

  // reset the queue to ensure correct order.
  resetQueue();

  // clean input string
  for (int i=0; i<len; i++){
    bool valid = false;
    curChar = tolower(in[i]);
    for (int j=0; j<26; j++){
      if (curChar == ALPHABET[j]){
	valid = true;}}
    if (valid){
      newin+=curChar;}}
  in = newin;
  len = in.length();

  // encode string using queue.
  string out = "";
  for (int i=0; i<len; i++){

    curInputValue = int(in[i]) - 97;
    keyQueue.dequeue(curCipherMovement);
    keyQueue.enqueue(curCipherMovement);
    
    while (curCipherMovement < 0){
      curCipherMovement+=26;}
    out += ALPHABET[(curCipherMovement+curInputValue)%26]; 
  }
  // return encoded string
  return out;
}

/*
Takes an input string and uses the key Queue to decode the input.
Simply uses the same strategy above but the keys are multiplied by 
negative 1. This essentially does the reverse of the encoding.
 */
string Cipher::decodeMessage(string in){
  int len = in.length();
  int curCipherMovement = 0;
  int curInputValue;
  char curChar;
  string newin = "";

  //reset queue to ensure correct order.
  resetQueue();

  // clean input string
  for (int i=0; i<len; i++){
    bool valid = false;
    curChar = tolower(in[i]);
    for (int j=0; j<26; j++){
      if (curChar == ALPHABET[j]){
        valid = true;}}
    if (valid){
      newin+=curChar;}}
  in = newin;
  len = in.length();

  // decode the string
  string out = "";
  for (int i=0; i<len; i++){
    curInputValue = int(in[i]) - 97;
    keyQueue.dequeue(curCipherMovement);
    keyQueue.enqueue(curCipherMovement);
    curCipherMovement *=-1;
    while (curCipherMovement < 0){
      curCipherMovement+=26;}
    out += ALPHABET[(curCipherMovement+curInputValue)%26];
  }

  //return decoded string.
  return out;
}
