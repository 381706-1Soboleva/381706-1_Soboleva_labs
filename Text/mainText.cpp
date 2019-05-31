#include <iostream>
#include "TextLib.h"
#include "StringLib.h"

using namespace std;

int main()
{
  
	TString S;
	S = "My string";
	TNode A(S);
	char* C = A.ToStr();
	TString S2(C);
	cout << S2 << endl;
	TText Text;
	cout << "Add string ""My string""" << endl << endl;
	Text.Ins(Text.GetRoot(), S);
	cout << "Printing Text" << endl;
	cout << Text << endl;
	cout << "Add char 'c'" << endl << endl;
	Text.Ins(Text.GetRoot(), "c");
	cout << "The text is:" << endl;
	cout << Text << endl;
	cout << "index for ""c""" << endl << endl;
	int p = Text.FindIndex("str");
	cout << "index = " << p << endl;
	return 0;
}
