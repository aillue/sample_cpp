
#include "gtest/gtest.h"

#include <memory>

TEST ( shared_ptr, default_value )
{
	std::shared_ptr<int> a;

	ASSERT_EQ ( nullptr, a );
}

TEST ( unique_ptr, unique_ptr )
{
	std::unique_ptr<int> a( new int( 10 ) );

	ASSERT_EQ ( 10, *a );
}

TEST ( unique_ptr, move )
{
	std::unique_ptr<char> a( new char( 'a' ) );
	std::unique_ptr<char> b;

	b = std::move( a );

	ASSERT_EQ ( nullptr, a );
	ASSERT_EQ ( 'a', *b );
}
