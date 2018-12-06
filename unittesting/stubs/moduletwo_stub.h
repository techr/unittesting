#ifndef MODULE_TWO_STUB_H
#define MODULE_TWO_STUB_H


extern "C" {
#include "moduletwo.h"
}

/* Define all the production code functions in a structure as function pointers */
struct StStubFunctions {
    static int (*module_two)(int);
};

/* Create a Stub namespace with functions which needs mocking */
namespace nsStub
{
int module_two(int a);
};


/* Create a production namespace where the actual production code needs to be called */
namespace nsProduction
{
int module_two(int a);
};


#endif
