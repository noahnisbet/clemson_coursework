# Noah Nisbet
# Project 3 Cipher Code
# November 11, 2022
# CPSC 1070
# This file is the makefile that I use to compile, run and clean code.

# This command will compile the source code when you run
compile:
	g++ -std=c++11 Queue.cpp -c
	g++ -std=c++11 Cipher.cpp -c
	g++ -std=c++11 CipherAdvanced.cpp -c
	g++ -std=c++11 Project3.cpp Queue.o Cipher.o CipherAdvanced.o -o driver.out
run:
	./driver.out
# this command will delete all files ending in .o or .out
clean:
	rm *.o
	rm *.out
