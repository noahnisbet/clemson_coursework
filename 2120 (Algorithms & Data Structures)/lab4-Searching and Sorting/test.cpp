#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> x(5,6);
  for (int i=0; i< x.size(); i++)
    {
      cout<<x[i]<<" ";
    }
  cout<<endl<<endl;

  cout<<x[7];
  
  return 0;
}
