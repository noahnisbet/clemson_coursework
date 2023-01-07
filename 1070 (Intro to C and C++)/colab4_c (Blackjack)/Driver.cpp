/*
 Byte Club B-2
 CPSC 1071-02
 10/24/2022
 Team Members:
 Kinzie Hall 
 Kwame Andre
 Max Koon
 Noah Nisbet

We decided to test our Card and DeckOfCard classes and functions by simulating a game of BlackJack.
This game tests all of the functions used by the Cards class and the DeckOfCards Class.
*/
#include <iostream>
#include <cstdlib>
#include "Card.h"
#include "DeckOfCards.h"
#include <vector>

using namespace std;

int main(){
  cout<<endl;
  cout<<"Clemson Blackjack :D"<<endl;
  cout<<"Ace is always 1, sorry"<<endl;
  cout<<endl;

  /*
Initialized deck and curCard objects for use in game.
   */ 
  DeckOfCards deck;
  Card curCard;
  int value = 0;
  int curValue = 0;
  string response;
  int sentinel = 0;
  /*
Shuffle function tested/used here. We know it works because the game is random each time.
   */
  deck.shuffle();
  do{
    if (sentinel == 0){
      cout<<"\tYour first card is: ";
      sentinel++;
    }
    else{
      cout<<endl;
      cout<<"\tYour next card is: ";
    }
    /*
Deal card function. Takes the "top card" off the deck and removes in from the vector in the class.
     */
    curCard = deck.dealCard();
    /*
Prints out the value of the current card but in string format.
     */
    cout<<curCard.toString()<<endl;
    curValue = curCard.curFace+1;
    if (curValue>10){
      curValue = 10;
    }
    value += curValue;
    cout<<"\tTotal value: "<<value<<"\n"<<endl;
    if (value <= 21){
      do{
	cout<<"Would you like to draw a card? (Y for yes, N for no): ";
	cin>>response;
      }
      while(response != "Y" && response != "y" && response != "N" && response != "n");
    }
  }
  // Doesn't continue the game if there are no more cards.
  while(value <= 21 && (response == "Y" || response == "y") && deck.moreCards());

  Card dealerCurCard;
  int dealerValue = 0;
  int dealerCurValue = 0;
  string dealerCards;
  if (value <= 21){
    while(dealerValue <= value){
      dealerCurCard = deck.dealCard();
      dealerCurValue = dealerCurCard.curFace+1;
      if (dealerCurValue>10){
	dealerCurValue = 10;
      }
      dealerValue += dealerCurValue;
    }
    cout<<endl;
    cout<<"\tDealer's drew a total of: "<<dealerValue<<endl;
  }
  cout<<endl;
  if (value>21){
    cout<<"You busted you lose :("<<endl;
  }
  else if (dealerValue>21){
    cout<<"Dealer busted you win!!"<<endl;
  }
  else if(dealerValue > value){
    cout<<"Sorry you lose :("<<endl;
  }
  else if(dealerValue < value){
    cout<<"You win!!"<<endl;
  }
  else if(dealerValue == value){
    cout<<"It is a tie!"<<endl;
  }
  else {
    cout<<"idk"<<endl;
  }
  cout<<endl;
  return 0;
}
