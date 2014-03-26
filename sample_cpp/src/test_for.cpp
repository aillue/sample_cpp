
#include "../gtest/gtest.h"

#include <array>

#if 1700 <= _MSC_VER // range based loop is not supported by VC2010
TEST ( for, range_for )
{
	int a[] = {1};

	for ( const auto &x : a )
	{
		ASSERT_EQ ( 1, x );
	}
}
#endif