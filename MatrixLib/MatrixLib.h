#include "VectorLib.h"
#include <iostream> 

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public: 
  TMatrix<T> (int s = 5); 
  TMatrix<T> (const TMatrix<T> &mt); 
  ~TMatrix<T>();

  TVector<T>& operator [] (int i);
  bool operator == (const TMatrix<T> &mt); 
  bool operator != (const TMatrix<T> &mt);
  TMatrix<T>& operator= (const TMatrix<T> &mt);
  TMatrix<T> operator+ (const TMatrix<T> &mt); 
  TMatrix<T> operator- (const TMatrix<T> &mt); 
  TMatrix<T> operator* (const TMatrix<T> &mt);
  TMatrix<T> operator/ (const TMatrix<T> &mt);

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
TMatrix<T> :: TMatrix ( int s ) : TVector<TVector<T> >(s) 
{
  if (s >= 0)
    for ( int i = 0; i < s; i++ )
    {
      this->vector[i] = TVector<T>(s-i);
    }
  else throw -1;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> :: TMatrix ( const TMatrix<T> &mt ) : TVector<TVector<T> >(mt.size)
{
  this->size = mt.size;
  for (int i = 0; i < this->size; i++)
  {
    this->vector[i] = mt.vector[i];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T>& TMatrix<T>::operator[](int i)
{
  if (i >= 0)
    if (i < this->size)
      return this->vector[i];
    else throw 1;
  else throw -1;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T>::~TMatrix()
{
  for (int i = 0; i < this->size; i++)
    if (this->vector[i] != 0)
      this->vector[i].~TVector();
  this->size = 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator == (const TMatrix<T> &mt)
{
  if (this->size == mt.size)
  {
    for (int i = 0; i < this->size; i++)
      if (this->vector[i] != mt.vector[i])
        return false;
    return true;
  }
  else return false;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator != (const TMatrix<T> &mt)
{
  if (this->size == mt.size)
  {
    for (int i = 0; i < this->size; i++)
      if (this->vector[i] != mt.vector[i])
        return true;
    return false;
  }
  else return true;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> & TMatrix<T>::operator=(const TMatrix<T> &mt)
{
  if ( this != &mt ) 
  {
    if ( this->size != mt.size ) 
    {
      delete[] this->vector;
      this->vector = new TVector<T>[mt.size];
    }
    this->size = mt.size; 
    for (int i = 0; i < this->size; i++) 
      this->vector[i] = mt.vector[i];
  }
  return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator + (const TMatrix<T> &mt) 
{
  if (this->size == mt.size)
  {
    TMatrix<T> M;
    M.size = this->size;
    for (int i = 0; i < this->size; i++) 
      M.vector[i] = this->vector[i] + mt.vector[i];
    return M;
  }
  else throw 2;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> TMatrix<T>::operator - (const TMatrix<T> &mt) 
{
  if (this->size == mt.size)
  {
    TMatrix<T> M;
    M.size = this->size;
    for (int i = 0; i < this->size; i++) 
      M.vector[i] = this->vector[i] - mt.vector[i];
    return M;
  }
  else throw 2;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> TMatrix<T>::operator * (const TMatrix<T> &mt) 
{
  if (this->size == mt.size)
  {
    TMatrix<T> M;
    M.size = this->size;
    for (int i = 0; i < this->size; i++) 
      M.vector[i] = this->vector[i] * mt.vector[i];
    return M;
  }
  else throw 2;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> TMatrix<T>::operator / (const TMatrix<T> &mt) 
{
  if (this->size == mt.size)
  {
    TMatrix<T> M;
    M.size = this->size;
    for (int i = 0; i < this->size; i++) 
      M.vector[i] = this->vector[i] / mt.vector[i];
    return M;
  }
  else throw 2;
}

 
