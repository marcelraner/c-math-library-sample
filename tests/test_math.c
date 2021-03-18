#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/math.h"

void test_math_add()
{
    int32_t result = 0;

    assert(MATH_RETURN_CODE_OK == math_add(&result, 3, 4));
    assert(7 == result);

    assert(MATH_RETURN_CODE_OK == math_add(&result, 3, -4));
    assert(-1 == result);
}

void test_math_add_limits()
{
    int32_t result = 0;

    assert(MATH_RETURN_CODE_OK == math_add(&result, INT32_MAX, 0));
    assert(INT32_MAX == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_add(&result, INT32_MAX, 1));

    assert(MATH_RETURN_CODE_OK == math_add(&result, INT32_MIN, 0));
    assert(INT32_MIN == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_add(&result, INT32_MIN, -1));
}

void test_math_subtract()
{
    int32_t result = 0;
    assert(MATH_RETURN_CODE_OK == math_subtract(&result, 3, 4));
    assert(-1 == result);

    assert(MATH_RETURN_CODE_OK == math_subtract(&result, 3, -4));
    assert(7 == result);
}

void test_math_subtract_limits()
{
    int32_t result = 0;

    assert(MATH_RETURN_CODE_OK == math_subtract(&result, 3, 4));
    assert(-1 == result);
    
    assert(MATH_RETURN_CODE_OK == math_subtract(&result, INT32_MIN, 0));
    assert(INT32_MIN == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_subtract(&result, INT32_MIN, 1));
    
    assert(MATH_RETURN_CODE_OK == math_subtract(&result, INT32_MAX, 0));
    assert(INT32_MAX == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_subtract(&result, INT32_MAX, -1));
}

void test_math_multiply()
{
    int32_t result = 0;
    assert(MATH_RETURN_CODE_OK == math_multiply(&result, 3, 4));
    assert(12 == result);

    assert(MATH_RETURN_CODE_OK == math_multiply(&result, 3, -4));
    assert(-12 == result);
}

void test_math_multiply_limits()
{
    int32_t result = 0;
    assert(MATH_RETURN_CODE_OK == math_multiply(&result, 1, INT32_MAX));
    assert(INT32_MAX == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_multiply(&result, 2, 0x40000000));

    assert(MATH_RETURN_CODE_OK == math_multiply(&result, 1, INT32_MIN));
    assert(INT32_MIN == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_multiply(&result, 3, -0x2aaaaaab));
}

void test_math_divide()
{
    int32_t result = 0;

    assert(MATH_RETURN_CODE_OK == math_divide(&result, 3, 2));
    assert(1 == result);
}

void test_math_divide_by_zero()
{
    int32_t result = 0;

    assert(MATH_RETURN_CODE_DIVISION_BY_ZERO == math_divide(&result, 3, 0));
}

void test_math_divide_limits()
{
    int32_t result = 0;

    assert(MATH_RETURN_CODE_OK == math_divide(&result, INT32_MAX, 1));
    assert(INT32_MAX == result);

    assert(MATH_RETURN_CODE_OVERFLOW == math_divide(&result, INT32_MIN, -1));
}

int main(int argc, char *argv[])
{
    test_math_add();
    test_math_add_limits();
    test_math_subtract();
    test_math_subtract_limits();
    test_math_multiply();
    test_math_multiply_limits();
    test_math_divide();
    test_math_divide_by_zero();
    test_math_divide_limits();
    return 0;
}
