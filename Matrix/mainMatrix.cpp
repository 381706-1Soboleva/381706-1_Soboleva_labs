#include "MatrixLib.h"
#include <iostream>
using namespace std;
int main()
{
	TMatrix <int> A(3);
	cout<<"Please, input matrix (6 numbers):\n";
	cin>>A;
	cout<<"First vector is: "<<A[0]<<"\n";
	cout<<"Second vector is:"<<A[1]<<"\n";
	cout<<"Third vector is:"<<A[2]<<"\n";
  return 0;
}
