/*
Noah Nisbet
October 17, 2022
Project 1
CPSC 1070

This program simulates a TA grading battle and uses overloaded operators to keep track of hours worked.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Simulation.h"
#include "WorkPay.h"
#include <string>

using namespace std;

/*
getInput function that outputs a menu for the user on startup and returns a character to be used in a switch statement
validates user input and returns character to move user where they want in the program.
 */
char getInput(){
  string input;
  do{
    cout<<"Input S for Simulation, W for WorkPay and Q to quit: ";
    cin>>input;
  }
  while (input != "S" && input != "W" && input != "Q" && input != "s" && input != "w" && input != "q");
  return toupper(input[0]);
}

/*
Handles user inputs and uses a switch statment to either run Simulation, run WorkPay, or quit.
 */
void runProgram(){
  char input;
  int sentinel = 0;
  Simulation SimulationObject;
  WorkPay WorkPayObject(0);
  do{
  input = getInput();

  switch (input){
  case 'S':
    SimulationObject.runOneGame();
    break;

  case 'W':
    WorkPayObject.runWorkPay();
    break;

  case 'Q':
    sentinel = 1;
    break;

  default:
    cout<<"Error, driver switch statement out of bounds"<<endl;
  }}
  while(sentinel == 0);
  return;
}
/*
Main method where we call runProgram.
 */
int main(){
  runProgram();
  return 0;
}
