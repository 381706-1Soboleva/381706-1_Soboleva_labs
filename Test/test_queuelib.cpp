#include "QueueLib.h"

#include <gtest.h>

TEST(QueueLib, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW (TQueue<int> s(1));
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, throws_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW (TQueue<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST(QueueLib, can_copy_queue)
{
  TQueue<int> A;
  ASSERT_NO_THROW (TQueue<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, can_put_to_queue)
{
  TQueue<int> A(4);
  ASSERT_NO_THROW (A.Put(7));
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, throws_when_put_to_full_queue)
{
  TQueue<int> A(1);
  A.Put(5);
  ASSERT_ANY_THROW (A.Put(7));
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, can_get_from_queue)
{
  TQueue<int> A(4);
  A.Put(0);
  ASSERT_NO_THROW (A.Get());
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, throws_when_get_from_empty_queue)
{
  TQueue<int> A(1);
  ASSERT_ANY_THROW (A.Get());
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, get_gives_right_answer)
{
  TQueue<int> A(2);
  A.Put(8);
  EXPECT_EQ (8, A.Get());
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, isfull_gives_right_answer)
{
  TQueue<int> A(1);
  A.Put(8);
  EXPECT_EQ (true, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (QueueLib, isempty_gives_right_answer)
{
  TQueue<int> A(1);
  EXPECT_EQ (true, A.IsEmpty());
}