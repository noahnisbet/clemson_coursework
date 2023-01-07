/*
Noah Nisbet
CPSC 1071: section 02
Team 2, Byte Club
September 21, 2022
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

/*
Estimates the earnings using the plan created in colab2 part B

It uses a for loop to compound growth for the number of months inputted
 */
double estimateEarnings(int currentAge, int retirementAge, double amountSaved, double monthlyContribution, double annualReturn){

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

/*
Calculates the time to pay off loan given: a principle amount, an annual interest rate, and a monthly payment

I wrote this function in colab1_C so I took it from there with a few minor modifications
 */
double paymentMonths(double principle, double annualInterestRate, double monthlyPayment){
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

  //Returns time to pay off loan in months to the payment driver function. This will be printed to the user.
  return round(payoffTime);
}

/*
Payment driver

Gets inputs from user and validates the responses.
After inputs are validated it runs those values through the respective calcualtion functions above.
After the calculations are returned it prints those values to the users.
After that it checks to see if the user want to do another calculation or not and then reruns the program
or exits depending on the user's input

 */
void paymentDriver(){
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

    //check to see if the user wants to input different data and that the user response is valid
    while (paymentSentinel != "n" && paymentSentinel != "N" && paymentSentinel != "y" && paymentSentinel != "Y"){
      cout<<"Calculate another loan payoff? (y/n): ";
      cin>>paymentSentinel;
    }
  }
  while(paymentSentinel == "y" || paymentSentinel == "Y");
  cout<<"\n"<<endl;
  //Return back to the switch statement in the menu function
return;
}

/*
Estimate how much money user will have at retirement

This function takes in user inputs, validates them, feeds that information into the estimateEarnings function above.
After information is calculated the information is printed to the user.
Also uses a do while loop to repeat this process if the user would like to put in more information.
 */

void estimateDriver(){
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

    // check if the user want to run the program again / make sure that the user input is valid.
    while (estimateSentinel != "n" && estimateSentinel != "N" && estimateSentinel != "y" && estimateSentinel != "Y"){
      cout<<"Calculate another estimate? (y/n): ";
      cin>>estimateSentinel;
    }
  }
  while(estimateSentinel == "y" || estimateSentinel == "Y");
  cout<<"\n"<<endl;
  
  return;
}


//基于文本的菜单系统
//Text-based menu system
/*
This function prints the menu and insures that the inputs to the menu are valid.
It also has a switch statement that handles the logic after a valid input is entered.
 */
void runMenuSystem(){
  string userInput;
  int sentinel = 0;
  char userInputChar;

  //While loop that keeps running the menu until the sentinel value is changed.
  //sentinel value is only changed in the switch statement when Q is entered
  while (sentinel == 0){

    // validation of the menu:
    // user input is a string to handle for inputs greater than 1 char
    // Also using a do while loop to repeatedly print the menu until a valid input is entered
    cout<<"******* Welcome to Clementine Financial *******\n"<<endl;
    cout<<"Menu:"<<endl;
    cout<<"        [E] Estimate how much money at retirement"<<endl;
    cout<<"        [L] Loan payoff calculator"<<endl;
    cout<<"        [Q] Quit program\n"<<endl;
    cout<<" Enter your choice and press enter: ";
    cin>>userInput;

    if (userInput != "E" && userInput != "e" && userInput != "L" && userInput != "l" && userInput != "Q" && userInput != "q"){
      do{
	cout<<endl;
	cout<<"The provided choice was invalid! Please select again.\n"<<endl;
	cout<<"******* Welcome to Clementine Financial *******\n"<<endl;
	cout<<"Menu:"<<endl;
	cout<<"        [E] Estimate how much money at retirement"<<endl;
	cout<<"        [L] Loan payoff calculator"<<endl;
	cout<<"        [Q] Quit program\n"<<endl;
	cout<<" Enter your choice and press enter: ";
	cin>>userInput;
      }
      while (userInput != "E" && userInput != "e" && userInput != "L" && userInput != "l" && userInput != "Q" && userInput != "q");
    }
    // grabbing the first value of the userInput string so that I can use a switch statement
    // There should be no way this string's length is greater than 1
    userInputChar = userInput[0];
    switch (userInputChar){

    // if user input is e or E run the estimate driver
    case 'E': case 'e':
      estimateDriver();
      break;

    // if user input is l or L run the payment driver
    case 'L': case'l':
      paymentDriver();
      break;

    // if q or Q is entered, change the sentinel at the start of this function to 1 to exit the loop and end the program.
    case 'Q': case 'q':
      sentinel = 1;
      break;
    }
  }
  return;
}

int main(){
  runMenuSystem();
  return 0;

}
