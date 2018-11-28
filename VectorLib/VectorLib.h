#pragma once
#include <iostream>

using namespace std;

template <class T>

class TVector
{
protected:
	T* vector;
	int size;

public:
	TVector (int s = 2 /*int si = 0*/);
	TVector (const TVector<T> &v);
	~TVector();

	int GetSize();
  T & operator[] (int pos); // ������ (#�2)
  bool operator==(const TVector &v); // ��������� (#�3)
	bool operator!=(const TVector &v);
  TVector<T> & operator= (const TVector &v); // ������������� (#�3)

  // ��������� ��������
  TVector<T> operator+ (const T a); // ��������� ������ (#�2)
  TVector<T> operator- (const T a); // ������� ������ (#�1)
  TVector<T> operator* (const T a); // �������� �� ������ (#�2)

  // ��������� ��������
  TVector<T> operator+ (const TVector &v); // �������� (#�3)
  TVector<T> operator- (const TVector &v); // ��������� (#�4)
  TVector<T> operator* (const TVector &v); // ��������� ������������ (#�5)

  // ����-�����
	
  friend istream & operator>>( istream &in, TVector<T> &v)
	{
		for (int i = 0; i < v.size; i++)
			in>>v.vector[i];
		return in;
	}

  friend ostream & operator<<( ostream &out, const TVector<T> &v)
	{
		for (int i = 0; i < v.size; i++)
			out<<v.vector[i]<<"   ";
		return out;
	}
}; 
//-------------------------------------------------------------------------------------------------
template <class T> 
TVector<T>::TVector(int s)
{
	if (s>=0)
	{
		vector=new T [s];
		size=s;
	}
	else throw -1;// -1 - ������ ������� ������ 0
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TVector<T>::TVector(const TVector<T> &v)
{
	size=v.size;
	vector=new T [size];
	for (int i = 0; i<size; i++)
		vector[i]=v.vector[i];
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TVector<T>::~TVector()
{
	if (size != 0)
	{
		delete [] vector;
		size=NULL;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TVector<T>::GetSize() 
{ 
	return size; 
} 
//-------------------------------------------------------------------------------------------------
/*template <class T>
T& TVector<T>::GetValue(int pos)
{
	if (pos>=0)&&(pos<size)
		return &vector[pos];
	else throw 1;
}*/
//-------------------------------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator [] (int pos)
{
	if (pos>=0)
		if (pos<size)
			return vector[pos];
		else throw 1;//1-����� ��-�� ������,��� ������ �������
	else throw -1;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator == (const TVector<T> &v)
{
	if (size==v.size)
	{
		for (int i = 0 ; i < size; i++)
			if (vector[i]!=v.vector[i])
				return false;
		return true;
	}
	else return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator != (const TVector<T> &v)
{
	if (size==v.size)
	{
		for (int i = 0 ; i < size; i++)
			if (vector[i]!=v.vector[i])
				return true;
		return false;
	}
	else return true;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator = (const TVector<T> &v)
{
	if (this != &v) 
	{
		if (size != v.size) 
		{
			delete[] vector;
			vector = new T[v.size];
		}
		size = v.size; 
		for (int i = 0; i < size; i++) 
			vector[i] = v.vector[i];
 }
 return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator + (const T a)
{
	TVector<T> A;
	A.size=size;
	A.vector=new T [size];
	for (int  i = 0; i < size; i++)
		A.vector[i]=vector[i]+a;
	return A;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator - (const T a)
{
	TVector<T> A;
	A.size=size;
	A.vector=new T [size];
	for (int  i= 0; i < size; i++)
		A.vector[i]=vector[i]-a;
	return A;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator * (const T a)
{
	TVector<T> A;
	A.size=size;
	A.vector=new T [size];
	for (int  i= 0; i < size; i++)
		A.vector[i]=vector[i]*a;
	return A;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator + (const TVector<T> &v)
{
	TVector<T> A;
	A.size=size;
	A.vector=new T [size];
	if (size==v.size)
	{
		for (int i = 0; i < size ; i++)	
			A.vector[i]=vector[i]+v.vector[i];
		return A;
	}
	else throw 2;//2-������ ������� ��������
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator - (const TVector<T> &v)
{
	TVector<T> A;
	A.size=size;
	A.vector=new T [size];
	if (size==v.size)
	{
		for (int i = 0; i < size ; i++)	
			A.vector[i]=vector[i]-v.vector[i];
		return A;
	}
	else throw 2;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator * (const TVector<T> &v)
{
	TVector<T> A;
	A.size=size;
	A.vector=new T [size];
	if (size==v.size)
	{
		for (int i = 0; i < size ; i++)	
			A.vector[i]=vector[i]*v.vector[i];
		return A;
	}
	else throw 2;
}

	