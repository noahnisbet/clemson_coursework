/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

AnalyzeHand.cpp file that defines the functions prototyped in the AnalyzeHand header file
*/

#include "AnalyzeHand.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Takes in no input and returns a string that tells what cards are in the player hand, hand1.
 */
string AnalyzeHand::toString(void){
  string returnString = "[";

  // loop over number of cards in hand1
  for(int i=0; i<numOfCards1; i++){
    // if the card is the last card in the hand add to returnString without a comma
    if (i == numOfCards1-1){
      returnString += hand1[i].toString();
    }
    // else add to returnString with a comma.
    else{
    returnString += hand1[i].toString()+", ";
    }
  }
  // add bracket and return returnString.
  returnString += "]";
  return returnString;
}

/*
AnalyzeHand constructor, takes in a vector of Cards
Sets numOfCards1 to size of vector and sets hand1 to inputHand.
*/
AnalyzeHand::AnalyzeHand(vector<Card> inputHand){
  numOfCards1 = inputHand.size();
  hand1 = inputHand;
}

/*
AnalyzeHand constructor2, takes in two vectors of Cards
Sets numOfCards1 to size of inputHand1 and sets hand1 to inputHand1.
Sets numOfCards2 to size of inputHand2 and sets hand2 to inputHand2.
*/
AnalyzeHand::AnalyzeHand(vector<Card> inputHand1,
			 vector<Card> inputHand2){
  numOfCards1 =	inputHand1.size();
  hand1	= inputHand1;
  numOfCards2 =	inputHand2.size();
  hand2 = inputHand2;
}
