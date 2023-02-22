/*
 * Noah Nisbet
 * Swapping Nodes in a Doubly Linked List
 * Feb 17, 2023
 * CPSC 2120
 */

#include "doublyLinkedSwap.h"

// Implement the following function:
// p and afterp are pointers to the nodes to be swapped.
/*
 * swapWithNext function
 * uses pointer operations to swap a specified node with the next node in the list
 * using pointers
 */
void swapWithNext(Node * p)
{
  // if the next node is NULL return
  if (p->next == nullptr)
    return;
  // if the next node's next node is NULL return
  if (p->next->next == nullptr)
    return;
  // if the previous node is NULL return
  if (p->prev == nullptr)
    return;

  // below is the pointer arithmatic that swappes the nodes
  p->prev->next = p->next;
  p->next->prev = p->prev;
  p->prev = p->next;
  p->next = p->next->next;
  p->prev->next = p;

  // if p->next is not the nullptr after swapping then p->next->previous
  // should be itself
  if (p->next != nullptr)
    p->next->prev = p;
}

//Be sure to comment out the main() function when submitting to codePost
/*
int main()
{
    int array[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    Node * head = arrayToList(array, 10);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [0],[1]" << endl;
    Node * p = getNode(head, 0);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [4],[5]" << endl;
    p = getNode(head, 4);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [8],[9]" << endl;
    p = getNode(head, 8);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
}
*/
//Do not modify any functions below this line
Node * arrayToList(int array[], int size)
{
    Node * head;
    Node * p;
    int pos = 0;
    if (size > 0)
    {
        head = new Node();
        head->prev = nullptr;
        head->value = 0;
        p = head;
        while (pos < size)
        {
            p->next = new Node();
            p->next->prev = p;
            p = p->next;
            p->value = array[pos];
            pos++;
        }
        p->next = new Node();
        p->next->prev = p;
        p = p->next;
        p->value = 0;
        p->next = nullptr;
    }
    else
    {
        return nullptr;
    }
    return head;
}

//Return pointer to end of the list
Node * getTail(Node * head)
{
    Node * p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

//Return pointer to node with "index"
//First node "index" 0, second node "index" 1, ...
Node * getNode(Node * head, int index)
{
    int pos = 0;
    Node * p = head->next;
    if (pos == index)
    {
        return p;
    }
    else if (index < 0)
    {
        return head;
    }
    else
    {
        while (pos < index && p->next != nullptr)
        {
            p = p->next;
            pos++;
        }
    }
    return p;
}

//Print list forwards from start
void printForwards(Node * head)
{
    Node * p = head->next;
    while (p->next != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

//Print list backwards from end
void printBackwards(Node * tail)
{
    Node * p = tail->prev;
    while (p->prev != nullptr)
    {
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;
}
