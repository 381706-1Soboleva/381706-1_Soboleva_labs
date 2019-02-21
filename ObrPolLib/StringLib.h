#pragma once
#include"QueueLib.h"


class TString
{
protected:
  char* s;
  int len;

public:
  TString();
  TString(TString &A);
  TString(char* s);
  ~TString();
  int GetLen();
  void DeleteS();
  char& operator[](int i);
  friend std::istream& operator>>(std::istream &A, TString &B);
  friend std::ostream& operator<<(std::ostream &A, const TString &B);
};

