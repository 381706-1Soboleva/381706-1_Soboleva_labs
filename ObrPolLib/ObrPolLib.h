#pragma once
#include "QueueLib.h"
#include "StringLib.h"


  int GetPrior(const char a);
  bool IsOperation(char a);
  TQueue<char> ToObrPol(TString str);
  double Result(TQueue<char> q);
