/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

CipherAdvanced.cpp file that defines the functions prototyped in simulation header file.
 */

#include "CipherAdvanced.h"
#include "Cipher.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
Takes in a string with spaces
Splits the string on whitespace
returns a vector of each word
 */
vector<string> CipherAdvanced::splitString(string input){
  vector<string> inputSplit;
  string temp = "";

  for(int i=0; i<input.length(); i++){
    if(input[i] != ' '){
      temp+=input[i];
    }
    else{
      inputSplit.push_back(temp);
      temp = "";
    }}
  inputSplit.push_back(temp);
  for(int i=0; i<inputSplit.size(); i++){
    if(inputSplit[i] == ""){
      inputSplit.erase (inputSplit.begin()+i);
    }
  }
  return inputSplit;
}

/*
Takes in a key with an encoding for each letter and a pattern vector
Checks if the pattern repeats throughout the entire key encoding
returns a boolean if the pattern repeats the entire time or not. 
 */
bool CipherAdvanced::checkPatternRepeats(vector<string> key, vector<string> pattern){
  for(int i=0; i<key.size(); i++){
    if (key[i].compare(pattern[i%pattern.size()]) != 0){
      return false;
    }
  }
  return true;
}

/*
Takes in an encoding from each letter in the input string to a word of the same length.
returns a vector of patterns (with maximum length of 5).
Does this by finding when a number matches the first number in the encoding.
The numbers between from the first index to the index where a match was found is assumed to be a pattern.
If that pattern repeats throughout the entire string add that to the valid keys vector.
Then return the valid keys vector.
 */
vector<string> CipherAdvanced::allRepeatingKeys(vector<string> key){
  string first;
  string curKey;
  vector<string> keys;
  vector<string> validKeys;
  vector<string> curPattern;
  string returnPattern;
  
  for(int i=0; i<key.size(); i++){
    curKey = key[i];
    first = splitString(curKey)[0];
    keys = splitString(curKey);
    for(int j=1; j<keys.size(); j++){
      if((j<6) && (keys[j].compare(first)==0)){
	curPattern.clear();
	for(int k=0; k<j; k++){
	  curPattern.push_back(keys[k]);
	}
	if (checkPatternRepeats(keys, curPattern)){
	  returnPattern="";
	  for(int n=0; n<curPattern.size(); n++){
	    returnPattern+=" "+curPattern[n];
	  }
	  validKeys.push_back(returnPattern);
	}
      }
    }
  }

  return validKeys;
}
/*
Checks if two keys match.
This is defferent then just checking if two keys are equivelent because one key
can  be a substring of the other key, but order matters.
Returns boolean for if the keys could match or not.
 */
bool CipherAdvanced::checkKeysMatch(string key1, string key2){
  int len1 = key1.length();
  int len2 = key2.length();
  
  if(len1 < len2){
    for(int i=0; i<len1; i++){
      if(key1[i]==key2[i]){
        return false;
      }}}
  else{
    for(int i=0; i<len2; i++){
      if(key1[i]==key2[i]){
	return false;
      }}}
  return true;
}

/*
takes in an encoded string and a string of the same length and
returns a string of the keys that could shift the encoded string to the decoded string.
 */
string CipherAdvanced::getInputEncodingKey(string encoded, string decoded){
  int len = encoded.length();
  vector<string> keys;
  int difference;
  string temp;
  
  for(int i=0; i<len; i++){
    difference = int(tolower(decoded[i])) - int(tolower(encoded[i]));
    while(difference < 0){
      difference += 26;
    }
    temp = to_string(difference);
    if(temp.length() == 1){
      temp = "0"+temp;
    }
    keys.push_back(temp);
  }

  string returnKey = "";
  for(int i=0; i<keys.size(); i++){
    returnKey+=" "+keys[i];
  }

  return returnKey;
}

/*
takes in an encoded word and prints out all possible encodings for that word.
Uses the above functions to accomplish this.
Simple steps:
#1 get all keys that map from the input to a real word of the same length
#2 check if the keys have a repition of numbers with a maximum repeating pattern 
of 5 numbers
returns nothing as it is a void function.
 */
void CipherAdvanced::unknownScramble(string input){
  ifstream words;
  words.open("/usr/share/dict/words");
  string line;
  int counter = 0;
  vector<string> encodings;
  string curEncoding;
  vector<string> encodingsCleaned;
  string encoding;
  Cipher decoder;
  int array[encodingsCleaned.size()];
  vector<string> cleanedKeys;
  vector<string> finalWords;

  // Getting encodings / keys for each word of same length
  while(getline(words, line)){
    if(input.length() == line.length()){
      encoding = getInputEncodingKey(input,line);
      encodings.push_back(encoding);
    }
  }
  
  string alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

  // If the input is only length one the entire alphabet is valid.
  if (input.length()>1){
    encodingsCleaned = allRepeatingKeys(encodings);
    if(encodingsCleaned.size()==0){
      cout<<"NO POSSIBILITIES EXIST";
      return;
    }
    
    for (int i=0; i<encodingsCleaned.size(); i++){
      cleanedKeys = splitString(encodingsCleaned[i]);
      int array[cleanedKeys.size()];
      for (int j=0; j<cleanedKeys.size(); j++){
	array[j] = stoi(cleanedKeys[j])*-1;
	cout<<stoi(cleanedKeys[j])*-1<<" ";
      }
      cout<<endl;
      decoder.setCipher(cleanedKeys.size(), array);
      cout<<decoder.decodeMessage(input)<<endl;
    }
  }
  // else use the repeating pattern method.
  else{
    for(int i=0; i<26; i++){
      cleanedKeys = splitString(getInputEncodingKey(input,alphabet[i]));
      int array[cleanedKeys.size()];
      for (int j=0; j<cleanedKeys.size(); j++){
        array[j] = stoi(cleanedKeys[j])*-1;
        cout<<stoi(cleanedKeys[j])*-1<<" ";
      }
      cout<<endl;
      decoder.setCipher(cleanedKeys.size(), array);
      cout<<decoder.decodeMessage(input)<<endl;
    }
  }
  
  return;
}

