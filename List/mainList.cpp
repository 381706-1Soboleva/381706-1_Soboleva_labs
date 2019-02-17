#include "ListLib.h"
#include "ElemLib.h"
#include <iostream>
using namespace std;
int main()
{
  TList<int> A;
  A.PutBegin(5);
  A.PutBegin(3);
  A.PutBegin(7);
  int b = A.GetBegin();
  int c = A.GetBegin();
  int d = A.GetEnd();
  cout<<"List from end to begin: "<<d<<" "<<c<<" "<<b<<"\n";
  return 0;
}

