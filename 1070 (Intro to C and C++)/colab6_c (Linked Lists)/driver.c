/*
Noah Nisbet
Colab 6C
Byte Club
November 29, 2022
CPSC 1071, section 2

This file runs the methods created in the LinkedList header file.
*/

#include "LinkedList.h"
#include "string.h"
#include "stdio.h"
#include "Node.h"

int main(){
  struct node *list = makeList();
  printList(list);
  deleteList(list);
  return 0;
}
