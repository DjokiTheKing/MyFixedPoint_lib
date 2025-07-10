#ifndef MY_FIXED_POINT_H
#define MY_FIXED_POINT_H

#include "pico/float.h"
#include <cstring>

class fixed{
    public:
        fixed() = default;
        fixed(float);

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

        static fixed __not_in_flash_func(absf)(const fixed& num);

        static fixed __not_in_flash_func(sqrt_acc)(const fixed& num);
        static fixed __not_in_flash_func(sqrt)(const fixed& num);

        static fixed __not_in_flash_func(sin)(const fixed& num);
        static fixed __not_in_flash_func(cos)(const fixed& num);

        int32_t value=0;
        static const fixed PI;
        static const fixed HALF_PI;
        static const fixed TWO_PI;
    private:
        static const unsigned FRAC_BITS = 15U;
        static const unsigned FRAC_MASK = 0x00007FFF;
    #ifdef SQRT_BIG_LUT
        static const uint16_t __not_in_flash("sqrt_lookup") sqrt_lookup[1025];
    #else
        alignas(32) static const uint16_t __not_in_flash("sqrt_lookup") sqrt_lookup[257];
    #endif
        static const uint16_t __not_in_flash("sin_cos_lookup") sin_cos_lookup[805];
};

#include "MyFixedPoint.hpp"

#endif // MY_FIXED_POINT_H