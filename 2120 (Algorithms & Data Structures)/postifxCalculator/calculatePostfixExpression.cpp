/*
 * Noah Nisbet
 * Stack-based Postfix Expression Calculator
 * Feb 17, 2023
 * CPSC 2120
 */


#include <string>
#include <stack>
#include <cctype>
#include <math.h>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
  // create stack nums for holding integers in expression
  stack<int> nums;

  // loop over expression
  for (int i=0; i<length; i++){
    // if the first character in the string is a digit convert the string to an int
    if (isdigit(expression[i][0])){
      // temp variable to add to stack
      int digit = 0;
      // use power of tens to convert string to int
      // go from biggest place value down to 1
      int placeValue = pow(10,(expression[i].size()-1));
      // loop over characters in string
      for (int j = 0; j<expression[i].size(); j++){
	// convert the current char to int, multipy by place value, add to digit 
	digit = digit + placeValue*int(expression[i][j] - '0');
	// divide place value by 10
	placeValue = placeValue/10;
      }
      // push digit to stack
      nums.push(digit);
    }

    // otherwise perform an operation
    else{
      // if there are not at least 2 digits in stack return 0
      if (nums.size() < 2)
	return 0;

      // pop top two digits
      int digit1 = nums.top();
      nums.pop();
      int digit2 = nums.top();
      nums.pop();

      // perform correct operation depending on current operator in expression
      // push value from operation back to num stack
      if (expression[i].compare("+") == 0)
	nums.push(digit1+digit2);
      else if (expression[i].compare("-") == 0)
	nums.push(digit2-digit1);
      else if (expression[i].compare("*") == 0)
	nums.push(digit2*digit1);
      else if (expression[i].compare("/") == 0)
	nums.push(digit2/digit1);
      else if (expression[i].compare("%") == 0)
	nums.push(digit2%digit1);
    }
  }

  // if there is only 1 number in the stack after looping through the expression
  // then it is ok to return
  if (nums.size() == 1)
    return nums.top();
  // otherwise something is wrong with the expression so return 0
  else
    return 0;
}
