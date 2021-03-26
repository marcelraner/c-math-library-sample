#ifndef LIBMYMATH_MYMATH_H
#define LIBMYMATH_MYMATH_H

#include <stdint.h>

enum mymath_return_code
{
    MYMATH_RETURN_CODE_OK = 0,
    MYMATH_RETURN_CODE_OVERFLOW = 1,
    MYMATH_RETURN_CODE_DIVISION_BY_ZERO = 2
};

enum mymath_return_code mymath_add(int32_t *result, int32_t a, int32_t b);
enum mymath_return_code mymath_subtract(int32_t *result, int32_t a, int32_t b);
enum mymath_return_code mymath_multiply(int32_t *result, int32_t a, int32_t b);
enum mymath_return_code mymath_divide(int32_t *result, int32_t a, int32_t b);

#endif /* LIBMYMATH_MYMATH_H */
