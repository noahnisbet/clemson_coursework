
/*
Noah Nisbet
10/17/22
Project2
CPSC 1070

This is the WorkPay header file that connects driver.cpp and WorkPay.cpp
*/

#ifndef WORKPAY_H
#define WORKPAY_H
#include <string>

/*
WorkPay Class
 */
class WorkPay {

  //prototyping functions
public:
  WorkPay(int inData);
  bool checkStringIsNumber(std::string input);
  void runWorkPay();
  void storeData(int inData);
  double retrieveHours(void);
  double retrieveDays (void);
  WorkPay operator - (int hours);
  WorkPay operator + (int hours);
  WorkPay operator -- (int);
  WorkPay operator ++ (int);
  WorkPay operator -- ();
  WorkPay operator ++ ();
  
private:
  // private member variable data where hours worked is stored.
  int data;

};
#endif
