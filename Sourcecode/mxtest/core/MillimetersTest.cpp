#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mx/core/Elements.h"
#include <sstream>

using namespace mx::core;

TEST( Test01, Millimeters )
{
	std::string indentString( INDENT );
	MillimetersValue value1{ 1.1 };
	MillimetersValue value2{ 2.2 };
	Millimeters object1;
	Millimeters object2( value2 );
	std::stringstream default_constructed;
	object1.toStream( default_constructed, 0 );
	std::stringstream object2_stream;
	object2.toStream( object2_stream, 2 );
	std::string expected = R"(<millimeters>0</millimeters>)";
	std::string actual = default_constructed.str();
	CHECK_EQUAL( expected, actual )
	expected = indentString+indentString+R"(<millimeters>2.2</millimeters>)";
	actual = object2_stream.str();
	CHECK_EQUAL( expected, actual )
	value1 = object2.getValue();
	object1.setValue( value1 );
	std::stringstream o1;	std::stringstream o2;	bool isOneLineOnly = false;
	object1.streamContents( o1, 0, isOneLineOnly );
	object2.streamContents( o2, 0, isOneLineOnly );
	CHECK( isOneLineOnly )
	CHECK_EQUAL( o1.str(), o2.str() )
}

#endif
