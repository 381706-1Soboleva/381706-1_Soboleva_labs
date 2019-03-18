#include "StackLib.h"

#include <gtest.h>

TEST(StackLib, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW (TStack<int> s(1));
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW (TStack<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST(StackLib, can_copy_stack)
{
  TStack<int> A;
  ASSERT_NO_THROW (TStack<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST(StackLib, can_delete_stack)
{
  TStack<int> s(1);
  ASSERT_NO_THROW (s.~TStack());
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, can_put_to_stack)
{
  TStack<int> A(4);
  ASSERT_NO_THROW (A.Put(7));
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, throws_when_put_to_full_stack)
{
  TStack<int> A(1);
  A.Put(5);
  ASSERT_ANY_THROW (A.Put(7));
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, can_get_from_stack)
{
  TStack<int> A(4);
  A.Put(0);
  ASSERT_NO_THROW (A.Get());
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, throws_when_get_from_empty_stack)
{
  TStack<int> A(1);
  ASSERT_ANY_THROW (A.Get());
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, get_gives_right_answer)
{
  TStack<int> A(2);
  A.Put(8);
  EXPECT_EQ (8, A.Get());
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, isfull_gives_right_answer)
{
  TStack<int> A(1);
  A.Put(8);
  EXPECT_EQ (true, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (StackLib, isempty_gives_right_answer)
{
  TStack<int> A(1);
  EXPECT_EQ (true, A.IsEmpty());
}


