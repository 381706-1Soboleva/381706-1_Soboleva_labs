#pragma once
#include <iostream>

using namespace std;

template <class T>

class TVector
{
protected:
  T* vector;
  int dlina;
public:
  TVector();
  TVector(TVector &A);
  TVector(T* s, int _dlina);
  ~TVector();

  int GetDlina();
  TVector<T>& DeleteVector();
  TVector<T>& Resize(int n);

  TVector<T> operator+(TVector<T> &A);
  TVector<T> operator-(TVector<T> &A);
  T operator*(TVector<T> &A);
  TVector<T> operator*(T a);
  TVector<T> operator/(T a);
  TVector<T>& operator=(TVector<T> &A);
  T& operator[](int i);

  TVector<T>& Sort();
  TVector<T>& Norm();
  T OneNorm();
  T TwoNorm();
  T GelderNorm(int p);
  T InfNorm();

  template <class T>
  friend std::istream& operator>>(std::istream& A, TVector<T>& B);
  template <class T>
  friend std::ostream& operator<<(std::ostream& A, TVector<T>& B);

};
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector()
{
  vector = 0;
  dlina = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &A)
{
  dlina = A.dlina;
  if (dlina != 0)
  {
    vector = new T [dlina];
    for (int i = 0; i < dlina; i++)
      vector[i] = A.vector[i];
  }
  else
    vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(T* s, int _dlina)
{
  dlina = _dlina;
  vector = new T [dlina];
  for (int i = 0; i < dlina; i++)
    vector[i] = s[i];
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::~TVector()
{
  dlina = 0;
  if (vector != 0)
    delete []vector;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetDlina()
{
  return dlina;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::DeleteVector()
{
  dlina = 0; 
  if (vector != 0)
    delete []vector;
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::Resize(int n)
{
	if ((n == dlina) || (n < 0))
		return *this;
	T* buff = 0;
	if (dlina != 0)
	{
		buff = new T [dlina];
		for (int i = 0; i < dlina; i++)
			buff[i] = vector[i];
		delete []vector;
	}
	if (n > 0)
	{
		
		vector = new T [n];
		for (int i = 0; i < min(n, dlina); i++)
			vector[i] = buff[i];
		if (dlina < n)
		for (int i = dlina; i < n; i++)
			vector[i] = 0;
		dlina = n;
		delete []buff;
	}
	else 
	{
		vector = 0;
		dlina = 0;
	}
	return *this;
	}
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator+(TVector<T> &A)
  {
    TVector<T> S;
    if (dlina == A.dlina)
    {
      if (dlina == 0)
        S.vector = 0;
      else
      {
        S.dlina = dlina;
        S.vector = new T[dlina];
        for (int i = 0; i < dlina; i++)
          S.vector[i] = vector[i] + A.vector[i];
      }
    }
    else
      throw 1;
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator-(TVector<T> &A)
  {
    TVector<T> S;
    if (dlina == A.dlina)
    {
      if (dlina == 0)
        S.vector = 0;
      else
      {
        S.dlina = dlina;
        S.vector = new T[dlina];
        for (int i = 0; i < dlina; i++)
          S.vector[i] = vector[i] - A.vector[i];
      }
    }
    else
      throw 1;
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T TVector<T>::operator*(TVector<T> &A)
  {
    T summ = 0;
    if (dlina == A.dlina)
    {
      if (dlina == 0)
        return summ;
      else
      {
        for (int i = 0; i < dlina; i++)
          summ += vector[i] * A.vector[i];
      }
    }
    else
      throw 1;
    return summ;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator*(T a)
  {
    TVector<T> S;
    if (dlina == 0)
      S.vector = 0;
    else
    {
      S.dlina = dlina;
      S.vector = new T[dlina];
      for (int i = 0; i < dlina; i++)
        S.vector[i] = vector[i] * a;
    }
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator/(T a)
  {
    TVector<T> S;
    if (a != 0)
    {
      if (dlina == 0)
        S.vector = 0;
      else
      {
        S.dlina = dlina;
        S.vector = new T[dlina];
        for (int i = 0; i < dlina; i++)
          S.vector[i] = vector[i] / a;
      }
    }
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T>& TVector<T>::operator=(TVector<T> &A)
  {
    if (this != &A)
    {
      dlina = A.dlina;
      if (dlina != 0)
      {
        if (vector != 0)
          delete []vector;
        vector = new T [dlina];
        for (int i = 0; i < dlina; i++)
          vector[i] = A.vector [i];
      }
      else
      {
        if (vector != 0)
          delete []vector;
        vector = 0;
      }
    }
    return *this;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T& TVector<T>::operator[](int i)
  {
    if (i >= 0 && i <= dlina)
      return vector[i];
    throw 1;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  std::istream& operator>>(std::istream &A, TVector<T> &B)
  {
    std::cout << "Vvedite Vector:\nDlina: "; 
	A >> B.dlina;
    B.vector = new T [B.dlina];
	std::cout << "Znachenie:\n"; 
    for (int i = 0; i < B.dlina; i++)
    {
      A >> B.vector[i];
    }
    return A;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  std::ostream& operator<<(std::ostream &A, TVector<T> &B)
  {
    A << "dlina = "<<B.dlina << "\n";
    for (int i = 0; i < B.dlina; i++)
      A << B.vector[i] << " ";
    return A;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T>& TVector<T>::Sort()
  {
    if (dlina != 0)
    {
      for(int i = 0; i < dlina - 1; i++) 
      {
        T min = vector[i]; 
        int ind = i; 
        for (int j = i + 1 ; j < dlina; j++) 
        { 
          if (vector[ind] > vector[j]) 
          { 
            min = vector[j]; 
            ind = j; 
          }
        } 
        if (i != ind) 
        { 
          T tmp = vector[i]; 
          vector[i] = vector[ind]; 
          vector[ind] = tmp; 
        } 
      } 
    }
    return *this;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T>& TVector<T>::Norm()
  {
    if (dlina != 0)
    {
      T summ = 0;
      for (int i = 0; i < dlina; i++)
        summ += pow(vector[i], 2);
      for (int i = 0; i < dlina; i++)
        vector[i] = vector[i] / pow(summ, 0.5f);
    } 
    return *this;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T TVector<T>::OneNorm()
  {
    if (dlina != 0)
    {
      T rez = 0; 
      for(int i = 0;i < dlina; i++)
        rez += vector[i];
      return rez;
    }
    else 
      return 0;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T TVector<T>::TwoNorm()
  {
    if (dlina != 0)
    {
      T rez = 0;
      for(int i = 0; i < dlina; i++)
        rez += vector[i]*vector[i];
      rez = sqrt(rez);
      return rez;
    }
    else 
      return 0;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T TVector<T>::InfNorm()
  {
    if (dlina != 0)
    {
      T max = vector[0];
      for (int i = 1; i < dlina; i++)
        if (max < vector[i])
          max = vector[i];
      return max;
    }
    else
      return 0;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T TVector<T>::GelderNorm(int p)
  {
    if (dlina != 0)
    {
      T rez = 0, summ = 0;
      for(int i = 0; i < dlina; i++)
        summ += pow(vector[i], p);
      rez = pow(summ, 1.0f/p);
      return rez;
    }
    else 
      return 0;
  }