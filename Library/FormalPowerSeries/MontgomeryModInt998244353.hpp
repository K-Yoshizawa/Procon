#pragma once

#include "../Common.hpp"

class MontgomeryModInt998244353{
    using i32 = int32_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    public:
    using ModInt = MontgomeryModInt998244353;

    constexpr MontgomeryModInt998244353() : x(0){}

    constexpr MontgomeryModInt998244353(int64_t y) : x(MontgomeryReduction(u64(y) * R2)){}

    constexpr ModInt &operator+=(const ModInt &r){
        if(i32(x += r.x - 2 * MOD) < 0) x += 2 * MOD;
        return (*this);
    }

    constexpr ModInt &operator-=(const ModInt &r){
        if(i32(x -= r.x) < 0) x += 2 * MOD;
        return (*this);
    }

    constexpr ModInt &operator*=(const ModInt &r){
        x = MontgomeryReduction(u64(x) * r.x);
        return (*this);
    }

    constexpr ModInt &operator/=(const ModInt &r){
        (*this) *= r.Inverse();
        return (*this);
    }

    constexpr ModInt operator+(const ModInt &r) const {return ModInt(*this) += r;}
    constexpr ModInt operator-(const ModInt &r) const {return ModInt(*this) -= r;}
    constexpr ModInt operator/(const ModInt &r) const {return ModInt(*this) /= r;}
    constexpr ModInt operator*(const ModInt &r) const {return ModInt(*this) *= r;}

    constexpr bool operator==(const ModInt &r) const {return Value() == r.Value();}
    constexpr bool operator!=(const ModInt &r) const {return Value() != r.Value();}
    
    constexpr ModInt operator+() const {return ModInt(*this);}
    constexpr ModInt operator-() const {return ModInt() - ModInt(*this);}

    constexpr ModInt Power(int64_t k) const {
        ModInt ret(1), mul(*this);
        while(k){
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }

    constexpr ModInt Inverse() const {
        return Power(MOD - 2);
    }

    constexpr uint32_t Value() const {
        uint32_t ret = MontgomeryReduction(x);
        return ret >= MOD ? ret - MOD : ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &r){
        return os << r.Value();
    }

    friend istream &operator>>(istream &is, ModInt &r){
        int64_t y; is >> y;
        r = MontgomeryModInt998244353(y);
        return is;
    }

    private:
    static constexpr u32 MontgomeryReduction(const u64 &T){
        return (T + u64(u32(T) * INV) * MOD) >> 32;
    }

    u32 x;

    static constexpr u32 MOD = 998244353;
    static constexpr u32 INV = 998244351;
    static constexpr u32 R2 = 932051910;
};

using mint = MontgomeryModInt998244353;