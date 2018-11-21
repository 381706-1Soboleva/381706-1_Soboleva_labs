#pragma once
#include <iostream>

using namespace std;

template <class T>

class TVector
{
protected:
	T* vector;
	int size;
	int StartIndex;
public:
	TVector (int s=10, int si=0);
	TVector (const TVector<T> &v);
	~TVector();

	int GetSize();
  int GetStartIndex();
  T & GetValue (int pos); // ������ � ��������� �������(#�1)
  T & operator[] (int pos); // ������ (#�2)
  bool operator==(const TVector &v); // ��������� (#�3)
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
	template <class T1>
  friend istream & operator>>( istream &in, TVector<T1> &v)
	{
		for (int i = 0; i < v.size; i++)
			in>>v.vector[i];
		return in;
	}
	template <class T1>
  friend ostream & operator<<( ostream &out, const TVector<T1> &v)
	{
		for (int i =0; i < v.size; i++)
			out<<v.vector[i]<<"   ";
		return out;
	}
}; 
//-------------------------------------------------------------------------------------------------
template <class T> 
TVector<T>::TVector(int s, int si)
{
	if (si>=0)
	if (s>=0)
	{
		vector=new T [s];
		size=s;
		StartIndex=si;
	}
	else throw -1;//-1-������ ������� ������ 0
	else throw -2;//-2-��������� ������ ������ 0
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TVector<T>::TVector(const TVector<T> &v)
{
	size=v.size;
	StartIndex=v.StartIndex;
	vector=new T [size];
	for (int i = 0; i<size; i++)
		vector[i]=v.vector[i];
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TVector<T>::~TVector()
{
	delete [] vector;
	size=NULL;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TVector<T>::GetSize() 
{ 
	return size; 
} 
//-------------------------------------------------------------------------------------------------
template <class T>
int TVector<T>::GetStartIndex() 
{ 
	return StartIndex; 
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
	if ((pos>=0)&&(pos<size))
		return vector[pos];
	else throw 1;//1-����� �� ������� �������
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
	else throw 2;//2-������ ������� ��������
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
		StartIndex = v.StartIndex;
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
	else throw 2;
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

	