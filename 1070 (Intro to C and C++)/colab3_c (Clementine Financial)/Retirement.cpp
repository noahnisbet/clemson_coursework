/*
Noah Nisbet
Retirement.cpp File used to define functions in the Retirement.h class
Colab3C
10/9/22

This class implement the functions defined in the class in Retirement.h.
It uses the previous work from labs but reimplements them to work with the class
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "Retirement.h"

using namespace std;

/*
Estimates the earnings using the plan created in colab2 part B

It uses a for loop to compound growth for the number of months inputted
 */
double Retirement::estimateEarnings(int currentAge, int retirementAge, double amountSaved, double monthlyContribution, double annualReturn){

  int numMonthsToRetirement = 12.0*retirementAge - 12.0*currentAge;
  double runningBalance = amountSaved;
  double curGrowth = 0.0;
  double runningGrowth = 0.0;
  double growth = 0.0;
  annualReturn = annualReturn/100.0;

  for (int i = 0; i<numMonthsToRetirement; i++){
    curGrowth = runningBalance * (annualReturn / 12.0);
    runningBalance += (monthlyContribution + curGrowth);
  }
  growth = runningBalance-(numMonthsToRetirement*monthlyContribution+amountSaved);

  cout<<"Estimated Retirement Savings: $"<<fixed<<setprecision(2)<<runningBalance<<endl;
  cout<<"Estimated Retirement Growth: $"<<fixed<<setprecision(2)<<growth<<endl;
  cout<<""<<endl;
  //Returns running balance to the estimateDriver function to be printed to the user
  return round(runningBalance*100.0)/100.0;
}
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;
/*
Estimate how much money user will have at retirement

This function takes in user inputs, validates them, feeds that information into the estimateEarnings\
 function above.
After information is calculated the information is printed to the user.
Also uses a do while loop to repeat this process if the user would like to put in more information.
 */
void Retirement::estimateDriver(){
  int retirementAge;
  double savings;
  double monthlyContribution;
  double annualReturn;
  int currentAge;
  string estimateSentinel = "";

  //Do while loop with all the printing, response validating and calculations
  // This allows me to rerun the program later on if the user wants to input different values

  do{
    //sentinel value for exiting the do while loop if the user is finished using the program.
    estimateSentinel = "";
    cout<<"Estimate Savings at Retirement"<<endl;
    cout<<"Disclaimer: This is only a rough estimate!"<<endl;
    cout<<endl;

    //This while loop checks to make sure the input is an int and that int is non-negative
    cout<<"        Enter your current age in years: ";
    while (!(cin>>currentAge) || currentAge <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      if (currentAge <= 0){
        cout<<"        Age cannot be 0 or less."<<endl;
      }
      cout<<"        Re-enter your age in years: ";
    }

    //This while loop checks to make sure the input is an int and that int is non-negative
    // Also checks that the retirement age is not less than or equal to the current age of the user
    cout<<"        Enter your target retirement age: ";
    while (!(cin>>retirementAge) || retirementAge <= 0 || retirementAge <= currentAge){
      cin.clear();
      cin.ignore(10000,'\n');
      if (retirementAge <= 0){
        cout<<"        Your target age cannot be less than or equal to zero."<<endl;
      }
      else if (retirementAge <= currentAge){
        cout<<"        Your target age cannot be less than or equal your current age."<<endl;
      }
      cout<<"        Re-enter your target age in years: ";
    }

    //This while loop checks to make sure the input is an double and that double is non-negative

    cout<<"        How much have you saved towards retirement?: $";
    while (!(cin>>savings) || savings <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      if (savings <= 0){
        cout<<"        Your savings cannot be negative."<<endl;
      }
      cout<<"        Re-enter your savings: $";
    }

    //This while loop checks to make sure the input is an double and that double is non-negative
    cout<<"        Enter your monthly contribution to retirement: $";
    while (!(cin>>monthlyContribution) || monthlyContribution <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      if (monthlyContribution <= 0){
        cout<<"        Your monthly contribution cannot be less than or equal to zero."<<endl;
      }
      cout<<"        Re-enter your monthly contribution: $";
    }

  //This while loop checks to make sure the input is an double and that double is non-negative
    cout<<"        Enter the estimated annual return on investment (in percent): ";
    while (!(cin>>annualReturn) || annualReturn <= 0){
      cin.clear();
      cin.ignore(10000,'\n');
      if (annualReturn <= 0){
        cout<<"        Your rate cannot be less than zero."<<endl;
      }
      cout<<"        Re-enter your rate (in percent): ";
    }
    cout<<".\n.\n...calculating"<<endl;

    cout<<""<<endl;
    // calculate earnings using the estimateEarnings function and print out the stats
    double earnings = estimateEarnings(currentAge, retirementAge, savings, monthlyContribution, annualReturn);
    cout<<"Calculate another estimate? (y/n): ";
    cin>>estimateSentinel;
    // check if the user want to run the program again / make sure that the user input is valid.
    while (estimateSentinel != "n" && estimateSentinel != "N" && estimateSentinel != "y" && estimateSentinel != "Y"){
      cout<<"Invalid Input! Please choose again."<<endl;
      cout<<"Calculate another estimate? (y/n): ";
      cin>>estimateSentinel;
    }
  }
  while(estimateSentinel == "y" || estimateSentinel == "Y");
  cout<<"\n"<<endl;

  return;
}
