#include <openenclave/internal/tests.h>
#include <iostream>
#include "test_t.h"

using namespace std;

extern "C" int gotest();

void test_ecall()
{
    const int r = gotest();
    cout << "gotest() returned " << r << '\n';
    OE_TEST(r == 42);
}

OE_SET_ENCLAVE_SGX(
    1,      /* ProductID */
    1,      /* SecurityVersion */
    true,   /* Debug */
    131072, /* NumHeapPages */
    64,     /* NumStackPages */
    16);    /* NumTCS */
