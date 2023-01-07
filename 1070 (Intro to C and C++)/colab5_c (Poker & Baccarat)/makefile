# Noah Nisbet
# 10/23/22
# Makefile for Colab5C
# CPSC 1071, section 2

# This command will compile the source code when you run
compile:
	g++ Card.cpp -c -Wall
	g++ PokerRules.cpp -c -Wall
	g++ BaccaratRules.cpp -c -Wall
	g++ AnalyzeHand.cpp -c -Wall
	g++ DeckOfCards.cpp -c -Wall
	g++ Dealer.cpp Card.o PokerRules.o BaccaratRules.o AnalyzeHand.o -o executable.out -Wall
	g++ PlayBaccarat.cpp Card.o PokerRules.o BaccaratRules.o AnalyzeHand.o DeckOfCards.o -o extracredit.out -Wall

compile-card:
	g++ Card.cpp -c

# this command will delete all files ending in .o or .out
clean:
	rm *.o
	rm *.out
	rm *~
	rm *#

# This command will run the extracredit Program
run-baccarat:
	./extracredit.out
