/*
Noah Nisbet
10/17/22
Project2
CPSC 1070

header file used to connect the driver.cpp file and simulation.cpp
 */

#ifndef SIMULATION_H
#define SIMULATION_H
//Simulation class
class Simulation {
public:
  // prototyping the functions that will be defined in simulation.cpp
  Simulation();
  void moveJaneway (unsigned int *ptrJaneway);
  void moveSisko (unsigned int *ptrSisko);
  void runOneGame(); 

private:  

};
#endif
