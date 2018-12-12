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

	void PutBegin(T A);
	void PutEnd(T A);

	T GetBegin();
	T GetEnd();
	T GetElem(T* A);
	T* GetInd(T A);

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
		begin = begin->GetNext();
		delete a;
		return tmp;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
	TElem<T>* a = begin;
	if (IsEmpty())
		throw -3;
	else
	{
		while (a->GetNext() != 0)
			a->GetNext();
		T tmp = a->GetD();
		delete a;
		return tmp;
	}
}
/*
//-------------------------------------------------------------------------------------------------
template <class T>
T TList<T>::GetElem(T* A)
{
	TElem<T>* a = begin, *b;
	T tmp;
	while (a->GetD() != A)
		a->GetNext();
	b = a->GetNext();
	tmp = b->GetD();
	return tmp;
	delete a;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T* TList<T>::GetInd(T A)
{
	TElem<T>* a = begin;
	int k = 0;
	while (k != A)
	{
		a->GetNext();
		k++;
	}	
	return a->GetD();
	delete a;
}
*/