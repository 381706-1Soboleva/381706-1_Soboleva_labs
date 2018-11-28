#include "VectorLib.h"
#include <iostream> 

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public: 
	TMatrix<T> (int s=5); // (#�1)
	TMatrix<T> (const TMatrix<T> &mt); // ����������� (#�1)
	~TMatrix();

	TVector<T> operator [] (int i);
	bool operator == (const TMatrix<T> &mt); // ��������� (#�1)
	bool operator != (const TMatrix<T> &mt);
	TMatrix<T>& operator= (const TMatrix<T> &mt); // ������������ (#�2)
	TMatrix<T> operator+ (const TMatrix<T> &mt); // �������� (#�2)
	TMatrix<T> operator- (const TMatrix<T> &mt); // ��������� (#�1)
	TMatrix<T> operator* (const TMatrix<T> &mt); // ��������� (#�2)

	// ���� / �����
	template <class T1>
	friend istream & operator>>( istream &in, TMatrix<T1> &mt) 
	{ 
		for (int i = 0; i < mt.size; i++)
			in>>mt.vector[i];
		return in;
	}
	template <class T1>
	friend ostream & operator<<( ostream &out, const TMatrix<T1> &mt) 
	{
		for (int i = 0; i < mt.size; i++)
			out<<mt.vector[i]<<"\n";
		return out;
	}
};
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> :: TMatrix ( int s ) : TVector<TVector<T>>(s) 
{
	if (s>=0)
		for ( int i = 0; i < s; i++ )
		{
			vector[i] = TVector<T>(s-i);
		}
	else throw -1;
}
//-------------------------------------------------------------------------------------------------
template <class T> // ����������� �����������
TMatrix<T> :: TMatrix ( const TMatrix<T> &mt ) : TVector<TVector<T>>(mt.size)
{
	size = mt.size;
	for (int i = 0; i < size; i++)
	{
		vector[i] = mt.vector[i];
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TMatrix<T>::operator[](int i)
{
	TVector<T> A(size-i);
	if (i >= 0)
		if (i < size)
			A = vector[i];
		else throw 1;
	else throw -1;
	return A;
}
//-------------------------------------------------------------------------------------------------
template <class T> // ����������
TMatrix<T>::~TMatrix()
{
	for (int i = 0; i < size; i++)
		if (vector[i] != 0)
			vector[i].~TVector();
	size=0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator == (const TMatrix<T> &mt)
{
	if (size == mt.size)
	{
		for (int i = 0; i < size; i++)
			if (vector[i]!=mt.vector[i])
				return false;
		return true;
	}
	else return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator != (const TMatrix<T> &mt)
{
	if (size == mt.size)
	{
		for (int i = 0; i < size; i++)
			if (vector[i]!=mt.vector[i])
				return true;
		return False;
	}
	else return true;
}
//-------------------------------------------------------------------------------------------------
template <class T> // ������������
TMatrix<T> & TMatrix<T>::operator=(const TMatrix<T> &mt)
{
	if ( this != &mt ) 
	{
		if ( size != mt.size ) 
		{
			delete[] vector;
			vector = new TVector<T>[mt.size];
		}
		size = mt.size; 
		for (int i = 0; i < size; i++) 
			vector[i] = mt.vector[i];
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T> // ��������
TMatrix<T> TMatrix<T>::operator + (const TMatrix<T> &mt) 
{
	if (size == mt.size)
	{
		TMatrix<T> M;
		M.size=size;
		for (int i = 0; i < size; i++) 
			M.vector[i] = vector[i]+ mt.vector[i];
		return M;
	}
	else throw 2;
}
//-------------------------------------------------------------------------------------------------
template <class T> // ���������
TMatrix<T> TMatrix<T>::operator - (const TMatrix<T> &mt) 
{
	if (size == mt.size)
	{
		TMatrix<T> M;
		M.size=size;
		for (int i = 0; i < size; i++) 
			M.vector[i] = vector[i] - mt.vector[i];
		return M;
	}
	else throw 2;
}
//-------------------------------------------------------------------------------------------------
template <class T> // ���������
TMatrix<T> TMatrix<T>::operator * (const TMatrix<T> &mt) 
{
	if (size == mt.size)
	{
		TMatrix<T> M;
		M.size=size;
		for (int i = 0; i < size; i++) 
			M.vector[i] = vector[i] * mt.vector[i];
		return M;
	}
	else throw 2;
}
// TVector �3 �2 �4 �6
// TMatrix �2 �2 �3 �3
 