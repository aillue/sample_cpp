
#include "gtest/gtest.h"

#include <memory>

TEST ( TestMemory, shared_ptr )
{
	std::shared_ptr<int> a;

	ASSERT_EQ ( nullptr, a );
}

TEST ( TestMemory, unique_ptr )
{
	std::unique_ptr<int> a( new int( 10 ) );

	ASSERT_EQ ( 10, *a );
}
