#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "../stubs/moduletwo_stub.h"
#include "moduleone.h"


TEST_GROUP(GroupOne)
{
    void setup() {
        /* updater the function pointer for this test group */
        UT_PTR_SET(StStubFunctions::module_two, nsStub::module_two);
    }

    void teardown() {
        mock().checkExpectations();
        mock().removeAllComparatorsAndCopiers();
        mock().clear();
    }
};


TEST(GroupOne, module_one_test)
{
	module_one();
	int module_one_calls_method_in_module_two(int val1);

    LONGS_EQUAL(0, 0);
}

TEST(GroupOne, module_two_test)
{
	int result = 0;

	mock().expectOneCall("module_two")
	    .andReturnValue(100);

	result = module_one_calls_method_in_module_two(12);

    LONGS_EQUAL(100, result);
}
