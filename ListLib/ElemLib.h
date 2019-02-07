#pragma once
#include <iostream>

using namespace std;

template <class T>
class TElem
{
protected:
  T d;
  TElem<T>* next;

public:
  TElem<T>(T _d = 0, TElem<T>* n = 0);
  TElem<T>(TElem<T>& A);

  T GetD();
  TElem<T>* GetNext();
  void SetD(T p);
  void SetNext(TElem<T>* n);
};
//-------------------------------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(T _d, TElem<T>* n)
{
  d = _d;
  next = n;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(TElem<T>& A)
{
  d = A.d;
  next = A.next;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TElem<T>::GetD()
{
  return d;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TElem<T>* TElem<T>::GetNext()
{
  return next;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TElem<T>::SetD(T _d)
{
  d = _d;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TElem<T>::SetNext(TElem<T>* n)
{
  next = n;
}
