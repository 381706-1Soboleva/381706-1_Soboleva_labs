#include "StackListLib.h"
#include <iostream>
using namespace std;
int main()
{
  TStackList<int> A;
  cout<<"Is this stacklist empty? \nAnswer: "<<A.IsEmpty()<<"\n";
  A.Put(21);
  A.Put(29);
  A.Put(213);
  cout<<"Stacklist is: "<<A.Get()<<" "<<A.Get()<<" "<<A.Get()<<"\n ";
  return 0;
}