#pragma once
#include <iostream>
#include "StackLib.h"

using namespace std;

template <class T>
class TQueue: public TStack<T>
{
protected:
  int start;
  
public:
  TQueue<T> (int _size = 0);
  TQueue<T> (TQueue <T> &A);
  ~TQueue<T> ();

  void Put(T A);
  T Get();
  bool IsFull();
  bool IsEmpty();
  T Start();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int _size): TStack<T>(_size)
{
  if (_size >= 0)
  {
    this->size = _size;
    this->m = new T [_size];
    this->top = 0;
    start = 0;
  }
  else throw -1;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(TQueue <T> &A): TStack<T>(A.size)
{
  start = 0;
  this->size = A.size;
  this->top = A.top;
  this->m = new T [A.size];
  for (int i = 0 ; i < this->size; i++)
    this->m[i] = A.m[i];
}
//-------------------------------------------------------------------------------------------------
template <class T>
TQueue<T>::~TQueue<T> ()
{
  start = size = 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TQueue<T>::IsFull()
{
  if (this->top - start == this->size)
    return true;
  else return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TQueue<T>::IsEmpty()
{
  if (this->top == start)
    return true;
  else return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TQueue<T>::Put(T A)
{
  if (IsFull())
    throw -4;
  else
  {
    this->m[start + this->top] = A;
    this->top++;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw -3;
  else
  {
    start++;
    return this->m[start-1];
    this->top++;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TQueue<T>::Start()
{
  if (IsEmpty())
    throw -3;
  else
  {
    return this->m[start];
  }
}
