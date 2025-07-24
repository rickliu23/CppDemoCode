#include <iostream>

#ifdef TEST_CONSTRUCTOR
void ConstructorTest();
#endif

int main() {
#ifdef TEST_CONSTRUCTOR
    ConstructorTest();
#endif
    return 0;
}