/*
Noah Nisbet
10/9/22
Colab3C
Loan.cpp file used to create functions previously defined in Loan header File

Uses the already implemented functions from colab2c and reimplementsd them so that they can
be used in a header file below
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "Loan.h"

using namespace std;

/*
paymentDriver is used to get and validate user inputs then run the Loan payoff calculations and
print results to the user.
 */
void Loan::paymentDriver(){
  double principal;
  double annualInterestRate;
  double monthlyPayment;
  double payoffTime;
  double payoffTimeAdditional;
  double payoffTimeDifference;
  double payoffTimeYears;
  string paymentSentinel = "";
  
  //Do while loop with all the printing, response validating and calculations
  // This allows me to rerun the program later on if the user wants to input different values
  do{
    // I am using a sentinel value to exit this do while loop.
    paymentSentinel = "";
    cout<<"Loan Payment Calculator\n"<<endl;
    
    // Get the principle amount and make sure it is a valid input
    cout<<"Enter the principal amount: $";
    while (!(cin>>principal) || principal <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<"Enter the principle amount: $";
    }
    
    // Get the annual interest rate and make sure it is a valid input
    cout<<"Enter the annual interest rate (in percent): ";
    while (!(cin>>annualInterestRate) || annualInterestRate <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<"Enter the annual interest rate (in percent): ";
    }
    // Get the monthly payment amount and make sure it is a valid input
    cout<<"Enter the monthly payment: $";
    while (!(cin>>monthlyPayment) || monthlyPayment <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<"Enter the monthly payment: $";
    }
    
    cout<<"\nCalculating...\n"<<endl;
    
    // use the paymentMonths method to print statistics / return months to pay off loan
    payoffTime = paymentMonths(principal, annualInterestRate, monthlyPayment);
    cout<<"\n"<<endl;
    
    cout<<"Calculate another loan payoff? (y/n): ";
    cin>>paymentSentinel;
    //check to see if the user wants to input different data and that the user response is valid
    while (paymentSentinel != "n" && paymentSentinel != "N" && paymentSentinel != "y" && paymentSentinel != "Y"){
      cout<<"Invalid Input! Please choose again."<<endl;
      cout<<"Calculate another loan payoff? (y/n): ";
      cin>>paymentSentinel;
    }
  }
  while(paymentSentinel == "y" || paymentSentinel == "Y");
  cout<<endl;
  //Return back to the switch statement in the menu function
  return;
}

/*
Calculated how long until a loan will be paid off using user inputs from the paymentDriver function
Also, it uses cmath functions to carry out operations required to calculate months to payoff
 */
double Loan::paymentMonths(double principle, double annualInterestRate, double monthlyPayment){
  double payoffTime;
  double payoffTimeYears;
  double payoffTimeAdditional;
  double payoffTimeDifference;
  
  //Implementing formula given in the directions of colab1_C
  payoffTime = log(monthlyPayment);
  payoffTime = payoffTime - log(monthlyPayment-((annualInterestRate*principle)/1200.0));
  payoffTime = payoffTime / (log((annualInterestRate/1200.0)+1.0));

  //printing statistics
  cout<<round(payoffTime);
  cout<<" months (";
  
  payoffTimeYears = payoffTime / 12.0;
  cout<<round(payoffTimeYears*10.0)/10.0;
  cout<<" years) are needed to pay your loan off.\n";
  cout<<endl;
  
  //recalculating the time with paying 15 more dollars a month
  monthlyPayment += 15.0;
  payoffTimeAdditional = log(monthlyPayment);
  payoffTimeAdditional = payoffTimeAdditional - log(monthlyPayment-((annualInterestRate*principle)/1200.0));
  payoffTimeAdditional = payoffTimeAdditional / (log((annualInterestRate/1200.0)+1.0));
  
  payoffTimeDifference = payoffTime-payoffTimeAdditional;
  
  cout<<"Did you know if you paid an additional $15 per month, you would pay off your loan ";
  cout<<round(payoffTimeDifference);
  cout<<" months earlier?";
    
  //Returns time to pay off loan in months to the payment driver function. This will be printed to the us \
  er.
  return round(payoffTime);
}
