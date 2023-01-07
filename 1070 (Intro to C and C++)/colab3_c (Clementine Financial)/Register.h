/*
Noah Nisbet
10/9/22
Colab3C
Register Header File

Uses header files to connect the Clementine.cpp and Register.cpp files
 */
#ifndef REGISTER_H
#define REGISTER_H
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

// Defining the enumerated type Transactions
enum class Transactions { RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER };

// Defining the class Register
class Register {
private:
  // Defining private variables used in Register.cpp
  std::string fileName;
  std::ifstream fileData;
  int totalLines = 0;
  std::vector<std::string> transactionDateVector;
  std::vector<Transactions> transactionTypeVector;
  std::vector<std::string> transactionNameVector;
  std::vector<std::string> transactionAmountVector;

public:
  // Defining functions belonging to the class
  Register();
  std::string getFileName();
  Transactions convertToEnumTransactions(std::string);
  void setFileName(std::string);
  void printFile();
  bool readFromFile();
  bool processTransaction();

};
#endif
