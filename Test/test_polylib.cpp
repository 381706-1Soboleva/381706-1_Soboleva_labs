#include "gtest.h"
#include "PolyLib.h"

//-------------------------------------------------------------------------------------------------
TEST(TPolynom, can_create_polynom)
{
  ASSERT_NO_THROW(TPolynom P(3));
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, throws_when_create_polynom_with_negative_size)
{
  ASSERT_ANY_THROW(TPolynom P(-3));
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, can_copy_polynom)
{
  TPolynom P(3);
  ASSERT_NO_THROW(TPolynom Q(P));
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, trows_when_add_different_polynoms)
{
  TPolynom P(4);
  TPolynom Q(3);
  ASSERT_ANY_THROW(P + Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, can_add_equal_polynoms)
{
  TPolynom P(3);
  TPolynom Q(3);
  ASSERT_NO_THROW(P + Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, trows_when_minus_different_polynoms)
{
  TPolynom P(4);
  TPolynom Q(3);
  ASSERT_ANY_THROW(P - Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, can_minus_equal_polynoms)
{
  TPolynom P(3);
  TPolynom Q(3);
  ASSERT_NO_THROW(P - Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, assign_operator_polynoms_work)
{
  TPolynom P(3);
  TPolynom Q(3);
  ASSERT_NO_THROW(P = Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, throws_when_assign_monoms_with_different_n)
{
  TPolynom P(4);
  TPolynom Q(3);
  ASSERT_ANY_THROW(P = Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, can_equivalence_polynoms_now)
{
  TPolynom P(3);
  TPolynom Q(3);
  Q = P;
  ASSERT_TRUE(P == Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, trows_when_equivalence_polynoms_with_different_n)
{
  TPolynom M(3);
  TPolynom N(4);
  ASSERT_ANY_THROW(M == N);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, can_multiply_equal_polynoms)
{
  TPolynom P(3);
  TPolynom Q(3);
  ASSERT_NO_THROW(P * Q);
}
//-------------------------------------------------------------------------------------------------
TEST(TPolynom, trows_when_multiply_different_polynoms)
{
  TPolynom P(3);
  TPolynom Q(4);
  ASSERT_ANY_THROW(P * Q);
}

