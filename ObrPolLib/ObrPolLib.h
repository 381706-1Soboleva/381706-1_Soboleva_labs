#pragma once
#include "QueueLib.h"
#include "StringLib.h"

int GetPrt(const char op);
bool IsOp(char a);
TQueue<char> ConvertToPol(TString s);
double Rez(TQueue<char> q);
