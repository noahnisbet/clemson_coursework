/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

AnalyzeHand abstract class. Will be inherited by BacarratRules and PokerRules.
*/
#include <string>
#include <iostream>
#include <vector>
// Including the card class header file.
#include "Card.h"
#ifndef ANALYZEHAND_H
#define ANALYZEHAND_H

using namespace std;

// AnalyzeHand Class
class AnalyzeHand{
  
 public:
  // player hand as vector of Card objects
  // Card objects represent a card in a deck
  vector<Card> hand1;
  // banker hand
  vector<Card> hand2;
  // number of player cards
  int numOfCards1;
  // number of banker cards
  int numOfCards2;
  // constuctor for PokerRules
  AnalyzeHand(vector<Card> inputHand);
  // constructor for BaccaratRules
  AnalyzeHand(vector<Card> inputHand1, vector<Card> inputHand2);
  // prints hand1 in nice format
  string toString(void);
  // abstract function isWon to be defined in child class.
  virtual bool isWon() = 0;
};
#endif
