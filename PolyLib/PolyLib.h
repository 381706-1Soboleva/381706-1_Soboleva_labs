#pragma once
#include "MonoLib.h"
using namespace std;

class TPolynom
{
protected:
  TMonom *start;
  int n;          
  int size;      

public:
  TPolynom(int _n = 3);
  TPolynom(TPolynom &p);
  ~TPolynom();

  int GetSize();
  TMonom* GetStart();

  TPolynom operator-(TPolynom &p);
  TPolynom operator+(TPolynom &p);
  TPolynom& operator=(const TPolynom &p);
  bool operator==(const TPolynom &p);
  TPolynom operator*(TPolynom &p);
  TPolynom& operator+=(TMonom &m);
  TPolynom& operator-=(TMonom &m);

};