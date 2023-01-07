/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071: section 2

DeckOfCards.h file that defines the Card class. This file connects DeckOfCards.cpp
 and Driver.cpp
*/
#include <vector>
#include "Card.h"
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

/*
DeckOfCards class that will represent a deck of cards and
will include functions to manipulate the deck.
 */
class DeckOfCards{
 public:
  //constructor
  DeckOfCards();
  //shuffle deck
  void shuffle(void);
  // deal top card
  Card dealCard(void);
  // deck if more cards exists.
  bool moreCards(void);

 private:
  //Private member variables
  vector<Card> deck;
  int currentCard;

};
#endif
