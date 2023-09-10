#include <iostream>

using namespace std;

int main(){
  
  int x[3] = {1,2,3};
  int *q1, *q2, *q3;
  int k;

  q1 = x;
  q1 = q1 + 2;
  cout<<*q1<<endl;
  q1 = q1-1;
  cout<<*q1<<endl;
  q2 = x + 2;
  q3 = &x[0];
  k = q2 - q3;
  cout << k << endl;

  return 0;
}
