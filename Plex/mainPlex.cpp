
#include "PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");

	int a = 0, b = 0;
	TPoint A, B(7,4), C(0,15),D(3,17);
	/*cout<<"������� �����:\n";
	cin>>a>>b;
	cout<<"�� ����� ����� � � ������������:\n";
	A.SetX(a);
	A.SetY(b);
	A.show();
	cout<<"����� ���� ����� � � � � ������������:\n";
	B.show();
	C.show();
	
	TSection AB(A, B);
	cout<<"������� �� ����� ���������:\n";
	AB.show();*/

	TPlex P, P1(&A, &B);
	TPlex P2(P1);
	P2.Add(&A, &C);
	D = *(P2.Search(&C));
	D.show();
	P2.show();
  return 0;
}
