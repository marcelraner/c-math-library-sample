#include "private_math.h"

enum math_return_code math_add(int32_t *result, int32_t a, int32_t b)
{
    if (((b > 0) && (a > (INT32_MAX - b))) ||
        ((b < 0) && (a < (INT32_MIN - b))))
    {
        return MATH_RETURN_CODE_OVERFLOW;
    }

    *result = a + b;
    return MATH_RETURN_CODE_OK;
}

enum math_return_code math_subtract(int32_t *result, int32_t a, int32_t b)
{
    if ((b > 0 && a < INT32_MIN + b) ||
        (b < 0 && a > INT32_MAX + b))
    {
        return MATH_RETURN_CODE_OVERFLOW;
    }

    *result = a - b;
    return MATH_RETURN_CODE_OK;
}

enum math_return_code math_multiply(int32_t *result, int32_t a, int32_t b)
{
    if (a > 0)
    {
        if (b > 0)
        {
            if (a > (INT32_MAX / b))
            {
                return MATH_RETURN_CODE_OVERFLOW;
            }
        }
        else
        {
            if (b < (INT32_MIN / a))
            {
                return MATH_RETURN_CODE_OVERFLOW;
            }
        }
    }
    else
    {
        if (b > 0)
        {
            if (a < (INT32_MIN / b))
            {
                return MATH_RETURN_CODE_OVERFLOW;
            }
        }
        else
        {
            if ((a != 0) && (b < (INT32_MAX / a)))
            {
                return MATH_RETURN_CODE_OVERFLOW;
            }
        }
    }

    *result = a * b;
    return MATH_RETURN_CODE_OK;
}

enum math_return_code math_divide(int32_t *result, int32_t a, int32_t b)
{
    if (b == 0)
    {
        return MATH_RETURN_CODE_DIVISION_BY_ZERO;
    }

    if ((a == INT32_MIN) && (b == -1)) {
        return MATH_RETURN_CODE_OVERFLOW;
    }

    *result = a / b;
    return MATH_RETURN_CODE_OK;
}
