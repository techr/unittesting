#include "CppUTestExt/MockSupport.h"
#include "moduletwo_stub.h"

/* Implement Stubs for mock calls */
namespace nsStub
{
int module_two(int intVal)
{
    mock().actualCall("module_two");
    return mock().returnValue().getIntValue();
}


};

/* Implement for actual production code calls */
namespace nsProduction
{

/* DO NOT include below files in makefile */

#include "../../src/moduletwo.c"  // This makes it nsProduction::FUNCTIONNAME(FUNCTION_PARAMs) for testing

};

/* Declare Function pointers for each production code.
 * Should be updated in each TEST_GROUP::setup().
 *
 *  */

int (*StStubFunctions::module_two)(int);


/** Wrappers to be linked in place of original functions.
 */
extern "C" int module_two(int intVal)
{
    return StStubFunctions::module_two(intVal);
}
