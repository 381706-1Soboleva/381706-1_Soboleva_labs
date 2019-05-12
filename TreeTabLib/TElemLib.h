#include <string>

using namespace std;

template <class T>
class TElem
{
public:
	string key;
	T data;

	TElem (string _key = "", T _data = 0);
	TElem (TElem &A);
	TElem& operator = (TElem &A);
	bool operator == (TElem &A);
	bool operator != (TElem &A);

	template <class T1>
	friend istream & operator>>( istream &in, TElem<T1> &t)
  {
    in>>t.key;
		in>>t.data;
    return in;
  }

	template <class T1>
  friend ostream & operator<<( ostream &out, TElem<T1> &t)
  {    
		out<<t.GetKey()<<"\t";
		out<<t.GetData()<<"\t";
    return out;
  }
};

//-------------------------------------------------------------------------------------------------
template <class T>
TElem<T>::TElem (string _key, T _data)
{
	key = _key;
	data = _data;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(TElem &A)
{
	key = A.key;
	data = A.data;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TElem<T>& TElem<T>::operator = (TElem &A)
{
	key = A.key;
	data = A.data;
	return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TElem<T>::operator == (TElem &A)
{
	return ((key == A.key) && (data == A.data));
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TElem<T>::operator != (TElem &A)
{
	return ((key != A.key) || (data != A.data));
}