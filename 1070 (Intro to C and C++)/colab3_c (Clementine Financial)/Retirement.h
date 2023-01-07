/*
Noah Nisbet
10/9/22
Colab3C
Retirement header file

Uses header files to connect Retirement.cpp and Clementine.cpp
 */
#ifndef RETIRE_H
#define RETIRE_H
/*
Retirement class that will be included in Clementine.cpp
 */
class Retirement{
public:
  // Prototyping the estimateDriver function in Retirement.cpp
    void estimateDriver();
    
private:
  // Prototyping the estimateEarnings function in Retirement.cpp
    double estimateEarnings (int, int, double, double, double);
    
};
#endif
