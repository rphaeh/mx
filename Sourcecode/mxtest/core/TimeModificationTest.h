#pragma once
#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"

namespace MxTestHelpers
{
    mx::core::NormalTypeNormalDotGroupPtr tgenNormalTypeNormalDotGroup( variant v );
    mx::core::TimeModificationPtr tgenTimeModification( variant v );
    void tgenTimeModificationExpected( std::ostream& os, int indentLevel, variant v );
}

#endif
