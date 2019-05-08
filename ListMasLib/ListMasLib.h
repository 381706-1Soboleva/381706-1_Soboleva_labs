#pragma once
#include <iostream>

using namespace std;

template <class T>
class TListMas
{
protected:
  T* mas;
  int* index;
  int start, size, count;

public:
  TListMas<T> (int n = 0);
  TListMas<T> (TListMas &A);
  ~TListMas<T> ();

  void PutStart (T B);
  void PutEnd (T B);
  T GetStart();
  T GetEnd();

  bool IsFull();
  bool IsEmpty();
};
//-------------------------------------------------------------------------------------------------
template <class T>
TListMas<T>::TListMas(int n)
{
  if (n < 0)
    throw -1;
  else if (n == 0)
  {
    size = 0;
    mas = 0;
    index = 0;
    start = -1;
    count = 0;
  }
  else
  {
    size = n;
    mas = new T [size];
    index = new T [size];
    start = -1;
    count = 0;
    for (int i = 0; i < size; i++)
      index [i] = -2;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TListMas<T>::TListMas(TListMas &A)
{
  size = A.size;
  start = A.start;
  count = A.count;
  if (size == 0)
  {
    mas = 0;
    index = 0;
  }
  else
  {
    mas = new T [size];
    index = new T [size];
    for (int i = 0; i < count; i++)
    {
      mas [i] = A.mas [i];
      index [i] = A.index [i];
    }
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TListMas<T>::~TListMas<T>()
{
  if (size != 0)
  {
    delete [] mas;
    size = 0;
  }
  if (count != 0)
  {
    delete [] index;
    count = 0;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TListMas<T>::PutStart(T B)
{
  if (IsFull())
    throw -4;
  else
  {
    for (int i = 0; i < size; i++)
      if (index[i] == -2)
      {
        index[i] = start;
        mas[i] = B;
        start = i;
        count++;
        break;
      }
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TListMas<T>::PutEnd(T B)
{
  if (IsFull())
    throw -4;
  else
  {
    for (int i = 0; i < size; i++)
      if (index[i] == -2)
      {
        mas[i] = B;
        for (int j = 0; j < size; j++)
          if (index[j] == -1)
            index[j] = i;
        index[i] = -1;
        count++;
        break;
      }
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TListMas<T>::GetStart()
{
  if (IsEmpty())
    throw -3;
  else
  {
    T tmp = mas[start];
    int _start = index[start];
    index[start] = -2;
    start = _start;
    count--;
    return tmp;
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TListMas<T>::GetEnd()
{
  if (IsEmpty())
    throw -3;
  else
  {
    int index1 = start;
    int index2 = index[start];
    while (index[index2] != -1)
    {
      index1 = index2;
      index2 = index[index2];
    }
    index[index1] = -1;
    count--;
    return mas[index2];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TListMas<T>::IsEmpty()
{
  return (count == 0);
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TListMas<T>::IsFull()
{
  return (count == size);
}

