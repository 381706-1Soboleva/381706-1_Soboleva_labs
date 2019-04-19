#include "TTElemLib.h"
#include <iostream>
#include <locale>

using namespace std;

template <class T>
class TTreeTab
{
protected:
	TTElem<T> not_found, ;
	TTElem<T>* mas;
	int count;

public:
	void SetSize (int _size);
	TTElem<T>* GetMas();
	int GetCount();

	TTreeTab (string* _key, int* _data, int _size);
	TTreeTab (int _size = 0);
	TTreeTab (TTreeTab& A);

	void GetRoot();
	void Repack();
	void Put (string _key, T _data);
	void Put (TTElem<T> A);
	void Del (string _key);
	TTElem<T>& Search (string _key);
	T operator[](string _key);
	void Resize();
	bool IsFull ();
	bool IsEmpty();

  friend ostream & operator<<( ostream &out, TTreeTab &t)
  {
    for (int i = 0; i < t.GetCount(); i++)
      out<<t.mas[i]<<"\n";
    return out;
  }

};

//-------------------------------------------------------------------------------------------------
template <class T>
void TTreeTab<T>::SetCount(int _count)
{
	count = _count;
}

//-------------------------------------------------------------------------------------------------
template <class T>
int TTreeTab<T>::GetCount()
{
	return count;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTElem<T>* TTreeTab<T>::GetMas()
{
	return mas;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTreeTab<T>::TTreeTab(string* _key, int* _data, int _size)
{
	count = 0;
	root = new TElem(_key[0], _data[0]);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTreeTab<T>::TTreeTab(int _size)
{
	if (_size < 0)
		throw -1;
	else
	{
		size = _size;
		mas = new TTElem<T>[size];
		count = 0;
		for (int i = count; i < size; i++)
			mas[i] = not_found;
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTreeTab<T>::TTreeTab(TTreeTab& A)
{
	size = A.size;
	count = A.count;
	mas = new TTElem<T> [size];
	for (int i = 0; i < count; i++)
		mas[i] = A.mas[i];
	for (int i = count; i < size; i++)
		mas[i] = not_found;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TTreeTab<T>::Index (string _key)
{
	if (IsEmpty())
		return 0;
	int left = 0, right = count, cur = (count)/2 ;
	while (right - left != 1)
	{
		if (mas[cur].GetKey() > _key)
		{
			right = cur;
			cur = (left + right)/2;
		}
		else if (mas[cur].GetKey() < _key)
		{
			left = cur;
			cur = (left + right +1)/2;
		}
		else return cur;
	}
 return cur;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TTreeTab<T>::Put(string _key, T _data)
{
	TTElem<T> tmp(_key, _data);
	int ind = Index(_key);
	if (IsFull())
		Resize();
	try
	{
		if (Search(_key) != not_found)
			throw -1;
		else
		{
			for (int i = count; i > ind; i--)
				mas[i] = mas[i - 1];
			mas[ind] = tmp;
			count++;
		}
	}
	catch (...)
	{
		cout<<"Ключи не могут повтряться!\n";
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TTreeTab<T>::Put(TTElem<T> A)
{
	int ind = Index(A.GetKey());
	if (IsFull())
		Resize();
	try
	{
		if (Search(A.GetKey()) != not_found)
			throw -1;
		else
		{
			for (int i = count; i > ind; i--)
				mas[i] = mas[i-1];
			mas[ind] = A;
			count++;
		}
	}
	catch (...)
	{
		cout<<"Ключи не могут повтряться!\n";
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TTreeTab<T>::Del(string _key)
{
	try
	{
		if (Search(_key) == not_found)
			throw -1;
		else
		{
			int ind = Index(_key);
			Resize();
			for (int i = ind; i < count; i++)
				mas[i] = mas[i+1];
			mas[count] = not_found;
			count--;
		}
	}
	catch(...)
	{
		cout<<"Нельзя удалить несуществующий элемент!\n";
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTElem<T>& TTreeTab<T>::Search(string _key)
{
	int ind = Index(_key);
	if (IsEmpty())
		return not_found;
	if (mas[ind].GetKey() == _key)
		return mas[ind];
	else return not_found;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TTreeTab<T>::operator [] (string _key)
{
	TTElem<T>& tmp = Search(_key);
	if (tmp == not_found)
	{
		if (IsFull())
			Resize();
		else
		{
			TTElem<T> B(_key, NULL);
			int ind = Index (B.GetKey());
			Put(B);
			count++;
			return mas[ind].GetData();
		}
	}
	else return tmp.GetData();
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TTreeTab<T>::Resize()
{
	size = size + 10;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TTreeTab<T>::IsFull()
{
	return (size == count);
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TTreeTab<T>::IsEmpty()
{
	return (count == 0);
}