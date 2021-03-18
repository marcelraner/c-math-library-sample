#ifndef LIBMATH_MATH_H
#define LIBMATH_MATH_H

#include <stdint.h>

enum math_return_code
{
    MATH_RETURN_CODE_OK = 0,
    MATH_RETURN_CODE_OVERFLOW = 1,
    MATH_RETURN_CODE_DIVISION_BY_ZERO = 2
};

enum math_return_code math_add(int32_t *result, int32_t a, int32_t b);
enum math_return_code math_subtract(int32_t *result, int32_t a, int32_t b);
enum math_return_code math_multiply(int32_t *result, int32_t a, int32_t b);
enum math_return_code math_divide(int32_t *result, int32_t a, int32_t b);

#endif /* LIBMATH_MATH_H */
