/*
Noah Nisbet
Colab 5C
Byte Club
October 23, 2022
CPSC 1071, section 2

Dealer.cpp file that uses the BaccaratRules and PokerRules classes.
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include "PokerRules.h"
#include "BaccaratRules.h"
#include "Card.h"

using namespace std;

int main(int argc, char** argv){

  // if there is anything other than 1 arguement print
  // a message and return.
  if (argc != 2){
    cout<<"Please provide a single argument of 0 for Baccarat or 1 for Poker."<<endl;
    return 0;
  }
  
  // get the first input into the executable.
  int input = atoi(argv[1]);

  // if the input is something other than 1 and 0
  // print out a message and return.
  if ((input != 1) && (input !=0)){
    cout<<"Please provide a single argument of 0 for Baccarat or 1 for Poker."<<endl;
    return 0;
  }

  // if the input is 1 use poker rules.
  if (input == 1){
    cout<<endl;
    cout<<"******* Welcome to Poker Rules *******\n"<<endl;

    // create the hand
    vector<Card> hand1;
    Card card1(1,1);
    hand1.push_back(card1);
    Card card2(2,1);
    hand1.push_back(card2);
    Card card3(3,1);
    hand1.push_back(card3);
    Card card4(4,1);
    hand1.push_back(card4);
    Card card5(5,1);
    hand1.push_back(card5);

    // create PokerRules object.
    PokerRules poker(hand1);

    // check if the hand is a winning hand or not and print out results.
    cout<<"We are checking the hand:"<<endl;
    cout<<"\t"<<poker.toString()<<"\n"<<endl;
    cout<<"...Checking\n"<<endl;
    
    if(poker.isWon()){
      cout<<"This IS a winning hand! "<<endl;
    }
    else{
      cout<<"This is NOT a winning hand!"<<endl;
    }
    cout<<endl;
  }

  // if input is a zero use BaccaratRules
  if (input == 0){
    cout<<endl;
    cout<<"******* Welcome to Baccarat Rules *******"<<endl;
    cout<<endl;

    // create the two hands for BaccaratRules class
    vector<Card> hand2;
    Card card6(8,1);
    hand2.push_back(card6);
    Card card7(7,1);
    hand2.push_back(card7);
    vector<Card> hand3;
    Card card8(10,1);
    hand3.push_back(card8);
    Card card9(2,1);
    hand3.push_back(card9);

    // create BaccaratRules object.
    BaccaratRules baccarat(hand2, hand3);

    // check if the player has a winning hand or not and print out results.
    cout<<"We are checking the hand:"<<endl;
    cout<<"\t"<<baccarat.toString()<<endl;
    cout<<"against:"<<endl;
    cout<<"\t"<<baccarat.dealerToString()<<"\n"<<endl;
    cout<<"...Checking\n"<<endl;
    
    if(baccarat.isWon()){
      cout<<"This IS a winning hand!"<<endl;
    }
    else{
      cout<<"This is NOT a winning hand!"<<endl;
    }
    cout<<endl;
  }
  return 0;
}
