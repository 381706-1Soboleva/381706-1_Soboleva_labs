#include "MonoLib.h"

TMonom::TMonom()
{
  next = NULL;
  power = NULL;
  c = 0;
  n = 0;
}// ---------------------------------------------------------------------------

TMonom::TMonom(int _n, int* _power, double _c)
{
  if (_n < 0)
    throw -1;
  else if (_n == 0)
  {
    power = NULL;
    n = _n;
    c = _c;
    next = NULL;
  }
  else
  {
    n = _n;
    c = _c;
    next = NULL;
    power = new int[_n];
    for (int i = 0; i < _n; i++)
    {
      if (_power[i] >= 0)
        power[i] = _power[i];
      else
        throw 2;
    }
  }
}// ---------------------------------------------------------------------------

TMonom::TMonom(const TMonom &A)
{
  n = A.n;
  c = A.c;
  next = A.next;
  power = new int[n];
  for (int i = 0; i < n; i++)
  {
    power[i] = A.power[i];
  }
}// ---------------------------------------------------------------------------

TMonom::~TMonom()
{
  if (power != 0)
    delete[]power;
  n = 0;
  c = 0;
  next = 0;
}// ---------------------------------------------------------------------------

TMonom* TMonom::GetNext()
{
  return next;
}// ---------------------------------------------------------------------------

int* TMonom::GetPower()
{
  return power;
}// ---------------------------------------------------------------------------

double TMonom::GetC()
{
  return c;
}// ---------------------------------------------------------------------------

int TMonom::GetN()
{
  return n;
}// ---------------------------------------------------------------------------

void TMonom::SetNext(TMonom* _next)
{
  next = _next;
}// ---------------------------------------------------------------------------

void TMonom::SetPower(int* _power)
{
  for (int i = 0; i < n; i++)
  {
    if (_power[i] >= 0)
      power[i] = _power[i];
    else
      throw -1;
  }
}// ---------------------------------------------------------------------------

void TMonom::SetC(double _c)
{
  c = _c;
}// ---------------------------------------------------------------------------

void TMonom::SetN(int _n)
{
  if (_n < 0)
    throw -1;
  else if (_n == 0)
  {
    if (power != 0)
      delete[] power;
    power = 0;
    n = 0;
  }
  else
  {
    int *tmp = new int[n];
    for (int i = 0; i < n; i++)
      tmp[i] = power[i];
    delete[]power;
    power = new int[_n];
    int i = 0;
    if (n < _n)
    {
      for (; i < n; i++)
        power[i] = tmp[i];
      for (; i < _n; i++)
        power[i] = 0;
    }
    if (_n < n)
      for (; i < _n; i++)
        power[i] = tmp[i];
    n = _n;
  }
}// ---------------------------------------------------------------------------

TMonom& TMonom::operator=(const TMonom& A)
{
  if (n != A.n)
    throw 2;
  c = A.c;
  n = A.n;
  next = A.next;
  delete[] power;
  power = new int[n];
  for (int i = 0; i < n; i++)
    power[i] = A.power[i];
  return *this;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator+(TMonom& A)
{
  TMonom tmp(A);
  if (n != A.n)
    throw 2;
  if (!(*this == A))
    throw 2;
  tmp.c = c + A.c;
  return tmp;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator+=(TMonom & A)
{
  if (n != A.n)
    throw 2;
  if (!(*this == A))
    throw 2;
  c += A.c;
  return *this;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator-(TMonom& A)
{
  TMonom tmp(A);
  if (n != A.n)
    throw 2;
  if (!(*this == A))
    throw 2;
  tmp.c = c - A.c;
  return tmp;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator-=(TMonom & A)
{
  if (n != A.n)
    throw 2;
  if (!(*this == A))
    throw 2;
  c -= A.c;
  return *this;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator*(const TMonom& A) const
{
  if (n != A.n)
    throw 2;
  TMonom tmp(A);
  tmp.c = c * A.c;
  for (int i = 0; i < n; i++)
    tmp.power[i] = power[i] + A.power[i];
  return tmp;
}// ---------------------------------------------------------------------------

TMonom TMonom::operator*=(TMonom& A)
{
  if (n != A.n)
    throw 2;
  c = c * A.c;
  for (int i = 0; i < n; i++)
    power[i] += A.power[i];
  return *this;
}// ---------------------------------------------------------------------------

bool TMonom::operator==(TMonom& A)
{
  if (n != A.n)
    throw 2;
  for (int i = 0; i < n; i++)
    if (power[i] != A.power[i])
      return false;
  return true;
}// ---------------------------------------------------------------------------

bool TMonom::operator>(TMonom& A)
{
  if (n != A.n)
    throw 2;
  if (*this == A)
    throw 2;
  for (int i = 0; i < n; i++)
  {
    if (power[i] == A.power[i])
      continue;
    else if (power[i] > A.power[i])
      return true;
    else
      return false;
  }
  return true;
}// ---------------------------------------------------------------------------

bool TMonom::operator<(TMonom& A)
{
  if (n != A.n)
    throw 2;
  if (*this == A)
    throw 2;
  for (int i = 0; i < n; i++)
  {
    if (power[i] == A.power[i])
      continue;
    else if (power[i] < A.power[i])
      return true;
    else
      return false;
  }
  if (c > A.c)
    return false;
  return true;
}// ---------------------------------------------------------------------------
