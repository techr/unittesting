#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTest/TestRegistry.h"
#include "CppUTest/TestOutput.h"



TEST_GROUP(GROUP_A)
{
    StringBufferTestOutput *pStringBufferOutput;
    TestResult *pTestResult;

    void setup() {
        pStringBufferOutput = new StringBufferTestOutput();
        pTestResult = new TestResult(*pStringBufferOutput);
    }

    void teardown() {
        if(pStringBufferOutput) {
            delete pStringBufferOutput;
            pStringBufferOutput = 0;
        }
        if(pTestResult) {
            delete pTestResult;
            pTestResult = 0;
        }
        mock().checkExpectations();
        mock().clear();
    }

    void executeTestFromAnotherGroup(){
        TestRegistry *pTestRegistry =  TestRegistry::getCurrentRegistry();
        if(pTestRegistry) {

        	UtestShell *pTestToRun = NULL;
        	pTestToRun = pTestRegistry->findTestWithName("TEST_NAME_FROM_GROUP_B");
            if(pTestToRun) {
                pTestToRun->runOneTest(pTestRegistry->getFirstPlugin(), *pTestResult);
            }
        }
    }
};

TEST(GROUP_A, TEST1)
{
	printf(" calling from TEST1 \n");
	executeTestFromAnotherGroup();	/* Execute Test from another Group */
	// TODO... add further test here....
	CHECK(true);
}


TEST_GROUP(GROUP_B)
{
    void setup() {
    }

    void teardown() {
        mock().checkExpectations();
        mock().clear();
    }
};
TEST(GROUP_B, TEST_NAME_FROM_GROUP_B)
{
	printf("executing ... TEST_NAME_FROM_GROUP_B \n");
	CHECK(true);
}
