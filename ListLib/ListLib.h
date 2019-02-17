#pragma once
#include <iostream>
#include "ElemLib.h"

using namespace std;

template <class T>
class TList
{
protected:
  TElem<T>* begin;

public:
  TList<T> ();
  TList<T> (TList<T>& A);
  ~TList<T> ();

  void PutBegin(T A);
  void PutEnd(T A);
  void Put(int _n, T elem);

  T GetBegin();
  T GetEnd();
  T Get(int _n);
  int GetCount();

  bool IsFull();
  bool IsEmpty();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TList<T>::TList()
{
  begin = 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &A)
{
  TElem<T> *a = A.begin, *b;
  if (A.begin == 0)
    begin = 0;
  else
  {
    begin = A.begin;
    b = begin;
    while (a->GetNext() != 0)
    {
      b->SetNext(new TElem<T>(*a->GetNext()));
      a = a->GetNext();
      b = b->GetNext();
    }
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TList<T>::~TList()
{
 while (begin != 0)
  {
    TElem<T>* temp = begin;
    begin = begin->GetNext();
    delete temp;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T A)
{
    TElem<T>* tmp = new TElem<T>(A, begin);
    begin = tmp;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T A)
{
  if (begin != 0)
  {
    TElem<T>* a = begin;
    while (a->GetNext() != 0)
      a->GetNext();
    a->SetNext(new TElem<T> (A, 0));
  }
  else
    begin = new TElem<T>(A, 0);
}
//-------------------------------------------------------------------------------------------------
template<class T>
void TList<T>::Put(int _n, T elem)
{
  if (_n < 1 || _n > (this->GetCount() - 1))
    throw -1;
  else
  {
    int i = 0;
    TElem<T>* a = begin;
    while (i != _n - 1)
    {
      a = a->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(elem, a->GetNext());
    a->SetNext(temp);
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return true;
  else
    return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{
  try
  {
    TElem<T>* A = new TElem<T>();
    if (A == 0)
      return false;
    else return true;
  }
  catch (...)
  {
    return false;
  }
  return true;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{
  TElem<T>* a = begin;
  if (IsEmpty())
    throw -3;
  else
  {
    T tmp = begin->GetD();
    begin = a->GetNext();
    delete a;
    return tmp;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
  if (this->IsEmpty())
    throw -3;
  else
  {
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    if (b == 0)
    {
      T temp = a->TElem<T>::GetD();
      delete a;
      begin = 0;
      return temp;
    }
    else
    {
      while (b->GetNext() != 0)
      {
        a = b;
        b = b->GetNext();
      }
      T temp = b->GetD();
      delete b;
      a->SetNext(0);
      return temp;
    }
  }
}
//-------------------------------------------------------------------------------------------------
template<class T>
T TList<T>::Get(int _n)
{
  if (this->IsEmpty())
    throw -3;
  if (_n < 1 || _n > this->GetCount()-1)
    throw -1;
  else
  {
    int i = 0;
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    while (i != _n - 1)
    {
      a = b;
      b = b->GetNext();
      i++;
    }
    T temp = b->GetD();
    a->SetNext(b->GetNext());
    delete b;
    return temp;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TList<T>::GetCount()
{
  int count = 2;
  
  if (IsEmpty())
    return 0;
  else 
    if (begin->GetNext() == 0)
    {
      return 1;
    }
    else
    {
      TElem<T>* a = begin;
      TElem<T>* b = begin->GetNext();
      while (b->GetNext() != 0)
      {
        a = b;
        b = b->GetNext();
      }
      T temp = b->GetD();
      delete b;
      a->SetNext(0);
      return count;
    }
}
