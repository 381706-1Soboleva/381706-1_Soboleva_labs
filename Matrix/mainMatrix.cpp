#include "MatrixLib.h"
#include "VectorLib.h"
#include <iostream>

using namespace std;

void main()

{
	TMatrix <int> A(3);
	cin>>A;
	TMatrix <int> B(A);
	cout<<B[1]<<"\n";

}