/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

PlayBaccarat.cpp file that uses the BaccaratRules class and the DeckOfCards class
to simulate a given number of games.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include "BaccaratRules.h"
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

int main(){
  int numRounds;
  cout<<"******* Welcome to Baccarat *******"<<endl;
  cout<<endl;
  // get the number of rounds the user wants to play and assign it to numRounds.
  cout<<"How many rounds of Baccarat would you like to play? ";
  cin>>numRounds;
  cout<<endl;
  cout<<"Shuffling Deck..\n"<<endl;

  // create the DeckOfCards object and shuffle the deck.
  DeckOfCards deck;
  deck.shuffle();

  // loop over the game code numRounds times.
  for (int i=0; i<numRounds; i++){

    cout<<"Game "<<i+1<<":"<<endl;

    // deal the four cards for the two hands
    Card card1 = deck.dealCard();
    Card card2 = deck.dealCard();
    Card card3 = deck.dealCard();
    Card card4 = deck.dealCard();

    // create the two hands as vectors of cards
    vector<Card> hand1;
    vector<Card> hand2;
    hand1.push_back(card1);
    hand1.push_back(card2);
    hand2.push_back(card3);
    hand2.push_back(card4);

    // create the BaccaratRules object
    BaccaratRules baccarat(hand1, hand2);

    // print out the payer and dealer's hands
    cout<<"\tPlayer's Hand: "<<baccarat.toString()<<endl;
    cout<<"\tDealer's Hand: "<<baccarat.dealerToString()<<endl;

    // print out who won.
    if(baccarat.isWon()){
      cout<<"\tPlayer wins!"<<endl;
    }
    else{
      cout<<"\tDealer wins!"<<endl;
    }
    cout<<endl;
  }
  cout<<"Exiting Baccarat.. Goodbye!"<<endl;
  return 0;
}
