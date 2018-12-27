#include "ListMasLib.h"

#include <gtest.h>


TEST(ListMasLib, can_create_listmas)
{
	ASSERT_NO_THROW (TListMas<int> v);
}

//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, can_create_copy_of_listmas)
{
	TListMas<int> c;
	ASSERT_NO_THROW (TListMas<int> v(c));
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, can_put_start)
{
	TListMas<int> c(10);
	ASSERT_NO_THROW (c.PutStart(5));
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, can_get_start)
{
	TListMas<int> c(10);
	c.PutStart(3);
	ASSERT_NO_THROW (int a = c.GetStart());
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, throws_when_get_start_from_empty_listmas)
{
	TListMas<int> c;
	ASSERT_ANY_THROW (int a = c.GetStart());
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, put_start_gives_right_answer)
{
	TListMas<int> c(3);
	c.PutStart(5);
	EXPECT_EQ (5, c.GetStart());
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, can_put_end)
{
	TListMas<int> c(5);
	ASSERT_NO_THROW (c.PutEnd(5));
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, can_get_end)
{
	TListMas<int> c(1);
	c.PutEnd(3);
	ASSERT_NO_THROW (int a = c.GetEnd());
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, throws_when_get_end_from_empty_listmas)
{
	TListMas<int> c;
	ASSERT_ANY_THROW (int a = c.GetEnd());
}
//-------------------------------------------------------------------------------------------------
TEST(ListMasLib, put_end_gives_right_answer)
{
	TListMas<int> c(1);
	c.PutEnd(5);
	EXPECT_EQ (5, c.GetEnd());
}
//-------------------------------------------------------------------------------------------------
TEST (ListMasLib, isfull_gives_right_answer)
{
	TListMas<int> A(1);
	A.PutEnd(8);
	EXPECT_EQ (true, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (ListMasLib, isempty_gives_right_answer)
{
	TListMas<int> A;
	EXPECT_EQ (true, A.IsEmpty());
}
