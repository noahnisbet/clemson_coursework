/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071: section 2

Card.h file that defines the Card Class and connects Card.cpp and Driver.cpp
*/
#include <string>
#include <iostream>
#ifndef CARD_H
#define CARD_H

using namespace std;

/*
Card class that represents a card in a normal deck.
 */
class Card{
 public:
  //constructor
  Card();
  //copy constructor
  Card(int, int);
  //return a string that represents the current card.
  string toString(void);
private:
  // enums
  enum Faces {Ace,Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
  enum Suits {Hearts, Diamonds, Clubs, Spades};
  // static arrays used in toString.
  static const string FacesAsString[];
  static const string SuitsAsString[];
public:
  Card::Suits curSuit;
  Card::Faces curFace;

};
#endif
