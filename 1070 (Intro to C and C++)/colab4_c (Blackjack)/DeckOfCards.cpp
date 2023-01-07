/*
Noah Nisbet
Colab 4C
Byte Club
October 23, 2022
CPSC 1071, section 2

DeckOfCards.cpp file that defines the functions prototyped in the DeckOfCards header file
*/
#include "Card.h"
#include "DeckOfCards.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

/*
DeckOfCards constructor, takes in no arguements and returns nothing.
Initializes the deck of 52 cards in order. Using the Card class.
 */
DeckOfCards::DeckOfCards(){
  currentCard = 1;
  for (int i=0; i<13; i++){
    for (int j=0; j<4; j++){
      Card curCard(i+1,j+1);
      deck.push_back(curCard);
    }
  }
}

/*
Shuffle function, returns nothing and takes no arguments
Uses random numbers to shuffle the current deck of cards vector
Loops over the deck and swaps each card with a random card in the deck.
 */
void DeckOfCards::shuffle(){
  int randomNumber;
  Card temp(0,0);
  srand (time(NULL));
  for (int i=0; i<int(deck.size()); i++){
    randomNumber = rand() % int(deck.size());
    temp = deck.at(i);
    deck.at(i) = deck.at(randomNumber);
    deck.at(randomNumber) = temp;
  }
}

/*
Deal Card function, takes no arguements and returns a Card object.
Returns the "top" card on the deck (the first index on the deck vector).
So I remove the top Card from the deck and return it.
 */
Card DeckOfCards::dealCard(){
  currentCard++;
  Card toDeal = deck.at(0);
  deck.erase(deck.begin());
  return toDeal;
}

/*
moreCards function, takes no arguments and returns a boolean.
Checks if the deck vector has a length greater than 0. If so return true
else return false.
 */
bool DeckOfCards::moreCards(){
  if (deck.size() > 0){
    return true;
  }
  else{
    return false;
  }
}
