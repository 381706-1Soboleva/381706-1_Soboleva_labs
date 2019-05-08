
#include "../PLexLib/PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");

	int a = 0, b = 0;
	TPoint A, B(7,4), C(0,15), D(3,17), E;
	cout<<"Òî÷êè:\n";
	cout<<"Ââåäèòå òî÷êó:\n";
	cin>>a>>b;
	cout<<"Âû ââåëè òî÷êó À ñ êîîðäèíàòàìè:\n";
	A.SetX(a);
	A.SetY(b);
	A.show();
	cout<<"Òàêæå åñòü òî÷êè Â è Ñ ñ êîîðäèíàòàìè:\n";
	B.show();
	C.show();
	cout<<"\n\n\n";
	
	cout<<"Îòðåçêè:\n";
	TSection AB(A, B);
	cout<<"Îòðåçîê ÀÂ èìååò êîîðäèíòû:\n";
	AB.show();
	cout<<"\n\n\n";

	cout<<"Ïëåêñû:\n";
	TPlex P, P1(&A, &B);
	TPlex P2(P1);
	cout<<"Áûë ñîçäàí ïëåêñ èç òî÷êè À è Â...\n";
	cout<<"Â ïëåêñ äîáàâëåíà òî÷êà (0, 15)...\n";
	P2.Add(&A, &C);
	cout<<"Â ïëåêñ äîáàâëåíà òî÷êà (3, 17)...\n";
	P2.Add(&C, &D);
	
	cout<<"Ââåäèòå òî÷êó:\n";
	cin>>a>>b;
	cout<<"Â ïëåêñ äîáàâëåíà ââåäåííàÿ òî÷êà... \n";
	E.SetX(a);
	E.SetY(b);
	P2.Add(&B,&E);
	cout<<"Ïîëó÷èëñÿ ïëåêñ: \n";
	P2.show();
	cout<<"\n\n\n";
  return 0;
}
