#include <string>
#include "TElemLib.h"

using namespace std;

template <class T>
class TTElem: public TElem<T>
{
public:
	TTElem<T> left, right, parent;
	TTElem (string _key = "", T _data = 0);
	TTElem (TTElem<T> &A);
	TTElem<T>& operator = (TTElem<T> &A);

	template <class T1>
	friend istream & operator>>( istream &in, TTElem<T1> &t)
  {
    in>>t->key;
		in>>t->data;
    return in;
  }

	template <class T1>
  friend ostream & operator<<( ostream &out, TTElem<T1> &t)
  {    
		out<<t->GetKey()<<"\t";
		out<<t->GetData()<<"\t";
    return out;
  }
};

//-------------------------------------------------------------------------------------------------
template <class T>
TTElem<T>::TTElem (string _key, T _data): TElem<T>(_key)
{
	this->key = _key;
	this->data = _data;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTElem<T>::TTElem(TTElem &A): TElem<T>(A._key)
{
	this->key = A.key;
	this->data = A.data;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TTElem<T>& TTElem<T>::operator = (TTElem &A)
{
	this->key = A.key;
	this->data = A.data;
	return *this;
}

