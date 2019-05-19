#include "HashTabLib.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");
  THElem<int> e1("AA", 35), e2("A", 17), e3("C", 76), e4(e1), e5;
  THashTab<int> t1(10);
  
	
  t1.Put(e2);
	t1.Put(e1);
	t1.Put(e3);
	cout<<*t1.mas[0];

	t1.Search("C");

	cout<<"\nПопытка положить элемент с повторяющимся ключом:\n";
	t1.Put(e4);

	t1.Put("AAA", 29);
	cout<<"\nПолучилась таблица:\n"<<t1;
	t1.Del("AA");
	cout<<"\nПопытка удалить несуществующий элемент:\n";
	t1.Del("U");
  return 0;
}
