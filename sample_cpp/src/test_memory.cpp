
#include "../gtest/gtest.h"

#include <memory>

TEST ( shared_ptr, default_value )
{
	std::shared_ptr<int> a;

	ASSERT_EQ ( nullptr, a );
}

TEST ( shared_ptr, reset )
{
	std::shared_ptr<float> a( new float( 1.0f ) );

	a.reset();

	ASSERT_EQ ( nullptr, a );
}

TEST ( unique_ptr, move )
{
	std::unique_ptr<char> a( new char( 'a' ) );
	std::unique_ptr<char> b;

	b = std::move( a );

	ASSERT_EQ ( nullptr, a );
	ASSERT_EQ ( 'a', *b );
}

TEST ( unique_ptr, swap )
{
	std::unique_ptr<int> a( new int( 10 ) );
	std::unique_ptr<int> b;

	a.swap( b );

	ASSERT_EQ ( nullptr, a );
	ASSERT_EQ ( 10, *b );

	a.swap( b ); // nullptr �̕��œǂ�ł����v�H

	ASSERT_EQ ( 10, *a );
	ASSERT_EQ ( nullptr, b );
}

TEST ( shared_unique_ptr, move_to_shared_ptr_from_unique_ptr )
{
	std::shared_ptr<int> a;
	std::unique_ptr<int> b( new int( 1 ) );

	a = std::move( b );// ok:unique_ptr �� shared_ptr (�t�̓_��)

	ASSERT_EQ ( 1, *a );
	ASSERT_EQ ( nullptr, b );
}
