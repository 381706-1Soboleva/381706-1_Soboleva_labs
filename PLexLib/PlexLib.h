#pragma once
#include "PointLib.h"
#include "SectionLib.h"
#include "StackLib.h"

#include <iostream>

using namespace std;


class TPlex: public TPoint
{
protected:
  TPoint *l, *r;

public:
  void SetL (TPoint *_l);
  void SetR (TPoint *_r);
  TPoint* GetL();
  TPoint* GetR();

	TPlex();
  TPlex (TPoint *_l, TPoint *_r);
  TPlex (TPlex& P);

	virtual void show();

  void Add (TPoint *_A, TPoint *_B);
	TPoint* Search(TPoint *A);
	void ChangePl(TPoint *A);

};

//-------------------------------------------------------------------------------------------------
void TPlex::SetL(TPoint* _l)
{
  l = _l;
}
//-------------------------------------------------------------------------------------------------
void TPlex::SetR(TPoint* _r)
{
  r = _r;
}
//-------------------------------------------------------------------------------------------------
TPoint* TPlex::GetL()
{
  return l;
}
//-------------------------------------------------------------------------------------------------
TPoint* TPlex::GetR()
{
  return r;
}
//-------------------------------------------------------------------------------------------------
TPlex::TPlex()
{
	l = NULL;
	r = NULL;
}
//-------------------------------------------------------------------------------------------------
TPlex::TPlex(TPoint *_l, TPoint *_r)
{
  l = _l;
	r = _r;
}
//-------------------------------------------------------------------------------------------------

TPlex::TPlex(TPlex& P)
{
  TPlex *pl, *pr;
	pl = dynamic_cast <TPlex*> (P.l);
	pr = dynamic_cast <TPlex*> (P.r);
	if (pl != 0)
		l = new TPlex(*pl);
	else
		l = new TPoint(*(P.GetL()));
	if (pr != 0)
		r = new TPlex(*pr);
	else
		r = new TPoint(*(P.GetR()));
}
//-------------------------------------------------------------------------------------------------
TPoint* TPlex::Search(TPoint *A)
{
	TPlex *pl, *pr;
	TPoint* res;
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (*l == *A) 
		return l;	
	else if (pl != NULL)
	{
		res = pl->Search(A);
		if (res != NULL)
			return res;
	}
	if (*r == *A) 
		return r;	
	else if (pr != NULL)
	{
		pr->Search(A);
		if (res != NULL)
			return res;
	}
	if ((pr == NULL)&&(pl == NULL))
		return NULL;
}

//-------------------------------------------------------------------------------------------------
/*void TPlex::ChangePl(TPoint *A)
{
	if (Search(A) != NULL)
	{
		if (*l == *A) 
		{
			TPlex *pl = new TPlex (A, A) ;
			l = new TPlex (*pl)	;
		}
		else 
		{
			TPlex* pl = dynamic_cast <TPlex*> (l);
			pl->ChangePl(A);
		}
		if (*r == *A) 
		{
			TPlex *pr = new TPlex (A, A) ;
			l = new TPlex (*pr)	;
		}	
		else 
		{
			TPlex* pr = dynamic_cast <TPlex*> (r);
			pr->ChangePl(A);
		}
	}
}*/
//-------------------------------------------------------------------------------------------------
void TPlex::Add (TPoint* A, TPoint* B)
{
  /*if ((l == 0) && (r == 0))
	{
		l = _A; 
		r = _B;
	}
	else
	{ 
		TStack<TPoint*> s1;
		TStack<TPlex*> s2;
		s1.Put(l);
		s1.Put(r);
		s2.Put(this);
		s2.Put(this);
		bool flag = true;
		while ((flag) && (!s1.IsEmpty()))
		{
			TPoint* p2 = s1.Get();
			TPoint* p1 = s1.Get();
			TPlex *ppar = s2.Get();
			if (*p1 == *_A)
			{
				if (ppar->l  == p1)
					ppar->l = new TPlex (_B, _A);
				else
					ppar->r = new TPlex (_B, _A);
				flag = false;
			}
			else  if (*p1 == *_B)
			{
				if (ppar->l  == p1)
					ppar->l = new TPlex (_A, _B);
				else
					ppar->r = new TPlex (_A, _B);
				flag = false;
			}
			if (*p2 == *_A)
			{
				if (ppar->l  == p2)
					ppar->l = new TPlex (_B, _A);
				else
					ppar->r = new TPlex (_B, _A);
				flag = false;
			}
			else  if (*p2 == *_B)
			{
				if (ppar->l  == p2)
					ppar->l = new TPlex (_A, _B);
				else
					ppar->r = new TPlex (_A, _B);
				flag = false;
			}
			else if ((p1 != NULL)||(p2 != NULL))
			{
				s1.Put(ppar->GetL());
				s1.Put(ppar->GetR());
				s2.Put(ppar);
			}
			else throw -1;
		}
	}*/
}
//-------------------------------------------------------------------------------------------------
void TPlex::show()
{
	TPlex *pl, *pr;
	cout<<"Отрезок\n";
	TSection start(*l, *r);
	start.show();
	pl = dynamic_cast <TPlex*> (l);
	pr = dynamic_cast <TPlex*> (r);
	if (pl != 0)
	{
		cout<<"Слева ";
		pl->show();
	}
	else if (pl == 0)
	{
		cout<<"Слева Tочка:\n";
		l->show();
	}
	if (pr != 0)
	{
		cout<<"Справа ";
		pr->show();
	}
	 else if (pr == 0)
	{
		cout<<"Справа Tочка:\n";
		r->show();
	}
}