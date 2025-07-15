#ifndef MY_FIXED_POINT_H
#define MY_FIXED_POINT_H

#include <cstdint>
#include <cmath>

#define MAX_FIXED_VALUE fixed::from_raw_fixed(2147483647)
#define MIN_FIXED_VALUE fixed::from_raw_fixed(-2147483648)

#ifdef PICO_RP2040
    #include "pico/float.h"
#endif

#ifndef __not_in_flash_func
    #define __not_in_flash_func(x) x
#endif

#ifndef __not_in_flash
    #define __not_in_flash(x)
#endif

#if defined(_MSC_VER)

static inline int __builtin_clz(uint32_t num) {
	unsigned long index;
	if (_BitScanReverse(&index, num)) return 31 - index;
	else return 32;
}

#endif

class fixed{
    public:
        fixed() = default;
        fixed(double);
        fixed(float);
        fixed(int);
        // BASIC OPS

        // FIXED
        fixed __not_in_flash_func(operator+)(const fixed& other) const;
        fixed __not_in_flash_func(operator-)(const fixed& other) const;
        fixed __not_in_flash_func(operator*)(const fixed& other) const;
        fixed __not_in_flash_func(operator/)(const fixed& other) const;

        // DOUBLE
        fixed __not_in_flash_func(operator+)(const double& other) const;
        fixed __not_in_flash_func(operator-)(const double& other) const;
        fixed __not_in_flash_func(operator*)(const double& other) const;
        fixed __not_in_flash_func(operator/)(const double& other) const;

        // FLOAT
        fixed __not_in_flash_func(operator+)(const float& other) const;
        fixed __not_in_flash_func(operator-)(const float& other) const;
        fixed __not_in_flash_func(operator*)(const float& other) const;
        fixed __not_in_flash_func(operator/)(const float& other) const;

        // INT
        fixed __not_in_flash_func(operator+)(const int& other) const;
        fixed __not_in_flash_func(operator-)(const int& other) const;
        fixed __not_in_flash_func(operator*)(const int& other) const;
        fixed __not_in_flash_func(operator/)(const int& other) const;

        // BASIC + ASSIGN OPS

        // FIXED
        fixed& __not_in_flash_func(operator+=)(const fixed& other);
        fixed& __not_in_flash_func(operator-=)(const fixed& other);
        fixed& __not_in_flash_func(operator*=)(const fixed& other);
        fixed& __not_in_flash_func(operator/=)(const fixed& other);

        // DOUBLE
        fixed& __not_in_flash_func(operator+=)(const double& other);
        fixed& __not_in_flash_func(operator-=)(const double& other);
        fixed& __not_in_flash_func(operator*=)(const double& other);
        fixed& __not_in_flash_func(operator/=)(const double& other);

        // FLOAT
        fixed& __not_in_flash_func(operator+=)(const float& other);
        fixed& __not_in_flash_func(operator-=)(const float& other);
        fixed& __not_in_flash_func(operator*=)(const float& other);
        fixed& __not_in_flash_func(operator/=)(const float& other);

        // INT
        fixed& __not_in_flash_func(operator+=)(const int& other);
        fixed& __not_in_flash_func(operator-=)(const int& other);
        fixed& __not_in_flash_func(operator*=)(const int& other);
        fixed& __not_in_flash_func(operator/=)(const int& other);

        // ASSIGNMENT OPS
        fixed& __not_in_flash_func(operator=)(const fixed& other);
        fixed& __not_in_flash_func(operator=)(const double& other);
        fixed& __not_in_flash_func(operator=)(const float& other);
        fixed& __not_in_flash_func(operator=)(const int& other);

        // COMPARISON OPS
        bool __not_in_flash_func(operator>)(const fixed& other) const;
        bool __not_in_flash_func(operator>)(const double& other) const;
        bool __not_in_flash_func(operator>)(const float& other) const;
        bool __not_in_flash_func(operator>)(const int& other) const;

        bool __not_in_flash_func(operator<)(const fixed& other) const;
        bool __not_in_flash_func(operator<)(const double& other) const;
        bool __not_in_flash_func(operator<)(const float& other) const;
        bool __not_in_flash_func(operator<)(const int& other) const;

        bool __not_in_flash_func(operator==)(const fixed& other) const;
        bool __not_in_flash_func(operator==)(const double& other) const;
        bool __not_in_flash_func(operator==)(const float& other) const;
        bool __not_in_flash_func(operator==)(const int& other) const;

        bool __not_in_flash_func(operator>=)(const fixed& other) const;
        bool __not_in_flash_func(operator>=)(const double& other) const;
        bool __not_in_flash_func(operator>=)(const float& other) const;
        bool __not_in_flash_func(operator>=)(const int& other) const;

        bool __not_in_flash_func(operator<=)(const fixed& other) const;
        bool __not_in_flash_func(operator<=)(const double& other) const;
        bool __not_in_flash_func(operator<=)(const float& other) const;
        bool __not_in_flash_func(operator<=)(const int& other) const;

        fixed __not_in_flash_func(operator%)(const fixed& other) const;
        fixed __not_in_flash_func(operator%)(const double& other) const;
        fixed __not_in_flash_func(operator%)(const float& other) const;
        fixed __not_in_flash_func(operator%)(const int& other) const;

        fixed& operator++();
        fixed& operator--();
        fixed operator++(int);
        fixed operator--(int);

        fixed operator-() const;

        operator double() const;
        operator float() const;
        operator int() const;
        operator short() const;
        operator char() const;

        operator unsigned int() const;
        operator unsigned short() const;
        operator unsigned char() const;

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

        static fixed __not_in_flash_func(from_raw_fixed)(const int32_t& num);

        int32_t value=0;
        static const fixed PI;
        static const fixed HALF_PI;
        static const fixed TWO_PI;
    private:
        static const int32_t FRAC_BITS = 15;
        static const int32_t FRAC_MASK = 0x7FFF;
    #ifdef SQRT_BIG_LUT
        static const uint16_t __not_in_flash("sqrt_lookup") sqrt_lookup[8193];
    #else
        static const uint16_t __not_in_flash("sqrt_lookup") sqrt_lookup[257];
    #endif
        static const uint16_t __not_in_flash("sin_cos_lookup") sin_cos_lookup[806];
        static const uint16_t __not_in_flash("log_base_lookup") log_base_lookup[513];
        static const uint16_t __not_in_flash("log_pow2_lookup") log_pow2_lookup[18];
};

#include "MyFixedPoint.hpp"

#endif // MY_FIXED_POINT_H