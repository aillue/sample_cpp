
#include "../gtest/gtest.h"

#include <array>

TEST ( array, initialize )
{
	std::array<int, 5> a = {0,1,2,3,5};

	ASSERT_EQ ( 5, a[4] );
}

TEST ( array, size )
{
	std::array<int, 5> a = {0,1,2,3,5};

	ASSERT_EQ ( 5, a.size() );
}


TEST ( array, sort )
{
	std::array<int, 5> a = {5,3,2,1,0};

	std::sort( a.begin(), a.end() );

	ASSERT_EQ ( 5, a[4] );
}

TEST ( array, swap )
{
	std::array<int, 5> a = {5,3,2,1,0};
	std::array<int, 5> b = {0,1,2,3,5};

	a.swap( b );

	ASSERT_EQ ( 5, a[4] );
}
