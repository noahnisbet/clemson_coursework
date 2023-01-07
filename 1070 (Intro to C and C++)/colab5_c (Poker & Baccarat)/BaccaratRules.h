/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

BaccaratRules header file that defines the BaccaratRules class
BaccaratRules class inherits the AnalyzeHand class.
*/
#include <string>
#include <iostream>
#include "AnalyzeHand.h"
#ifndef BACCARATRULES_H
#define BACCARATRULES_H

using namespace std;

// Naming class BaccaratRules and inheriting the AnalyzeHand class
class BaccaratRules : public AnalyzeHand{
 public:
  // constructor takes in two vectors of cards, one for the dealer and one for the player.
  // Then it passes those hands into the AnalyzeHand constructor.
  BaccaratRules(vector<Card> hand1, vector<Card> hand2): AnalyzeHand(hand1, hand2){};
  // dealer to string returns the cards in the dealers hand as a string.
  string dealerToString();
  // redefining the isWon function from AnalyzeHand with the rules of Baccarat.
  bool isWon();
  // helper function for isWon that calculates the Baccarat hand value
  // given two face values.
  int getBaccaratHandValue(int, int);
};
#endif
