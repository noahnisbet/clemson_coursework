/*
Noah Nisbet
Register.cpp
Colab3C
10/9/22

This file works with the Register header file to process transaction ledgers and print the
contents to a user
 */

#include "Register.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include<algorithm>

using std::ifstream;

using namespace std;

/*
Constructor
Not needed so empty
 */
Register::Register(){
}

/*
convert from string to enum Transactions
This necessary for printing the transaction type to the user.
It uses if, else if, and else logic to return the correct Transactions 
object.
By default the function returns OTHER
 */
Transactions Register::convertToEnumTransactions(string input){
  if (input == "RESTAURANT"){
    return Transactions::RESTAURANT;
  }
  else if (input == "MERCHANDISE"){
    return Transactions::MERCHANDISE;
  }
  else if (input == "UTILITY"){
    return Transactions::UTILITY;
  }
  else if (input == "COFFEESHOP"){
    return Transactions::COFFEESHOP;
  }
  else if (input == "AUTOMOTIVE"){
    return Transactions::AUTOMOTIVE;
  }
  else if (input == "DEPOSIT"){
    return Transactions::DEPOSIT;
  }
  else if (input == "OTHER"){
    return Transactions::OTHER;
  }
  else {
    return Transactions::OTHER;
  }
  
}
/*
Gets the filename from the user
then returns the file
 */
string Register::getFileName(){
    cout<<"        Please enter the filename: ";
    cin>>fileName;
    return fileName;
  }

/*
Sets the file name to the input string
 */
void Register::setFileName(string inputString){
  fileName = inputString;
  return;
}
/*
Uses the vectors filled in process transaction to print the ledger to the screen
All vectors other than the transaction type are relatively simple, simply grab the
element at the index in the for loop from all vectors.

transaction type requires an array to index into. It works because enums can be
casted to their order in declaration.

Also uses setw, right, fixed, and setprecision to format the output for the user
 */
void Register::printFile(){
  string transactionTypes[] = {"Restaurant", "Merchandise", "Utility", "Coffeeshop", "Automotive", "Deposit", "Other"};
  int curTransactionTypeNum;
  cout<<"Printing Transaction Ledger"<<endl;
  for (int i = 0; i<totalLines; i++){
    cout<<right<<setw(10);
    cout<<transactionDateVector.at(i)<<" |";
    cout<<setw(15);
    cout<<transactionNameVector.at(i)<<" |";
    cout<<setw(10);
    cout<<transactionAmountVector.at(i)<<" |";
    cout<<setw(20);
    Transactions curTransactionType = transactionTypeVector.at(i);
    curTransactionTypeNum = int(curTransactionType);
    cout<<transactionTypes[curTransactionTypeNum]<<endl;
    cout<<endl;
  }
  return;
}

/*
read in the data and then populate the respective vectors
Uses a switch statement, vector operations, and streams to do this
 */
bool Register::readFromFile(){
  cout<<"        Opening the file <"+fileName+">"<<endl;
  ifstream fileData(fileName);
  
  if (!fileData){
    return false;
  }
  
  int curLineNum = 0;
  string curLineAmount = "";
  string curLineDate = "";
  string curLineType = "";
  string curLineName = "";
  string curLineString = "";
  int i = 0;
  totalLines = 0;
  transactionAmountVector.clear();
  transactionNameVector.clear();
  transactionDateVector.clear();
  transactionTypeVector.clear();
  
  while (getline(fileData, curLineString) ){
    
    stringstream ss(curLineString);
    ss >> curLineDate >> curLineType >> curLineName >> curLineAmount;
    curLineAmount.erase(remove(curLineAmount.begin(), curLineAmount.end(), '+'), curLineAmount.end());
    transactionDateVector.push_back(curLineDate);
    transactionTypeVector.push_back(convertToEnumTransactions(curLineType));
    transactionNameVector.push_back(curLineName);
    transactionAmountVector.push_back(curLineAmount);
    totalLines++;
  }
  return true;
}

/*
Driver for the Register class
Uses the above methods to get an input from the user, read
the input file, and then print out the formatted ledger.

This function also handles input validation
 */
bool Register::processTransaction(){
  string transactionSentinel = "";
  
  do{
    fileName = getFileName();
    while (!readFromFile()){
      cout<<"Error opening file. Please retry."<<endl;
      fileName = getFileName();
    }
    printFile();
    
    cout<<"Would you like to process another transaction register? (y/n): ";
    cin>>transactionSentinel;
    
    // check if the user want to run the program again / make sure that the user input is valid.
    while (transactionSentinel != "n" && transactionSentinel != "N" && transactionSentinel != "y" && transactionSentinel != "Y"){
      cout<<"Invalid Input! Please choose again."<<endl;
      cout<<"Would you like to process another transaction register? (y/n): ";
      cin>>transactionSentinel;
    }
  }
  while(transactionSentinel == "y" || transactionSentinel == "Y");
  cout<<endl;
  return true;
}
