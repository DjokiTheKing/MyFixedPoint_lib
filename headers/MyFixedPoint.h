#ifndef MY_FIXED_POINT_H
#define MY_FIXED_POINT_H

#define MAX_FIXED_VALUE fixed(65535.99997f)
#define MIN_FIXED_VALUE fixed(-65536.0f)

#include "pico/float.h"
#include <cstring>

class fixed{
    public:
        fixed() = default;
        fixed(float);
        fixed(int);

        fixed __not_in_flash_func(operator+)(const fixed& other) const;
        fixed __not_in_flash_func(operator-)(const fixed& other) const;
        fixed __not_in_flash_func(operator*)(const fixed& other) const;
        fixed __not_in_flash_func(operator/)(const fixed& other) const;

        fixed __not_in_flash_func(operator+)(const float& other) const;
        fixed __not_in_flash_func(operator-)(const float& other) const;
        fixed __not_in_flash_func(operator*)(const float& other) const;
        fixed __not_in_flash_func(operator/)(const float& other) const;

        fixed __not_in_flash_func(operator+)(const int& other) const;
        fixed __not_in_flash_func(operator-)(const int& other) const;
        fixed __not_in_flash_func(operator*)(const int& other) const;
        fixed __not_in_flash_func(operator/)(const int& other) const;

        fixed& __not_in_flash_func(operator+=)(const fixed& other);
        fixed& __not_in_flash_func(operator-=)(const fixed& other);
        fixed& __not_in_flash_func(operator*=)(const fixed& other);
        fixed& __not_in_flash_func(operator/=)(const fixed& other);

        fixed& __not_in_flash_func(operator+=)(const float& other);
        fixed& __not_in_flash_func(operator-=)(const float& other);
        fixed& __not_in_flash_func(operator*=)(const float& other);
        fixed& __not_in_flash_func(operator/=)(const float& other);

        fixed& __not_in_flash_func(operator+=)(const int& other);
        fixed& __not_in_flash_func(operator-=)(const int& other);
        fixed& __not_in_flash_func(operator*=)(const int& other);
        fixed& __not_in_flash_func(operator/=)(const int& other);

        fixed& __not_in_flash_func(operator=)(const fixed& other);
        fixed& __not_in_flash_func(operator=)(const float& other);
        fixed& __not_in_flash_func(operator=)(const int& other);

        bool __not_in_flash_func(operator>)(const fixed& other) const;
        bool __not_in_flash_func(operator>)(const float& other) const;
        bool __not_in_flash_func(operator>)(const int& other) const;

        bool __not_in_flash_func(operator<)(const fixed& other) const;
        bool __not_in_flash_func(operator<)(const float& other) const;
        bool __not_in_flash_func(operator<)(const int& other) const;

        bool __not_in_flash_func(operator==)(const fixed& other) const;
        bool __not_in_flash_func(operator==)(const float& other) const;
        bool __not_in_flash_func(operator==)(const int& other) const;

        bool __not_in_flash_func(operator>=)(const fixed& other) const;
        bool __not_in_flash_func(operator>=)(const float& other) const;
        bool __not_in_flash_func(operator>=)(const int& other) const;

        bool __not_in_flash_func(operator<=)(const fixed& other) const;
        bool __not_in_flash_func(operator<=)(const float& other) const;
        bool __not_in_flash_func(operator<=)(const int& other) const;

        operator float() const;
        operator int() const;

        static fixed __not_in_flash_func(absf)(const fixed& num);
        static fixed __not_in_flash_func(sign)(const fixed& num);

        static fixed __not_in_flash_func(logn)(const fixed& num);
        static fixed __not_in_flash_func(logn_fast)(const fixed& num);
        
        static fixed __not_in_flash_func(sqrt_acc)(const fixed& num);
        static fixed __not_in_flash_func(sqrt)(const fixed& num);
        static fixed __not_in_flash_func(sqrt_fast)(const fixed& num);

        static fixed __not_in_flash_func(sin)(const fixed& num);
        static fixed __not_in_flash_func(cos)(const fixed& num);

        static fixed __not_in_flash_func(sin_fast)(const fixed& num);
        static fixed __not_in_flash_func(cos_fast)(const fixed& num);

        int32_t value=0;
        static const fixed PI;
        static const fixed HALF_PI;
        static const fixed TWO_PI;
    private:
        static const unsigned FRAC_BITS = 15U;
        static const unsigned FRAC_MASK = 0x00007FFF;
    #ifdef SQRT_BIG_LUT
        static const uint16_t __not_in_flash("sqrt_lookup") sqrt_lookup[8193];
    #else
        static const uint16_t __not_in_flash("sqrt_lookup") sqrt_lookup[257];
    #endif
        static const uint16_t __not_in_flash("sin_cos_lookup") sin_cos_lookup[805];
        static const uint16_t __not_in_flash("log_base_lookup") log_base_lookup[513];
        static const uint16_t __not_in_flash("log_pow2_lookup") log_pow2_lookup[18];
};

#include "MyFixedPoint.hpp"

#endif // MY_FIXED_POINT_H