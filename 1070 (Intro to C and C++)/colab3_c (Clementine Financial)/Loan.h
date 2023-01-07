/*
Noah Nisbet
10/9/22
Colab 3C
Loan header file

uses header files to connect Clementine.cpp and Loan.cpp
 */
#ifndef LOAN_H
#define LOAN_H

/*
Loan class that will be included in Clementine.cpp
 */
class Loan {
 public:
  // prototyping paymentDriver function that will is implemented in Loan.cpp
  void paymentDriver();

private:
  // prototyping paymentMonths function which is implemented in Loan.cpp
  double paymentMonths(double, double, double);
};
#endif
