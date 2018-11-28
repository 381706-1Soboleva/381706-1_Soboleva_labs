#include "VectorLib.h"

#include <iostream>

using namespace std;
void main()
{
	TVector<int> A(3), B(A);
	if (A==B) 
		for (int i=0; i<3; i++)
			A[i]=i;
	cout<<A<<"\n";
	B=A+1;
	cout<<B<<"\n";
	cout<<A*B<<"\n";
}
