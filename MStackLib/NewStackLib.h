#include <iostream>
#include "StackLib.h"

using namespace std;

template <class T>
class TNewStack: public TStack<T>
{
public:
  TNewStack<T> (int n, T* mas);
  TNewStack<T> (TNewStack<T> &A);

  T GetTop();
  void PutTop(T A);
  int CountFreeE();
  void SetM (int n, T* mas);
  int GetSize();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack (int n, T* mas)
{
  this->size = n;
  this->m = mas;
  this->top = 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack (TNewStack<T> &A)
{
  this->size = A.size;
  this->m = A.m;
  this->top = A.top;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TNewStack<T>::SetM (int n, T* mas)
{
  this->size = n;
  this->m = mas;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetSize ()
{
  return this->size;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TNewStack<T>::GetTop ()
{
  return this->top;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TNewStack<T>::PutTop (T A)
{
  return this->Put(A);
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TNewStack<T>::CountFreeE ()
{
  return (this->size) - (this->top);
}