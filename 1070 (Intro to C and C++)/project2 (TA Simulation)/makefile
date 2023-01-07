# Noah Nisbet
# 10/17/22
# Makefile for Project2

# This command will compile the source code when you run
compile-all:
	g++ -std=c++11 Simulation.cpp -c
	g++ -std=c++11 WorkPay.cpp -c
	g++ -std=c++11 driver.cpp WorkPay.o Simulation.o -o driver.out

# This command will compile Workpay.cpp
compile-workpay:
	g++ -std=c++11 WorkPay.cpp -c

# This command will compile Simulation.cpp
compile-simulation:
	g++ -std=c++11 Simulation.cpp -c

# this command will delete all files ending in .o or .out
clean:
	rm *.o
	rm *.out

# This command will run the Program
run:
	./driver.out
