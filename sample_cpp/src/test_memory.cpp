
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

	a.swap( b ); // nullptr の方で読んでも大丈夫？

	ASSERT_EQ ( 10, *a );
	ASSERT_EQ ( nullptr, b );
}

TEST ( shared_unique_ptr, move_to_shared_ptr_from_unique_ptr )
{
	std::shared_ptr<int> a;
	std::unique_ptr<int> b( new int( 1 ) );

	a = std::move( b );// ok:unique_ptr → shared_ptr (逆はダメ)

	ASSERT_EQ ( 1, *a );
	ASSERT_EQ ( nullptr, b );
}

TEST ( rvalue_reference, move )
{
	std::string a;
	std::string b = "test";

	a = std::move( b );	// b はこれ以降使わないことを明示的に宣言。
	// aへはbの中身がコピーされないで、中のポインタが渡されるように最適化を期待する

	ASSERT_EQ ( "test", a );
}

namespace // ファイル内限定
{
char *func()
{
	char a[10] ;
	strcpy_s( a, 10, "test" );

	return a;
}
}// namespace

TEST ( rvalue_reference, constrain )
{
	char* && value_ref = func();// funcの返り値は関数が返るとともに消えるはずであるが、それをrvalueの参照という形で寿命を保持する

	ASSERT_EQ ( 0, strcmp( "test", value_ref ) );
}
