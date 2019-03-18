#include <gtest.h>
#include "StringLib.h"
#include "ObrPolLib.h"

//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_check_is_operation)
{
  ASSERT_EQ(1, IsOperation('+'));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_get_priority)
{
  ASSERT_EQ(3, GetPrior('*'));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, throws_when_get_priority_of_uncorrect_symbol)
{
  ASSERT_ANY_THROW(GetPrior('k'));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_add)
{
  char s[] = "2+3";
  TString str(s);
  TQueue<char> Q;
  Q = ToObrPol(str);
  EXPECT_EQ(5, Result(Q));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_substraction)
{
  char s[] = "75-25";
  TString str(s);
  TQueue<char> Q;
  Q = ToObrPol(str);
  EXPECT_EQ(50, Result(Q));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_multiply)
{
  char s[] = "7*8";
  TString str(s);
  TQueue<char> Q;
  Q = ToObrPol(str);
  EXPECT_EQ(56, Result(Q));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_division)
{
  char s[] = "125/5";
  TString str(s);
  TQueue<char> Q;
  Q = ToObrPol(str);
  EXPECT_EQ(25, Result(Q));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, throw_when_math_expression_have_is_uncurrent_symbol)
{
  char s[] = "9!8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ToObrPol(A));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, throw_when_math_expression_have_is_unequal_count_skobok)
{
  char s[] = "(9*8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ToObrPol(A));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, throw_when_queue_is_fuflo)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('&');

  ASSERT_ANY_THROW(Result(B));
}
//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_calculate_several_operation)
{
  char s[] = "5+(13-8)/5";
  TString str(s);
  TQueue<char> Q;
  Q = ToObrPol(str);
  EXPECT_EQ(6, Result(Q));
}//-------------------------------------------------------------------------------------------------
TEST(ObrPol, can_find_res_with_negative_first_number) 
{
  char s[] = "-5+(43+57)/20";
  TString A(s);
  TQueue<char> B;
  B = ToObrPol(A);

  EXPECT_EQ(0, Result(B));
}
