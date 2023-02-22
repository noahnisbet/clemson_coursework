#include <iostream>
#include <string>
#include <string>
#include <stack>
#include <cctype>
#include <iostream>
using namespace std;
bool higherPrecendenceCheck(string cur, string top)
{
  if ((top.compare("+") == 0) || (top.compare("-") == 0))
    {
      if ((cur.compare("%") == 0) || (cur.compare("/") == 0) || (cur.compare("*") == 0) || (cur.compare("+") == 0)
          || (cur.compare("-") == 0))
        {
          return true;
        }
    }
  return false;
}
int infixToPostfix(string infix[], int length, string postfix[])
{
  stack<string> operatorStack;
  int curPostfix = 0;
  string curOperator;
  for (int i=0; i<length; i++)
    {
      if(isdigit(infix[i][0]))
        {
          postfix[curPostfix] = infix[i];
          curPostfix++;
        }
      else if(infix[i] == "(")
        {
          operatorStack.push(infix[i]);
        }
      else if(infix[i] == ")")
	{
          while(!operatorStack.empty() && (operatorStack.top() != "("))
            {
              postfix[curPostfix] = operatorStack.top();
              curPostfix++;
              operatorStack.pop();
            }
          if (!operatorStack.empty() && operatorStack.top() == "(")
            {
              operatorStack.pop();
            }
        }
      else
        {
          while (!operatorStack.empty() && higherPrecendenceCheck(operatorStack.top(), infix[i]) &&
                 operatorStack.top().compare("(") != 0)
            {
              postfix[curPostfix] = operatorStack.top();
              curPostfix++;
              operatorStack.pop();
            }
          operatorStack.push(infix[i]);
        }
    }
  while (!operatorStack.empty())
    {
      postfix[curPostfix] = operatorStack.top();
      curPostfix++;
      operatorStack.pop();
    }
  return curPostfix;
}

int main()
{
    string infixExp[] = {"2", "+", "3"};
    string postfixExp[] = {"2", "3", "+"};
    string postfixTest[3];
    int postfixLength = infixToPostfix(infixExp, 3, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<3; i++)
    {
        if (postfixTest[i] != postfixExp[i])
        {
            cout << "Mismatch at position " << i << ": expected/correct value " << postfixExp[i] << ", actual value when testing " << postfixTest[i] << ".\n";
            return 1;
        }
    }
    cout << "Passed" << endl;
    return 0;
}
