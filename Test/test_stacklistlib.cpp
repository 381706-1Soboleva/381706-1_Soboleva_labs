#include "gtest.h"
#include "StackListLib.h"

TEST(TStackList, can_create_stack)
{
  ASSERT_NO_THROW(TStackList<int> A);
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_create_with_parametr)
{
  ASSERT_NO_THROW(TStackList<int> A(3));
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, throws_with_negative_size)
{
  ASSERT_ANY_THROW(TStackList<int> A(-1));
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_delete_stack)
{
  TStackList<int> A;
  A.Put(15);
  ASSERT_NO_THROW(A.~TStackList());
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_create_copy)
{
  TStackList<int> S(1);
  ASSERT_NO_THROW(TStackList<int> A(S));
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_get_size)
{
  TStackList<int> S(15);
  ASSERT_EQ(S.GetSize(), 15);
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_get_count)
{
  TStackList<int> S(5);
  S.Put(1);
  S.Put(2);
  ASSERT_EQ(S.GetCount(), 2);
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_put)
{
  TStackList<int> A;

  ASSERT_NO_THROW(A.Put(43));
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, throws_when_in_full_stack_put_elem)
{
  TStackList<int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, can_get)
{
  TStackList<int> A;
  A.Put(4);
  EXPECT_EQ(4, A.Get());
}

//-------------------------------------------------------------------------------------------------
TEST(TStackList, throws_when_get_from_empty_stack)
{
  TStackList <int> S(5);
  ASSERT_ANY_THROW(S.Get());
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, isempty_gives_right_answer)
{
  TStackList<int> S(5);
  ASSERT_TRUE(S.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST(TStackList, isempty_gives_right_answer_2)
{
  TStackList<int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}
