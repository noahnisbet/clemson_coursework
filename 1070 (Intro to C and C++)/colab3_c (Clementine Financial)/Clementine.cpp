/*
Noah Nisbet
10/9/22
Colab3C

This file handles the menu logic for Clementine Financial
Routes user inputs to appropriate files where different functionalities
take place.
Also validates user inputs.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>
#include "Loan.h"
#include "Retirement.h"
#include "Register.h"

using namespace std;

void printMenu(){
    cout<<"******* Welcome to Clementine Financial *********\n"<<endl;
    cout<<"Menu:"<<endl;
    cout<<"        [E] Estimate how much money at retirement"<<endl;
    cout<<"        [L] Loan payoff calculator"<<endl;
    cout<<"        [R] Run transaction classifier"<<endl;
    cout<<"        [Q] Quit program\n"<<endl;
    cout<<" Enter your choice and press enter: ";
    return;
}

/*
This function prints the menu and insures that the inputs to the menu are valid.
It also has a switch statement that handles the logic after a valid input is entered.
 */
void runMenuSystem(){
  string userInput;
  int sentinel = 0;
  char userInputChar;

  cout<<"Starting Clementine Financial Bank"<<endl;
  //While loop that keeps running the menu until the sentinel value is changed.
  //sentinel value is only changed in the switch statement when Q is entered
  while (sentinel == 0){

    // validation of the menu:
    // user input is a string to handle for inputs greater than 1 char
    // Also using a do while loop to repeatedly print the menu until a valid input is entered
    printMenu();
    cin>>userInput;
    if (userInput != "E" && userInput != "L" && userInput != "Q" && userInput != "R" && userInput != "e" && userInput != "l" && userInput != "q" && userInput != "r"){
      do{
        cout<<endl;
        cout<<"The provided choice was invalid! Please select again.\n"<<endl;
	printMenu();
	cin>>userInput;
      }
      while (userInput != "E" && userInput != "L" && userInput != "Q" && userInput != "R" && userInput != "e" && userInput != "l" && userInput != "q" && userInput != "r");
    }
    userInputChar = toupper(userInput[0]);
    // grabbing the first value of the userInput string so that I can use a switch statement
    // There should be no way this string's length is greater than 1
    switch (userInputChar){

    // if user input is e or E run the estimate driver
    case 'E':
      {
      Retirement RetirementObject;
      RetirementObject.estimateDriver();
      }
      break;

    // if user input is l or L run the payment driver
    case 'L':
      {
      Loan LoanObject;
      LoanObject.paymentDriver();
      }
      break;

      // if user input is l or L run the payment driver
    case 'R':
      {
      Register RegisterObject;
      RegisterObject.processTransaction();
      }
      break;

      // if q or Q is entered, change the sentinel at the start of this function to 1 to exit the loop and end the program.
    case 'Q':
      sentinel = 1;
      break;
      
    default:
      cout<<"Invalid input into switch statement, error"<<endl;
      break;
    }
  }
  return;
}

// main function
int main(){
  runMenuSystem();
  return 0;
}
