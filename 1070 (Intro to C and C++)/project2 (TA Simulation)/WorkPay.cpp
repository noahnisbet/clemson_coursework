/*
Noah Nisbet
Project 1
October 17, 2022
CPSC 1070

This file defines functions prototypes in WorkPay class in WorkPay header file.
 */

#include <iostream>
#include <iomanip>
#include "WorkPay.h"
#include <sstream>
#include <string>

using namespace std;

/*
Contructor for WorkPay, takes in an int of initial hours worked and assigns private variable data to value.
 */
WorkPay::WorkPay(int inData){
  data = inData;
}

/*
Runs the WorkPay demo
This function takes in user input from the terminal. User can input hours, +, or - to change time worked in days in a WorkPay Object.
 */
void WorkPay::runWorkPay(){

  int input;
  string inputString;
  int numberSentinel = 0;

  //Getting the value for constructor in WorkPay
  do{
    cout<<"\nHello welcome to WorkPay, enter starting hours: ";
  }
  while (!(cin>>input));

  //Defining WorkPay Object
  WorkPay curWorkPay(input);

  cout<<"\tCurrent days worked: "<<curWorkPay.retrieveDays()<<endl;
  cout<<endl;
  cout<<"Enter + to increment days worked, - to decrement days worked, or a number of hours to add to total. \n(Enter Q to quit)"<<endl;

  // Do while loop that handles input validation and uses the overloaded operators in WorkPay to print current hours worked to user
  do{
    cout<<"Input: ";
    cin>>inputString;

    // Checks if all characters in string inputted by user are numbers
    // If so, using stringstream convert that string to an int and add that value to curWorkPayObject.
    if (checkStringIsNumber(inputString)){
      stringstream s(inputString);
      s >> input;
      curWorkPay + input;
      cout<<"\tCurrent days worked: "<<curWorkPay.retrieveDays()<<endl;
    }
    // increment if + is the input
    else if (inputString == "+"){
      curWorkPay++;
      cout<<"\tCurrent days worked: "<<curWorkPay.retrieveDays()<<endl;
    }
    // decrement if - is the input
    else if (inputString == "-"){
      curWorkPay--;
      cout<<"\tCurrent days worked: "<<curWorkPay.retrieveDays()<<endl;
    }
    // Do nothing yet if Q is the input, will escape do while loop soon.
    else if (inputString == "Q" || inputString == "q"){
    }
    // If none of the above if statements are hit the input cannot be understood.
    else {
      cout<<"Could not understand input, please try again."<<endl;
    }
  }
  while(inputString != "Q" && inputString != "q");
}

/*
Helper function for runWorkPay.
Takes in a string as the input and loops over all characters in the string to see if any characters are not a number.
If all are numbers return true.
 */
bool WorkPay::checkStringIsNumber(string input){
  for (int i=0; i<input.size(); i++){
    if (std::isdigit(input[i]) == 0){
      return false;
  }
  }
  return true;
}

/*
Store Data function that takes int as an input and assigns the private member variable of WorkPay to the input.
 */
void WorkPay::storeData(int inData){
  data = inData;
  return;
}
/*
getter function that returns the private member variable data's value in hours.
 */
double WorkPay::retrieveHours(void){
  return data;
}
/*
getter function that returns the private member variable data's value in days.
 */
double WorkPay::retrieveDays (void){
  return data / 8.0;
}
/*
Overloading the "-" operator. Take in an int as input and subtracts that value from the current value of data.
Also checks if the data is less than zero after the operation. If so, assign data to zero. 
 */
WorkPay WorkPay::operator - (int hours){
  data = data - hours;
  if (data < 0){
    data = 0;
  }
  return data;
}

/*
Overloading the "+" operator. Take in an int as input and adds that value to the current value of data.
*/
WorkPay WorkPay::operator + (int hours){
  data = data + hours;
  return data;
}

/*
Overloading the "--" postfix operator. Returns value of data then substracts 8 from data because 8 hours corresponds to 1 day.
Also checks if the data is less than zero after the operation. If so, assign data to zero.
 */
WorkPay WorkPay::operator -- (int){
  double toReturn = retrieveHours();
  data = data - 8;
  if (data < 0){
    data = 0;
  }
  return toReturn;
}

/*
Overloading the "++" postfix operator. Returns value of data then adds 8 to data because 8 hours corresponds to 1 day.
*/
WorkPay WorkPay::operator ++ (int){
  double toReturn = retrieveHours();
  data = data + 8;
  return toReturn;
}

/*
Overloading the "--" prefix operator. Returns value of data after it  substracts 8 from data because 8 hours corresponds to 1 day.
Also checks if the data is less than zero after the operation. If so, assign data to zero.
 */
WorkPay WorkPay::operator -- (){
  data = data - 8;
  if (data < 0){
    data = 0;
  }
  return retrieveHours();
}

/*
Overloading the "++" postfix operator. Returns value of data after it adds 8 to data because 8 hours corresponds to 1 day.
*/
WorkPay WorkPay::operator ++ (){
  data = data + 8;
  return retrieveHours();
}
