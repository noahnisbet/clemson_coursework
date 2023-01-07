/*
Noah Nisbet
Project 2
October 17, 2022
CPSC 1070

Simulation.cpp file that defines the functions prototyped in simulation header file.
 */

#include "Simulation.h"
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Simulation constructor, empty but here to show that.
 */
Simulation::Simulation(){
}

/*
moveJaneway function that takes in the pointer to Janeway's position in the simulation and moves her forward
randomly depending on the random number geneation where odds of different movements are the same as 
those defined in project directions.
 */
void Simulation::moveJaneway (unsigned int *ptrJaneway){
  // Using mod 20 because percentages are by the 5% and 100%/5% = 20 equal parts, so each number
  // In 1-20 represents 5% of the total chance.
  enum JanewayGradingStatus {Grading, RedoMistakes, SlowGrading};
  JanewayGradingStatus currentStatus;
  int i = 0;
  float grading = 0;
  float redomistakes = 0;
  float slowgrading = 0;
  float total = 0;

  switch(currentStatus){
  case Grading:
    *ptrJaneway += 3;
    break;

  case RedoMistakes:
    *ptrJaneway += 6;
    break;

  case SlowGrading:
    *ptrJaneway += 1;
    break;

  default:
    cout<<"Error, Janeway switch statement out of bounds"<<endl;
  }

  return;
}
/*
moveSisko function that takes in the pointer to Sisko's position in the simulation and moves him forward
randomly depending on the random number geneation where odds of different movements are the same as
those defined in project directions.
 */
void Simulation::moveSisko (unsigned int *ptrSisko){
  // Using mod 20 because percentages are by the 5% and 100%/5% = 20 equal parts, so each number
  // In 1-20 represents 5% of the total chance.
  enum SiskoGradingStatus {OutSick, TurboGrading, RedoMistakes, RegularGrading};
  SiskoGradingStatus currentStatus;
  int i = 0;
  float outsick = 0;
  float turbograding = 0;
  float redomistakes = 0;
  float regulargrading = 0;
  float total = 0;
  
  switch(currentStatus){
  case OutSick:
    break;
    
  case TurboGrading:
    *ptrSisko += 9;
    break;
    
  case RedoMistakes:
    *ptrSisko += 12;
    break;
    
  case RegularGrading:
    *ptrSisko += 1;
    break;
    
  default:
    cout<<"Error, Sisko switch statement out of bounds"<<endl;
  }
  return;
}

/*
runOneGame function that uses the moveSisko and moveJaneway functions to run a simulation
of the TA's competing in a grading battle and printing live standings to the user.
*/
void Simulation::runOneGame(){
  unsigned int SiskoPosition = 0;
  unsigned int JanewayPosition = 0;
  unsigned int *ptrSisko = &SiskoPosition;
  unsigned int *ptrJaneway = &JanewayPosition;
  // seeding the random number generator with time to get randomness.
  srand( time(NULL));

  cout<<"                        Running I.S.A.A.C. Simulation..."<<endl;
  cout<<"                        Janeway: J              Sisko: S"<<endl;
  cout<<"     <<< Intelligent System for Academic Assistance in Computing Simulation >>>"<<endl;
  
  // while either of the competitors are not at the 80 paper graded run the movement logic.
  while ((*ptrSisko < 79) && (*ptrJaneway < 79)){
    string curProgress = "--------------------------------------------------------------------------------";
    moveSisko(ptrSisko);
    moveJaneway(ptrJaneway);

    // if sisko and janeway are in the same postion progress bar at that point is char !
    if (*ptrSisko == *ptrJaneway){
      curProgress[*ptrSisko] = '!';
    }
    // else progress bar at the competitors postions is the first letter of their names.
    else{
      curProgress[*ptrSisko] = 'S';
      curProgress[*ptrJaneway] = 'J';
    }
    // if janeway and sisko are or above the last postion print wow its a tie
    // and move them back to last position if they went above
    if (*ptrSisko >= 79 && *ptrJaneway >= 79){
      curProgress[79] = '!';
      cout<<"[ "<<curProgress<<" ]"<<endl;
      cout<<"WOW!!! A TIE!!!"<<endl<<endl;
    }
    // if sisko is at the last position print sisko wins
    // and move them back to last position if they went above
    else if (*ptrSisko >= 79){
      curProgress[79] = 'S';
      cout<<"[ "<<curProgress<<" ]"<<endl;
      cout<<"SISKO WINS!!!"<<endl<<endl;
    }
    // if janeway is at the last position print sisko wins
    // and move them back to last position if they went above
    else if (*ptrJaneway >= 79){
      curProgress[79] = 'J';
      cout<<"[ "<<curProgress<<" ]"<<endl;
      cout<<"JANEWAY WINS!!!!"<<endl<<endl;
    }
    // if none of the above print current progress bar
    else {
      cout<<"[ "<<curProgress<<" ]"<<endl;
    }
    // sleep for one second or 1 million micro-seconds
    usleep(1000000);
  }
  
  return;
}
