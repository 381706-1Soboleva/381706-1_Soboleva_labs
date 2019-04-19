#include "SortTabLib.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");
	TSElem<int> e1("A", 35), e2("B", 17), e3("C", 76), e4(e1), e5;
	TSortTab<int> t1(10);
	t1.Put(e2);
	t1.Put(e1);
	t1.Put(e3);
	cout<<t1<<"\n";
	cout<<"������� ������ ������ � ������ �: ...\n";
	t1.Put(e4);
	cout<<"������� ������� ������ � ������ K: ...\n";
	t1.Del("K");
	t1.Del("A");
	cout<<"\n������� ������:\n";
	cin>>e5;
	t1.Put(e5);
	cout<<"���������� �������\n"<<t1<<"\n";
	cout<<"����� �� ����� �:\n"<<t1.Search("C")<<"\n";
	cout<<"������ ������� �\n"<<t1["B"]<<"\n";
	return 0;
}
