#include "VectorLib.h"

#include <gtest.h>

TEST(VectorLib, can_create_vector_with_positive_size)
{
	ASSERT_NO_THROW( TVector<int> v(1));
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_create_copy_of_vector)
{
	TVector<int> v(2);
	v[0]=1;
	v[1]=2;	
  ASSERT_NO_THROW(TVector<int> v1(v));
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, throws_when_create_vector_with_negative_size)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_get_size)
{
	TVector<int> v(1);
	EXPECT_EQ(1,v.GetSize());
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_get_position)
{
	TVector<int> v(10);
	for (int i = 0; i < v.GetSize(); i++)
		v[i]=i;
	EXPECT_EQ(5,v[5]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, throws_when_position_is_negative)
{
	TVector<int> v(10);
	int a;
  ASSERT_ANY_THROW(a=v[-3]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_compare_vectors_of_equal_size_1)
{
	TVector<int> v(1), v1(1);
	v[0]=1;
	v1[0]=1;
	EXPECT_EQ(1,v==v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_compare_vectors_of_equal_size_2)
{
	TVector<int> v(1), v1(1);
	v[0]=1;
	v1[0]=2;
	EXPECT_EQ(1,v!=v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_compare_vectors_of_different_size_1)
{
	TVector<int> v(1), v1(2);
	EXPECT_EQ(0,v==v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_compare_vectors_of_different_size_2)
{
	TVector<int> v(1), v1(2);
	EXPECT_EQ(1,v!=v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_assign_vector)
{
	TVector<int> v(1), v1(7);
	v[0]=1;
	v1=v;
	EXPECT_EQ(1,v1[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, changes_length_when_assign_vector)
{
	TVector<int> v(1), v1(7);
	v[0]=1;
	v1=v;
	EXPECT_EQ(1,v1.GetSize());
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_sum_number_and_vector)
{
	TVector<int> v(1);
	v[0]=5;
	int a=8;
	v=v+a;
	EXPECT_EQ(13,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_razn_number_and_vector)
{
	TVector<int> v(1);
	v[0]=5;
	int a=8;
	v=v-a;
	EXPECT_EQ(-3,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_mult_number_and_vector)
{
	TVector<int> v(1);
	v[0]=5;
	int a=8;
	v=v*a;
	EXPECT_EQ(40,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_sum_vector_and_vector)
{
	TVector<int> v(1), v1(1);
	v[0]=5;
	v1[0]=4;
	v=v+v1;
	EXPECT_EQ(9,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, throws_when_sum_vectors_with_different_size)
{
	TVector<int> v(1), v1(5);
	ASSERT_ANY_THROW(v+v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_sum_vectors_with_equal_size)
{
	TVector<int> v(5), v1(5);
	ASSERT_NO_THROW(v+v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_razn_vector_and_vector)
{
	TVector<int> v(1), v1(1);
	v[0]=5;
	v1[0]=4;
	v=v-v1;
	EXPECT_EQ(1,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, throws_when_razn_vectors_with_different_size)
{
	TVector<int> v(1), v1(5);
	ASSERT_ANY_THROW(v-v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_razn_vectors_with_equal_size)
{
	TVector<int> v(5), v1(5);
	ASSERT_NO_THROW(v-v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_mult_vector_and_vector)
{
	TVector<int> v(1), v1(1);
	v[0]=5;
	v1[0]=4;
	v=v*v1;
	EXPECT_EQ(20,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, throws_when_mult_vectors_with_different_size)
{
	TVector<int> v(1), v1(5);
	ASSERT_ANY_THROW(v*v1);
}
//-------------------------------------------------------------------------------------------------
TEST(VectorLib, can_mult_vectors_with_equal_size)
{
	TVector<int> v(5), v1(5);
	ASSERT_NO_THROW(v*v1);
}
