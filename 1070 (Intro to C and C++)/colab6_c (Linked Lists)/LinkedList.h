/*
Noah Nisbet
Colab 6C
Byte Club
November 29, 2022
CPSC 1071, section 2

This file prototypes the functions to be defined in LinkedList.c
*/

#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// prints out the linked list given the head of the list
void printList(struct node *head);
// make the list using user inputs
struct node* makeList(void);
// deallocate the memory the linked list uses by traversing over it.
void deleteList(struct node *head);
#endif
