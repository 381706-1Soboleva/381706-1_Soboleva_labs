#include "ListLib.h"

#include <gtest.h>


TEST(ListLib, can_create_list)
{
  ASSERT_NO_THROW (TList<int> v());
}

//-------------------------------------------------------------------------------------------------
TEST(ListLib, can_create_copy_of_list)
{
  TList<int> c;
  ASSERT_NO_THROW (TList<int> v(c));
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, can_delete_list)
{
  TList<int> c;
  c.PutBegin(6);
  ASSERT_NO_THROW (c.~TList());
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, can_put_begin)
{
  TList<int> c;
  ASSERT_NO_THROW (c.PutBegin(5));
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, can_get_begin)
{
  TList<int> c;
  c.PutBegin(3);
  ASSERT_NO_THROW (int a = c.GetBegin());
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, throws_when_get_begin_from_empty_list)
{
  TList<int> c;
  ASSERT_ANY_THROW (int a = c.GetBegin());
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, put_begin_gives_right_answer)
{
  TList<int> c;
  c.PutBegin(5);
  EXPECT_EQ (5, c.GetBegin());
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, can_put_end)
{
  TList<int> c;
  ASSERT_NO_THROW (c.PutEnd(5));
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, can_get_end)
{
  TList<int> c;
  c.PutEnd(3);
  ASSERT_NO_THROW (int a = c.GetEnd());
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, throws_when_get_end_from_empty_list)
{
  TList<int> c;
  ASSERT_ANY_THROW (int a = c.GetEnd());
}
//-------------------------------------------------------------------------------------------------
TEST(ListLib, put_end_gives_right_answer)
{
  TList<int> c;
  c.PutEnd(5);
  EXPECT_EQ (5, c.GetEnd());
}

//-------------------------------------------------------------------------------------------------
TEST (ListLib, isfull_gives_right_answer)
{
  TList<int> A;
  A.PutEnd(8);
  EXPECT_EQ (true, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (ListLib, isempty_gives_right_answer)
{
  TList<int> A;
  EXPECT_EQ (true, A.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (ListLib, can_get_count)
{
  TList<int> A;
  A.PutBegin(5);
  A.PutBegin(3);
  EXPECT_EQ (2, A.GetCount());
}
//-------------------------------------------------------------------------------------------------
TEST (ListLib, can_put)
{
  TList<int> A;
  A.PutBegin(5);
  A.PutBegin(3);
  ASSERT_NO_THROW (A.Put(1,7));
}
//-------------------------------------------------------------------------------------------------
TEST (ListLib, throws_when_get_from_empty)
{
  TList<int> A;
  ASSERT_ANY_THROW (A.Get(2));
}
//-------------------------------------------------------------------------------------------------
TEST (ListLib, can_get)
{
  TList<int> A;
  A.PutBegin(5);
  A.PutBegin(3);
  A.PutBegin(7);
  ASSERT_NO_THROW (A.Get(1));
}

//-------------------------------------------------------------------------------------------------