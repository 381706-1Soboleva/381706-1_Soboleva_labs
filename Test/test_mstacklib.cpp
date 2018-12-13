#include "MStackLib.h"

#include <gtest.h>

TEST(MStackLib, can_create_default_mstack)
{
	ASSERT_NO_THROW (TMStack<int> s());
}
//-------------------------------------------------------------------------------------------------
TEST(MStackLib, can_create_mstack_with_positive_size_and_n)
{
	ASSERT_NO_THROW (TMStack<int> s(1, 4));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, throws_when_create_mstack_with_negative_size)
{
	ASSERT_ANY_THROW (TMStack<int> s(-8, 4));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, throws_when_create_mstack_with_negative_n)
{
	ASSERT_ANY_THROW (TMStack<int> s(5, -7));
}
//-------------------------------------------------------------------------------------------------
TEST(MStackLib, can_copy_mstack)
{
	TMStack<int> A;
	ASSERT_NO_THROW (TMStack<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, can_put_to_mstack)
{
	TMStack<int> A(4,5);
	ASSERT_NO_THROW (A.Put(2,7));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, throws_when_put_to_full_mstack)
{
	TMStack<int> A(1,1);
	A.Put(0,5);
	ASSERT_ANY_THROW (A.Put(0,7));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, can_get_from_mstack)
{
	TMStack<int> A(1,4);
	A.Put(0,17);
	ASSERT_NO_THROW (A.Get(0));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, throws_when_get_from_empty_mstack)
{
	TMStack<int> A(1,8);
	ASSERT_ANY_THROW (A.Get(0));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, get_gives_right_answer)
{
	TMStack<int> A(2,3);
	A.Put(0,5);
	EXPECT_EQ (5, A.Get(0));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, can_countfree_mstack)
{
	TMStack<int> A(2,3);
	int k;
	ASSERT_NO_THROW (k = A.CountFree());
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, countfree_gives_right_answer)
{
	TMStack<int> A(2,3);
	int k;
	A.Put(0,7);
	A.Put(1,2);
	EXPECT_EQ (1, A.CountFree());
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, can_repack_mstack)
{
	TMStack<int> A(2,4);
	A.Put(0,17);
	ASSERT_NO_THROW (A.Repack(1));
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, isempty_gives_right_answer)
{
	TMStack<int> A(2,4);
	EXPECT_EQ (true, A.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (MStackLib, isfull_gives_right_answer)
{
	TMStack<int> A(1,1);
	A.Put(0,5);
	EXPECT_EQ (true, A.IsFull());
}