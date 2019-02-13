#include <iostream>
#include "NewStackLib.h"

using namespace std;

template <class T>
class TMStack
{
protected:
  int n;
  int size;
  T* mas;
  TNewStack<T>** m;

public:
  TMStack<T> (int _n = 0, int l = 0);
  TMStack<T> (TMStack<T> &A);

  T Get (int i);
  void Put (int i, T A);

  bool IsFull();
  bool IsEmpty();

  int CountFree();
  void Repack(int k);
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack (int _n, int l)
{
  if (_n < 0 || l < 0)
    throw -1;
  else if ((_n == 0) && (l == 0))
  {
    n = 0;
    size = 0;
    mas = 0;
    m = 0;
  }
  else
  {
    n = _n;
    size = l;
    mas = new T [size];
    for (int i = 0; i < size; i++)
      mas[i] = 0;
    int *A = new int [n];
    T** B = new T* [n];
    for (int i = 0; i < n; i++)
      A[i] = (int) size / n; 
    A[n - 1] += size % n;
    B[0] = mas;
    for (int i = 1; i < n; i++)
      B[i] = A[i - 1] + B [i - 1];
    m = new TNewStack<T>*[n];
    for (int i = 0; i < n; i++)
      m[i] = new TNewStack<T>(A[i], B[i]);
  }

}
//-------------------------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack (TMStack<T> &C)
{
  n = C.n;
  size = C.size;
  if (size == 0)
  {
    mas = 0;
    m = 0;
  }
  else
  {
    mas = new T [size];
    for (int i = 0; i < size; i++)
      mas[i] = C.mas[i];
    m = new TNewStack<T>* [n];
    int *A = new int [n];
    T** B = new T* [n];
    for (int i = 0; i < n; i++)
      A[i] = C.m[i]->GetSize();
    B[0] = mas;
    for (int i = 1; i < n; i++)
      B[i] = A[i - 1] + B [i - 1];
    m = new TNewStack<T>*[n];
    for (int i = 0; i < n; i++)
      m[i] = new TNewStack<T>(*C.m[i]);
  }
}

//-------------------------------------------------------------------------------------------------
template <class T>
int TMStack<T>::CountFree ()
{
  int count = 0;
  for (int i = 0; i < n; i++)
    count += m[i]->CountFreeE();
  return count;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Repack(int k)
{
  int fm = CountFree();
  if (fm == 0)
    throw -4;
  else
  {
    int* new_size = new int [n];
    T** new_start = new T* [n];
    T** old_start = new T* [n];
    for (int i = 0; i < n; i++)
      new_size[i] = (int)(fm / n) + m[i]->GetSize();
    new_size[k] += fm % n;
    new_start[0] = old_start[0] = mas;
    for (int i = 1; i < n; i++)
    {
      new_start[i] = new_start[i - 1] + new_size[i - 1];
      old_start[i] = old_start[i -1] + m[i-1]->GetSize();
    }
    for (int i = 0; i < n; i++)
    {
      if (new_start[i] <= old_start[i])
        for (int j = 0; j < m[i]->GetTop(); j++)
          new_start[i][j] = old_start[i][j];
      else
      {
        int s = i + 1;
        for (s ; s < n; s++)
          if (new_start[s] <= old_start[s])
            break;
        for (int j = s - 1; j >= i; j--)
          for (int r = (m[i]->GetTop()) - 1; r >= 0; r--)
            new_start[j][r] = old_start[j][r];
        i = s - 1;
      }
    }
    for (int i = 0; i < n; i++)
      m[i]->SetM(new_size[i], new_start[i]);
    delete [] new_size;
    delete [] new_start;
    delete [] old_start;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TMStack<T>::Get (int i)
{
  return m[i]->Get();
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Put (int i, T A)
{
  return m[i]->PutTop(A);
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsFull()
{
  if (CountFree() == 0)
    return true;
  else return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsEmpty()
{
  if (CountFree() == size)
    return true;
  else return false;
}
