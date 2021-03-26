#include "../include/mymath.h"

enum mymath_return_code mymath_add(int32_t *result, int32_t a, int32_t b)
{
    if (((b > 0) && (a > (INT32_MAX - b))) ||
        ((b < 0) && (a < (INT32_MIN - b))))
    {
        return MYMATH_RETURN_CODE_OVERFLOW;
    }

    *result = a + b;
    return MYMATH_RETURN_CODE_OK;
}

enum mymath_return_code mymath_subtract(int32_t *result, int32_t a, int32_t b)
{
    if ((b > 0 && a < INT32_MIN + b) ||
        (b < 0 && a > INT32_MAX + b))
    {
        return MYMATH_RETURN_CODE_OVERFLOW;
    }

    *result = a - b;
    return MYMATH_RETURN_CODE_OK;
}

enum mymath_return_code mymath_multiply(int32_t *result, int32_t a, int32_t b)
{
    if (a > 0)
    {
        if (b > 0)
        {
            if (a > (INT32_MAX / b))
            {
                return MYMATH_RETURN_CODE_OVERFLOW;
            }
        }
        else
        {
            if (b < (INT32_MIN / a))
            {
                return MYMATH_RETURN_CODE_OVERFLOW;
            }
        }
    }
    else
    {
        if (b > 0)
        {
            if (a < (INT32_MIN / b))
            {
                return MYMATH_RETURN_CODE_OVERFLOW;
            }
        }
        else
        {
            if ((a != 0) && (b < (INT32_MAX / a)))
            {
                return MYMATH_RETURN_CODE_OVERFLOW;
            }
        }
    }

    *result = a * b;
    return MYMATH_RETURN_CODE_OK;
}

enum mymath_return_code mymath_divide(int32_t *result, int32_t a, int32_t b)
{
    if (b == 0)
    {
        return MYMATH_RETURN_CODE_DIVISION_BY_ZERO;
    }

    if ((a == INT32_MIN) && (b == -1)) {
        return MYMATH_RETURN_CODE_OVERFLOW;
    }

    *result = a / b;
    return MYMATH_RETURN_CODE_OK;
}
