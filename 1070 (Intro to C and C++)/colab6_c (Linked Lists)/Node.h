/*
Noah Nisbet
Colab 6C
Byte Club
November 29, 2022
CPSC 1071, section 2

This file defines the Node struct that is used to create the linked
lists in LinkedList.h
*/

#ifndef NODE_H
#define NODE_H

struct node {
  struct node *next;
  char data[300];
};

#endif
