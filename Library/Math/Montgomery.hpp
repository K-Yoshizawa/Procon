#include "../Common.hpp"

struct Montgomery{
    using mont = Montgomery;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static void SetMod(const u64 m){
        assert(m < (1LL << 62));
        assert(m & 1);
        mod = m;
        inv_mod = m;
        for(int i = 0; i < 5; ++i){
            inv_mod *= 2 - m * inv_mod;
        }
        r2 = -u128(m) % m;
    }

    u64 val;

    Montgomery() : val(0){}

    Montgomery(long long x) : val(Reduct((u128(x) + mod) * r2)){}

    inline u64 Get() const {
        u64 res = Reduct(val);
        return res >= mod ? res - mod : res;
    }

    mont &operator+=(const mont &r){
        if((val += r.val) >= 2 * mod) val -= 2 * mod;
        return (*this);
    }

    mont &operator-=(const mont &r){
        if((val += 2 * mod - r.val) >= 2 * mod) val -= 2 * mod;
        return (*this);
    }

    mont &operator*=(const mont &r){
        val = Reduct(u128(val) * r.val);
        return (*this);
    }

    mont &operator/=(const mont &r){
        (*this) *= r.Inverse();
        return (*this);
    }

    mont Inverse() const {
        return Power(mod - 2);
    }

    mont Power(long long k) const {
        mont ret(1), mul(*this);
        while(k){
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }

    mont operator-() const {
        return mont() - mont(*this);
    }

    mont operator+(const mont &r) const {
        return mont(*this) += r;
    }

    mont operator-(const mont &r) const {
        return mont(*this) -= r;
    }

    mont operator*(const mont &r) const {
        return mont(*this) *= r;
    }

    bool operator==(const mont &r) const {
        return (val >= mod ? val - mod : val) == (r.val >= mod ? r.val - mod : r.val);
    }

    bool operator!=(const mont &r) const {
        return (val >= mod ? val - mod : val) != (r.val >= mod ? r.val - mod : r.val);
    }

    private:
    static u64 mod;
    static u64 inv_mod;
    static u64 r2;

    static u64 Reduct(const u128 x){
        return (x + u128(u64(x) * u64(-inv_mod)) * mod) >> 64;
    }
};

typename Montgomery::u64 Montgomery::mod, Montgomery::inv_mod, Montgomery::r2;