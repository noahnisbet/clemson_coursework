/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

BaccaratRules.cpp file that defines the functions prototyped in the BaccaratRules 
header file.
*/
#include <iostream>
#include <string>
#include "BaccaratRules.h"

using namespace std;

/*
dealerToString is the same as the toString method just with hand2 instead of
hand 1.
This function takes no input and returns a string that represents the cards in the
dealer's hand.
 */
string BaccaratRules::dealerToString(){

  string returnString = "[";
  // Loop over the dealers hand
  for(long unsigned int i=0; i<hand2.size(); i++){
    // if it is the last card in the hand don't add a comma after card
    if (i == (hand2.size()-1)){
      returnString+=hand2[i].toString();
    }
    // else add a comma after the card.
    else{
    returnString+=hand2[i].toString()+", ";
    }
  }
  // add end bracket and return
  returnString+="]";
  return returnString;
}

/*
getBaccaratHandValue takes in two integers arguements that represent the face value of 
the cards in a deck.
returns the correct value for the Baccarat hand value according to the rules.
 */
int BaccaratRules::getBaccaratHandValue(int card1, int card2){

  // if the card is jack, queen, or king it has the value 11, 12, and 13 respectively
  // they are of value 10 in the game so here I fix that.
  if(card1>10){
    card1 = 10;
  }
  if(card2>10){
    card2 = 10;
  }

  // add two card values.
  int value = card1 + card2;

  // return value modulus 10 because that gets only the first digit
  return value % 10;
}

/*
Here I define the abstract function prototyped in AnalyzeHand.
This function uses the two hands passed into the constructor and returns
a boolean depending if the player wins based on the rules of Baccarat 
or not.
 */
bool BaccaratRules::isWon(){

  // check if player has a pair.
  if (hand1[0].curFace == hand1[1].curFace){
    cout<<"Player has a pair"<<endl;
  }
  // check if dealer has a pair.
  if (hand2[0].curFace == hand2[1].curFace){
    cout<<"Banker has a pair"<<endl;
  }
  // get respective hand values using getBaccaratHandValue function.
  int playerVal = getBaccaratHandValue(hand1[0].curFace+1, hand1[1].curFace+1);
  int bankerVal = getBaccaratHandValue(hand2[0].curFace+1, hand2[1].curFace+1);

  // check if the player and banker tied
  if(((playerVal == 8) || (playerVal == 9)) && ((bankerVal == 8) || (bankerVal == 9))){
    cout<<"It's a tie"<<endl;
    return false;
  }
  // check if the payer won through natural 8 or 9.
  if(((playerVal == 8) || (playerVal == 9)) && ((bankerVal != 8) || (bankerVal != 9))){
    return true;
  }
  // check if player won
  if(playerVal > bankerVal){
    return true;
  }
  // otherwise the player has lost so return false.
  return false;
}
