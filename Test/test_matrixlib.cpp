#include "MatrixLib.h"

#include <gtest.h>
#include <iostream>

TEST(MatrixLib, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW( TMatrix<int> v(1));
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_create_copy_of_matrix)
{
	TMatrix<int> v(1);
	v[0]=1;
  ASSERT_NO_THROW(TMatrix<int> v1(v));
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, throws_when_create_matrix_with_negative_size)
{
  ASSERT_ANY_THROW(TMatrix<int> v(-5));
}
/*//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_get_position)
{
	TMatrix<int> v(1);

	EXPECT_EQ(1,A==v[2]);
}*/
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, throws_when_position_is_negative)
{
	TMatrix<int> v(10);
	TVector<int> a;
  ASSERT_ANY_THROW(a=v[-3]);
}
/*//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_compare_matrixs_of_equal_size)
{
	TMatrix<int> v(1), v1(1);
	v[0]=1;
	v1[0]=1;
	EXPECT_EQ(1,v==v1);
}
//-------------------------------------------------------------------------------------------------
/*TEST(MatrixLib, can_assign_matrix)
{
	TMatrix<int> v(1), v1(1);
	v[0]=1;
	v1=v;
	EXPECT_EQ(1,v1[0]);
}

//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, changes_length_when_assign_matrix)
{
	TMatrix<int> v(1), v1(7);
	v[0]=1;
	v1=v;
	EXPECT_EQ(1,v1.GetSize());
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_sum_number_and_matrix)
{
	TMatrix<int> v(1);
	v[0]=5;
	int a=8;
	v=v+a;
	EXPECT_EQ(13,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_razn_number_and_matrix)
{
	TMatrix<int> v(1);
	v[0]=5;
	int a=8;
	v=v-a;
	EXPECT_EQ(-3,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_mult_number_and_matrix)
{
	TMatrix<int> v(1);
	v[0]=5;
	int a=8;
	v=v*a;
	EXPECT_EQ(40,v[0]);
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_sum_matrix_and_matrix)
{
	TMatrix<int> v(1), v1(1);
	v[0]=5;
	v1[0]=4;
	v=v+v1;
	EXPECT_EQ(9,v[0]);
}*/
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, throws_when_sum_matrixs_with_different_size)
{
	TMatrix<int> v(1), v1(5);
	ASSERT_ANY_THROW(v+v1);
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_sum_matrixs_with_equal_size)
{
	TMatrix<int> v(5), v1(5);
	ASSERT_NO_THROW(v+v1);
}
//-------------------------------------------------------------------------------------------------
/*TEST(MatrixLib, can_razn_matrix_and_matrix)
{
	TMatrix<int> v(1), v1(1);
	v[0]=5;
	v1[0]=4;
	v=v-v1;
	EXPECT_EQ(1,v[0]);
}*/
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, throws_when_razn_matrixs_with_different_size)
{
	TMatrix<int> v(1), v1(5);
	ASSERT_ANY_THROW(v-v1);
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_razn_matrixs_with_equal_size)
{
	TMatrix<int> v(5), v1(5);
	ASSERT_NO_THROW(v-v1);
}
//-------------------------------------------------------------------------------------------------
/*TEST(MatrixLib, can_mult_matrix_and_matrix)
{
	TMatrix<int> v(1), v1(1);
	v[0]=5;
	v1[0]=4;
	v=v*v1;
	EXPECT_EQ(20,v[0]);
}*/
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, throws_when_mult_matrixs_with_different_size)
{
	TMatrix<int> v(1), v1(5);
	ASSERT_ANY_THROW(v*v1);
}
//-------------------------------------------------------------------------------------------------
TEST(MatrixLib, can_mult_matrixs_with_equal_size)
{
	TMatrix<int> v(5), v1(5);
	ASSERT_NO_THROW(v*v1);
}