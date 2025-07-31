#include <iostream>

#if defined(TEST_CONSTRUCTOR)
    void ConstructorTest();
#elif defined(TEST_RANGE_BASED_FOR_LOOP)
    void range_based_for_loop();
#elif defined(TEST_LAMBDA)
    void lambda_test();
#endif

int main() {

#if defined(TEST_CONSTRUCTOR)
    ConstructorTest();
#elif defined(TEST_RANGE_BASED_FOR_LOOP)
    range_based_for_loop();
#elif defined(TEST_LAMBDA)
    lambda_test();
#endif

    return 0;
}