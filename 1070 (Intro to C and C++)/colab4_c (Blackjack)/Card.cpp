/*
Noah Nisbet
Colab 4C
Byte Club
October 23, 2022
CPSC 1071, section 2

Card.cpp file that defines the functions prototyped in the Card header file
 */
#include <iostream>
#include "Card.h"
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Defining the static arrays that are used in the function toString
const string Card::FacesAsString[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string Card::SuitsAsString[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

/*
Default Card constructor, takes in no arguements.
The default card is a Ace of Hearts
No return for constructors
 */
Card::Card(){
  curFace = (Card::Faces) (0);
  curSuit = (Card::Suits) (0);
}
/*
Card constructor, takes in two ints one for the face and one for the suit.
The integer corresponds to values in enum.
I cast the integer to the corresponding enum types.
No return for constructors
 */
Card::Card(int Face, int Suit){
  curFace = (Card::Faces) (Face-1);
  curSuit = (Card::Suits) (Suit-1);
}

/*
Does not take in an arguement.
Returns the current value stored in the Card class as a string.
Cast the curFace and curSuit enum values to ints and index into the static arrays with those values.
return the concatenated string.
 */
string Card::toString(){
  string curString = FacesAsString[int(curFace)] + " Of " + SuitsAsString[int(curSuit)];
  return curString;
}

