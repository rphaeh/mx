#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"
#include "mxtest/core/NoteheadTextTest.h"
#include "mxtest/core/MidiInstrumentTest.h"


using namespace mx::core;
using namespace std;
using namespace MxTestHelpers;

TEST( Test01, NoteheadText )
{
    variant v = variant::one;
	NoteheadTextPtr object = tgenNoteheadText( v );
	stringstream expected;
	tgenNoteheadTextExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, NoteheadText )
{
    variant v = variant::two;
	NoteheadTextPtr object = tgenNoteheadText( v );
	stringstream expected;
	tgenNoteheadTextExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, NoteheadText )
{
    variant v = variant::three;
	NoteheadTextPtr object = tgenNoteheadText( v );
	stringstream expected;
	tgenNoteheadTextExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace MxTestHelpers
{
    NoteheadTextPtr tgenNoteheadText( variant v )
    {
        NoteheadTextPtr o = makeNoteheadText();
        switch ( v )
        {
            case variant::one:
            {
                
            }
                break;
            case variant::two:
            {
                o->getDisplayText()->setValue( XsString( "B" ) );
                o->getAccidentalText()->setValue( AccidentalValue::koron );
            }
                break;
            case variant::three:
            {
                o->getDisplayText()->setValue( XsString( "C" ) );
                o->getAccidentalText()->setValue( AccidentalValue::sharp );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenNoteheadTextExpected( std::ostream& os, int i, variant v )
    {
        
        switch ( v )
        {
            case variant::one:
            {
                streamLine( os, i, R"(<notehead-text>)" );
                streamLine( os, i+1, R"(<display-text></display-text>)" );
                streamLine( os, i+1, R"(<accidental-text>natural</accidental-text>)" );
                streamLine( os, i, R"(</notehead-text>)", false );
            }
                break;
            case variant::two:
            {
                streamLine( os, i, R"(<notehead-text>)" );
                streamLine( os, i+1, R"(<display-text>B</display-text>)" );
                streamLine( os, i+1, R"(<accidental-text>koron</accidental-text>)" );
                streamLine( os, i, R"(</notehead-text>)", false );
            }
                break;
            case variant::three:
            {
                streamLine( os, i, R"(<notehead-text>)" );
                streamLine( os, i+1, R"(<display-text>C</display-text>)" );
                streamLine( os, i+1, R"(<accidental-text>sharp</accidental-text>)" );
                streamLine( os, i, R"(</notehead-text>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
