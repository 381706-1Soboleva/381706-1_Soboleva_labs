#include "MStackLib.h"
#include <iostream>
using namespace std;
int main()
{
  TMStack<int> A(3,6);
  
  A.Put(1,7);
  A.Put(1,4);
  A.Repack(1);
  A.Put(1,17);
  int a = A.CountFree();
  cout<<"Free cells left: "<<a<<"\n";
  cout<<"Last element in first stack: "<<A.Get(1)<<"\n";
  return 0;
}