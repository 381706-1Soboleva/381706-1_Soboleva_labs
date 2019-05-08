#include "ObrPolLib.h"
#include <iostream>

using namespace std;

int main()
{
  char s[] = "(28-17)*9";
  TString str(s);
  TQueue<char> Q;
  Q = ToObrPol(str);
  cout<<"Your string\n"<< str<<"\nRPN:\n";
  while (!Q.IsEmpty())
    cout<<Q.Get();
  cout<<"="<<Result(Q)<<"\n";
  return 0;
}