# Noah Nisbet
# 10/23/22
# Makefile for Colab4C
# CPSC 1071, section 2

# This command will compile the source code when you run
compile:
	g++ -std=c++11 Card.cpp -c -Wall
	g++ -std=c++11 DeckOfCards.cpp -c -Wall
	g++ -std=c++11 Driver.cpp Card.o DeckOfCards.o -o driver.out -Wall

compile-card:
	g++ -std=c++11 Card.cpp -c

# this command will delete all files ending in .o or .out
clean:
	rm *.o
	rm *.out

# This command will run the Program
run:
	./driver.out
