#pragma once
#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
  int size;
  T* m;
  int top;

public:
  TStack<T> (int s = 0);
  TStack<T> (TStack<T> &A);

  void Put(T A);
  T Get();
  bool IsFull();
  bool IsEmpty();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(int s)
{
  if (s < 0)
    throw -1;
  else if (s == 0)
  {
    size = 0;
    top = 0;
    m = 0;
  }
  else
  {
    size = s;
    top = 0;
    m = new T [size];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(TStack<T> &A)
{
  size = A.size;
  top = A.top;
  if (size == 0)
    m = 0;
  else
  {
    m = new T [size];
    for (int i = 0; i < size; i++)
      m[i] = A.m[i];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TStack<T>::Put(T A)
{
  if (IsFull())
    throw -4;// -4-put to full
  else
  {
    m[top] = A;
    top++;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw -3;// -3-get from empty
  else
  {
    top--;
    return m[top];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsFull()
{
  if (top == size)
    return true;
  else
    return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0)
    return true;
  else
    return false;
}