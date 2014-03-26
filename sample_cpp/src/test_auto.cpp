
#include "../gtest/gtest.h"

#include <array>

TEST ( auto, set )
{
	auto a = '1';

	ASSERT_NE ( 1, a );

	ASSERT_EQ ( '1', a );
}

TEST ( decltype, set )
{
	int a;

	decltype( a ) b = 1.0f; // 1.0fは、aの型(int)になってbに代入される

	ASSERT_EQ ( 1, b );
}

int a;
decltype( a ) func()
{
	return 2.0f;   // 0.0fは、aの型(int)になって返される
}

TEST ( decltype, func )
{
	ASSERT_EQ ( 2, func() );
}
