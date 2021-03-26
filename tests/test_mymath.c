#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/mymath.h"

void test_mymath_add()
{
    int32_t result = 0;

    assert(MYMATH_RETURN_CODE_OK == mymath_add(&result, 3, 4));
    assert(7 == result);

    assert(MYMATH_RETURN_CODE_OK == mymath_add(&result, 3, -4));
    assert(-1 == result);
}

void test_mymath_add_limits()
{
    int32_t result = 0;

    assert(MYMATH_RETURN_CODE_OK == mymath_add(&result, INT32_MAX, 0));
    assert(INT32_MAX == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_add(&result, INT32_MAX, 1));

    assert(MYMATH_RETURN_CODE_OK == mymath_add(&result, INT32_MIN, 0));
    assert(INT32_MIN == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_add(&result, INT32_MIN, -1));
}

void test_mymath_subtract()
{
    int32_t result = 0;
    assert(MYMATH_RETURN_CODE_OK == mymath_subtract(&result, 3, 4));
    assert(-1 == result);

    assert(MYMATH_RETURN_CODE_OK == mymath_subtract(&result, 3, -4));
    assert(7 == result);
}

void test_mymath_subtract_limits()
{
    int32_t result = 0;

    assert(MYMATH_RETURN_CODE_OK == mymath_subtract(&result, 3, 4));
    assert(-1 == result);
    
    assert(MYMATH_RETURN_CODE_OK == mymath_subtract(&result, INT32_MIN, 0));
    assert(INT32_MIN == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_subtract(&result, INT32_MIN, 1));
    
    assert(MYMATH_RETURN_CODE_OK == mymath_subtract(&result, INT32_MAX, 0));
    assert(INT32_MAX == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_subtract(&result, INT32_MAX, -1));
}

void test_mymath_multiply()
{
    int32_t result = 0;
    assert(MYMATH_RETURN_CODE_OK == mymath_multiply(&result, 3, 4));
    assert(12 == result);

    assert(MYMATH_RETURN_CODE_OK == mymath_multiply(&result, 3, -4));
    assert(-12 == result);
}

void test_mymath_multiply_limits()
{
    int32_t result = 0;
    assert(MYMATH_RETURN_CODE_OK == mymath_multiply(&result, 1, INT32_MAX));
    assert(INT32_MAX == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_multiply(&result, 2, 0x40000000));

    assert(MYMATH_RETURN_CODE_OK == mymath_multiply(&result, 1, INT32_MIN));
    assert(INT32_MIN == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_multiply(&result, 3, -0x2aaaaaab));
}

void test_mymath_divide()
{
    int32_t result = 0;

    assert(MYMATH_RETURN_CODE_OK == mymath_divide(&result, 3, 2));
    assert(1 == result);
}

void test_mymath_divide_by_zero()
{
    int32_t result = 0;

    assert(MYMATH_RETURN_CODE_DIVISION_BY_ZERO == mymath_divide(&result, 3, 0));
}

void test_mymath_divide_limits()
{
    int32_t result = 0;

    assert(MYMATH_RETURN_CODE_OK == mymath_divide(&result, INT32_MAX, 1));
    assert(INT32_MAX == result);

    assert(MYMATH_RETURN_CODE_OVERFLOW == mymath_divide(&result, INT32_MIN, -1));
}

int main(int argc, char *argv[])
{
    test_mymath_add();
    test_mymath_add_limits();
    test_mymath_subtract();
    test_mymath_subtract_limits();
    test_mymath_multiply();
    test_mymath_multiply_limits();
    test_mymath_divide();
    test_mymath_divide_by_zero();
    test_mymath_divide_limits();
    return 0;
}
