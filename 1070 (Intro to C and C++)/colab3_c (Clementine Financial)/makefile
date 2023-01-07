# Noah Nisbet
# 10/9/22
# Makefile for Colab3C

# This command will compile the source code when you run
compile:
	g++ -std=c++11 Retirement.cpp -c
	g++ -std=c++11 Register.cpp -c
	g++ -std=c++11 Loan.cpp -c
	g++ -std=c++11 Clementine.cpp Retirement.o Register.o Loan.o -o calculate.out

# this command will delete all files ending in .o or .out
clean:
	rm *.o
	rm *.out

# This command will run the Program
run:
	./calculate.out
