#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "../stubs/moduletwo_stub.h"


TEST_GROUP(GroupTwo)
{
    void setup() {
        /* updater the function pointer for this test group */
        UT_PTR_SET(StStubFunctions::module_two, nsProduction::module_two);
    }

    void teardown() {
        mock().checkExpectations();
        mock().removeAllComparatorsAndCopiers();
        mock().clear();
    }
};


TEST(GroupTwo, module_two_test)
{
	int result = module_two(10);
    LONGS_EQUAL(20, result);
}
