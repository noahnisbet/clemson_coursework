/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

Queue.h file that connects the Queue class to other files.
This class was copies from the textbook.
*/

#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
  struct QueueNode{
    int value;
    QueueNode *next;
    QueueNode(int value1, QueueNode *next1 = nullptr)
    {
      value = value1;
      next = next1;
    }
  };
  // These track the front and rear of the queue
  QueueNode *front;
  QueueNode *rear;
 public:
  // Constructor and Destructor
  Queue();
  ~Queue();
  
  // Member functions
  void enqueue(int);
  void dequeue(int &);
  bool isEmpty() const;
  bool isFull() const;
  void clear();
private:
  int counter = 0;
};
#endif
