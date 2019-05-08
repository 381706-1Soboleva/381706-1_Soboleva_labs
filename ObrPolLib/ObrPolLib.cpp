#include "ObrPolLib.h"
#include <cstdlib>

int GetPrior(const char op)
{
  switch (op)
  {
  case '(': case ')':
    return 1;
  case '+': case '-':
    return 2;
  case '*':   case '/':
    return 3;
  default:
    throw -1;
  }
}
//-------------------------------------------------------------------------------------------------
bool IsOperation(char a)
{
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}
//--------------------------------------------------------------------------------------------------
TQueue<char> ToObrPol(TString s)
{
  int open = 0;
  int close = 0;
  TQueue<char> Q(s.GetLen() * 3);
  TStack<char> S(s.GetLen() * 3);
  for (int i = 0; i < s.GetLen(); i++)
  {
    if (i == 0)
    {
      if (s[0] == '-')
      {
        Q.Put('[');
        Q.Put('0');
        Q.Put(']');
      }
      else if (IsOperation(s[0]))
        if (GetPrior(s[0]) != 1)
          throw 1;
    }
    if (isdigit(s[i]))
    {
      Q.Put('[');
      while ((i < s.GetLen()) && isdigit(s[i + 1]))
      {
        Q.Put(s[i]);
        i++;
      }
      Q.Put(s[i]);
      Q.Put(']');
    }
    else if (S.IsEmpty() && IsOperation(s[i]))
    {
      S.Put(s[i]);
      if (s[i] == '(')
        open++;
      if (s[i] == ')')
        throw 1;
    }
    else if (IsOperation(s[i]))
    {
      if (s[i] == '(')
      {
        S.Put(s[i]);
        open++;
      }
      else if (s[i] == ')')
      {
        close++;
        while (S.Top() != '(')
          Q.Put(S.Get());
        S.Get();
      }
      else
      {
        int p = GetPrior(s[i]);
        if (p > GetPrior(S.Top()))
          S.Put(s[i]);
        else if (p <= GetPrior(S.Top()))
        {
          while (!S.IsEmpty() && p <= GetPrior(S.Top()))
            Q.Put(S.Get());
          S.Put(s[i]);
        }
      }
    }
    else if (s[i] != '\0')
      throw 1;
  }
  while (!S.IsEmpty())
    Q.Put(S.Get());
  if (open != close)
    throw 1;
  return Q;
}
//-------------------------------------------------------------------------------------------------
double Result(TQueue<char> q)
{
  double res = 0;
  TStack<double> S(q.GetSize());
  if (!IsOperation(q.Top()))
    throw 1;
  int i = 0;
  int dit = 0;
  int t = 0;
  while (!q.IsEmpty())
  {
    i++;
    char A = q.Get();
    if (A == '[')
    {
      dit++;
      A = q.Get();
      double tmp = std::atof(&A);
      while (q.Start() != ']')
      {
        A = q.Get();
        tmp = tmp * 10 + std::atof(&A);
      }
      q.Get();
      S.Put(tmp);
    }
    else if (IsOperation(A))
    {
      double B = S.Get();
      double C = S.Get();
      double D = 0;
      if (A == '+')
        D = C + B;
      if (A == '-')
        D = C - B;
      if (A == '*')
        D = C * B;
      if (A == '/')
        D = C / B;
      S.Put(D);
    }
    else
      throw 1;
    if (i == 2 && dit != 2)
      throw 1;
  }
  res = S.Get();
  if (!S.IsEmpty())
    throw 1;
  return res;
}