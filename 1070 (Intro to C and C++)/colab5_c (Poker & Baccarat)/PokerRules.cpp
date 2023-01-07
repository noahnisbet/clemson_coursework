/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

PokerRules.cpp file that defines the functions prototyped in the PokerRules
header file.
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AnalyzeHand.h"
#include "Card.h"
#include "PokerRules.h"

using namespace std;

/*
Here I define the abstract function prototyped in AnalyzeHand.
This function uses the functions that check if the hand contains a pair, two pair
, straight, etc. and returns true if it contains something.
 */
bool PokerRules::isWon(){
  if (pair()){
    return true;
  }  
  if (twoPairs()){
    return true;
  }
  if (threeOfAKind()){
    return true;
  }
  if (fourOfAKind()){
    return true;
  }
  if (straight()){
    return true;
  }
  if (flush()){
    return true;
  }
  
  return false;
}

/*
This function checks if hand1 contains a pair
returns true if so false if not
 */
bool PokerRules::pair(){

  vector<Card> hand = hand1;
  // loop over the cards in the hand
  for (long unsigned int i=0; i<hand.size(); i++){
    // for each card in the hand loop over the cards in the hand
    for (long unsigned int j=0; j<hand.size(); j++){
      // if the loops are on different cards and the face values are the same return true
      if (i != j){
        if (hand[i].curFace == hand[j].curFace){
	  return true;
	}}}}
  // return false if no pair is found.
  return false;
}

/*
This function checks if hand1 contains a two pair
returns true if so false if not
 */
bool PokerRules::twoPairs(){

  vector<Card> hand = hand1;
  
  int firstPair1;
  int firstPair2;
  int sentinel = 0;

  // check if there is a pair using the same strategy as the pair function
  for (long unsigned int i=0; i<hand.size(); i++){
    for (long unsigned int j=0; j<hand.size(); j++){
      // now check if the cards in the hand are different have the same face value
      // and another pair hasn't already been found enter the if statement.
      if (i != j){
	if ((hand[i].curFace == hand[j].curFace) && (sentinel == 0)){
	  // if a pair is found set the values of the indecies in the hand to
	  // first pair 1 and first pair 2.
	  firstPair1 = i;
	  firstPair2 = j;
	  // if a pair is found set the sentinel value to anything other than 0.
	  sentinel = 1;
	}}}}

  // if the sentinel value is not changed return false since a first pair was not found.
  if (sentinel == 0){
    return false;
  }

  // erase the first pair from the deck.
  // erase the bigger index first to not accidentally delete the wrong card.
  if (firstPair1>firstPair2){
    hand.erase(hand.begin()+firstPair1);
    hand.erase(hand.begin()+firstPair2);
  }
  else{
    hand.erase(hand.begin()+firstPair2);
    hand.erase(hand.begin()+firstPair1);
  }

  // use the same strategy as the pair function to see if a pair still
  // exists in the hand. If so return true.
  for (long unsigned int i=0; i<hand.size(); i++){
    for (long unsigned int j=0; j<hand.size(); j++){
      if (i != j){
	if (hand[i].curFace == hand[j].curFace){
          return true;
        }}}}

  // return false if a second pair is not found.
  return false;
}

/*
This function checks if hand1 contains a three of a kind
returns true if so false if not
 */
bool PokerRules::threeOfAKind(){

  vector<Card> hand = hand1;

  // this strategy would be inefficient on a larger scale. However only 5 cards in deck
  // so I don't see a problem in using an inefficent way.
  
  // loop over the cards in the hand
  for (long unsigned int i=0; i<hand.size(); i++){
    // for every card in the hand loop over the cards in the hand
    for (long unsigned int j=0; j<hand.size(); j++){
      // for every card looped over in the second loop loop over all cards in hand.
      for (long unsigned int k=0; k<hand.size(); k++){
	// if all the card in the current iteration are different
	// check if all of the face values are the same
	// if so return true
	if ((i != j) && (i != k) && (k != j)){
	  if ((hand[i].curFace == hand[j].curFace) &&
	      (hand[k].curFace == hand[j].curFace) &&
	      (hand[i].curFace == hand[k].curFace)){
	    return true;
	  }}}}}

  // if no three of a kind is found return false.
  return false;
}

/*
This function checks if hand1 contains a four of a kind
returns true if so false if not
 */
bool PokerRules::fourOfAKind(){

  vector<Card> hand = hand1;

  // this strategy would be inefficient on a larger scale. However only 5 cards in deck
  // so I don't see a problem in using an inefficent way.
  
  // loop over every card in the hand.
  for (long unsigned int i=0; i<hand.size(); i++){
    // for every card in the deck loop over the deck again
    for (long unsigned int j=0; j<hand.size(); j++){
      // for every card in the 2nd loop loop over the cards again
      for (long unsigned int k=0; k<hand.size(); k++){
	// for every card in the 3rd loop loop over the cards again
	for (long unsigned int q=0; q<hand.size(); q++){
	  // if all the card in the current iteration are different
	  // check if all of the face values are the same
	  // if so return true
	  if ((i != q) && (i != k) && (i != j) &&
	      (j != q) && (j != k) && (k != q)){
	    if ((hand[i].curFace == hand[q].curFace) &&
		(hand[i].curFace == hand[k].curFace) &&
		(hand[i].curFace == hand[j].curFace) &&
		(hand[j].curFace == hand[q].curFace) &&
		(hand[j].curFace == hand[k].curFace) &&
		(hand[k].curFace == hand[q].curFace)){
	      return true;
	    }}}}}}

  // If no four of a kind is found return false.
  return false;
}

/*
This function checks if hand1 contains a straight using recursion.
I made a seperate function for this since recursion would require a parameter.
returns true if so false if not
 */
bool PokerRules::straightRecursion(vector<Card> hand){

  // base case. If only 1 card remains in the hand return true.
  if (hand.size() == 1){
    return true;
  }

  // below I get the largest face value in the hand and store the
  // value of the face and the index of that face in the respective
  // variables below.
  int biggestFaceVal = -1;
  int biggestFaceValIdx;
  for (long unsigned int i=0; i<hand.size(); i++){
    if (hand[i].curFace > biggestFaceVal){
      biggestFaceVal = hand[i].curFace;
      biggestFaceValIdx = i;
    }}

  // loop over the cards in the hand
  for (long unsigned int i=0; i<hand.size(); i++){
    // if a card's face value equals 1 minus the largest face value
    // erase the largest face value from the hand and recursively repeat this
    // function until 1 card is left in the hand. If that happens return true.
    if (hand[i].curFace == (biggestFaceVal-1)){
      hand.erase(hand.begin()+biggestFaceValIdx);
      return straightRecursion(hand);
    }}

  // if a straight is not found return false.
  return false;
}

/*
This function checks if hand1 contains a straight
returns true if so false if not
this function uses the straightRecursion function.
 */
bool PokerRules::straight(){
  return straightRecursion(hand1);
}

/*
This function checks if hand1 contains a straight
returns true if so false if not
*/
bool PokerRules::flush(){

  vector<Card> hand = hand1;
  
  // get the suit of the first card in the hand.
  int suit = hand[0].curSuit;

  // loop over all the cards in the hand.
  for(long unsigned int i=0; i<hand.size(); i++){
    // if any card in the hand is not of the same suit as the first card
    // return false
    if (hand[i].curSuit != suit){
      return false;
    }}

  // if all the cards have the same suit return true.
  return true;
}
