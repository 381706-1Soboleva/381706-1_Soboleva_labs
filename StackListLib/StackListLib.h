#pragma once
#include "ListLib.h"


template <class T>
class TStackList : public TList<T>
{
protected:
  int size;
  int count;

public:

  TStackList<T> (int _size = 10);
  TStackList<T> (TStackList<T> &A);
  ~TStackList<T> ();

  void Put(T A);
  T Get();
  int GetSize();
  int GetCount();
  bool IsEmpty();
  bool IsFull();
};

template <class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
  if (_size <= 0)
    throw -1;
  size = _size;
  count = 0;
}
//-----------------------------------------------------------------
template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
  count = A.GetCount();
}
//-----------------------------------------------------------------
template <class T>
TStackList<T>::~TStackList()
{
  if (size != 0)
    while (this->begin != 0)
  {
    TElem<T>* temp = this->begin;
    this->begin = (this->begin)->GetNext();
    delete temp;
  }
  size = 0;
  count = 0;
}
//-----------------------------------------------------------------
template <class T>
void TStackList<T>::Put(T A)
{
  if (this->IsFull())
    throw 1;
  TList<T>::PutBegin(A);
  count++;
}
//-----------------------------------------------------------------
template <class T>
T TStackList<T>::Get() 
{
  if (this->IsEmpty())
    throw -1;
  return TList<T>::GetBegin();
  count--;
}
//-----------------------------------------------------------------
template <class T>
int TStackList<T>::GetSize() 
{
  return size;
}
//-----------------------------------------------------------------
template<class T>
inline int TStackList<T>::GetCount()
{
  return count;
}
//-----------------------------------------------------------------
template <class T>
bool TStackList<T>::IsEmpty() 
{
  if (count == 0)
    return true;
  return false;
}
//-----------------------------------------------------------------
template<class T>
bool TStackList<T>::IsFull()
{
  if (count == size)
    return true;
  return false;
}
