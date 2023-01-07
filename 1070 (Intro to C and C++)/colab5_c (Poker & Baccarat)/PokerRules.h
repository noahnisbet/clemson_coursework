/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

PokerRules header file that defines the PokerRules class
PokerRules class inherits the AnalyzeHand class.
*/
#include <string>
#include <iostream>
#include <vector>
#include "AnalyzeHand.h"
#include "Card.h"

#ifndef POKERRULES_H
#define POKERRULES_H

using namespace std;

// Naming class PokerRules and inheriting the AnalyzeHand class
class PokerRules:public AnalyzeHand{
 public:
  // constructor takes in a vectors of cards
  // Then it passes the hand into the AnalyzeHand constructor.
  PokerRules(vector<Card> hand): AnalyzeHand(hand){};
  // redefining the isWon function from AnalyzeHand with the rules of Poker.
  bool isWon();
  // function that checks if the hand contains a pair and returns a boolean if so
  bool pair();
  // function that checks if the hand contains a two pair and returns a boolean if so
  bool twoPairs();
  // function that checks if the hand contains a three of a kind and returns a boolean if so
  bool threeOfAKind();
  // function that checks if the hand contains a four of a kind and returns a boolean if so
  bool fourOfAKind();
  // function that checks if the hand contains a straight and returns a boolean if so
  bool straight();
  // helper function to straight that uses recursion to check if the hand contains
  // a straight.
  bool straightRecursion(vector<Card>);
  // function that checks if the hand contains a flush and returns a boolean if so
  bool flush();
};

#endif
