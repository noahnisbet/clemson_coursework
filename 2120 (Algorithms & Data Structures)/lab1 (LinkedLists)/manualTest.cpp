#include <iostream>
#include "List.h"
#include "Node.h"
#include <string>

using namespace std;

int main(){

  List<int> list1;

  list1.print("name");
  if (list1.empty()){
    printf("worked\n");
  }

  cout<<"insert"<<endl;
  list1.insertStart(1);
  cout<<list1.size()<<endl;
  list1.insertEnd(2);
  cout<<list1.size()<<endl;
  list1.insertAt(3,1);
  cout<<list1.size()<<endl;
  list1.print("name");
  list1.insertEnd(4);
  cout<<list1.size()<<endl;
  list1.print("name");
  
  cout<<endl;
  cout<<"get"<<endl;
  cout<<list1.getFirst()<<endl;
  list1.print("name");

  cout<<list1.getLast()<<endl;
  cout<<list1.getAt(3)<<endl;
  cout<<list1.find(3)<<endl;

  cout<<endl;
  cout<<"remove"<<endl;
  list1.removeStart();
  list1.print("name");

  list1.removeAt(2);
  list1.print("name");

  list1.removeEnd();
  list1.print("name");

  return 0;
}
