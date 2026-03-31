#include "../Common.hpp"

struct SBTR{
    using i64 = int64_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    i64 nume;
    u64 deno;

    SBTR(i64 n = 0, u64 d = 1) : nume(n), deno(d){}

    SBTR &operator+=(const SBTR &r){
        nume += r.nume;
        deno += r.deno;
        return (*this);
    }

    SBTR &operator*=(const u64 &r){
        nume *= r;
        deno *= r;
        return (*this);
    }

    SBTR operator+(const SBTR &r) const {
        return SBTR(*this) += r;
    }

    SBTR operator*(const u64 &r) const {
        return SBTR(*this) *= r;
    }

    bool operator==(const SBTR &r) const {
        return u128(nume) * r.deno == u128(deno) * r.nume;
    }

    bool operator!=(const SBTR &r) const {
        return u128(nume) * r.deno != u128(deno) * r.nume;
    }

    bool operator<(const SBTR &r) const {
        return u128(nume) * r.deno < u128(deno) * r.nume;
    }

    bool operator>(const SBTR &r) const {
        return u128(nume) * r.deno > u128(deno) * r.nume;
    }

    bool operator<=(const SBTR &r) const {
        return u128(nume) * r.deno <= u128(deno) * r.nume;
    }

    bool operator>=(const SBTR &r) const {
        return u128(nume) * r.deno >= u128(deno) * r.nume;
    }

    bool operator<(const u64 &r) const {
        return nume < r || deno < r;
    }

    bool operator>(const u64 &r) const {
        return nume > r || deno > r;
    }

    bool operator<=(const u64 &r) const {
        return nume <= r || deno <= r;
    }

    bool operator>=(const u64 &r) const {
        return nume >= r || deno >= r;
    }

    friend ostream &operator<<(ostream &os, const SBTR &p) {
        return os << p.nume << ' ' << p.deno;
    }
};

class SternBrocotTree{
    public:
    using u64 = uint64_t;
    using u128 = __uint128_t;
    using Rational = pair<u64, u64>;

    SternBrocotTree() : l(0, 1), r(1, 0) {}

    inline void Reset(){
        l = SBTR(0, 1), r = SBTR(1, 0);
    }

    inline SBTR Current() const {
        return l + r;
    }

    inline void Move(const char d, const u64 x){
        if(d == 'L') MoveLeft(x);
        if(d == 'R') MoveRight(x);
    }

    inline void MoveLeft(u64 x){
        r += l * x;
    }

    inline void MoveRight(u64 x){
        l += r * x;
    }

    tuple<char, u64, bool> MoveStraightLimited(const u64 n, const u64 d, const u64 k, const bool floor = false){
        SBTR t(n, d), c = Current();
        if(t < c){
            u128 xn = u128(c.nume) * d - u128(c.deno) * n;
            u128 xd = u128(l.deno) * n - u128(l.nume) * d;
            u64 x = floor ? xn / xd : (xn - 1) / xd + 1;
            bool f = false;
            if(c + l * x > k) x = min((k - c.nume) / l.nume, (k - c.deno) / l.deno), f = true;
            MoveLeft(x);
            return {'L', x, f};
        }
        else{
            u128 xn = u128(c.deno) * n - u128(c.nume) * d;
            u128 xd = u128(r.nume) * d - u128(r.deno) * n;
            u64 x = floor ? xn / xd : (xn - 1) / xd + 1;
            bool f = false;
            if(c + r * x > k) x = min((k - c.nume) / r.nume, (k - c.deno) / r.deno), f = true;
            MoveRight(x);
            return {'R', x, f};
        }
    }

    pair<char, u64> MoveStraight(const u64 n, const u64 d, const bool floor = false){
        SBTR t(n, d), c = Current();
        if(t < c){
            u128 xn = u128(c.nume) * d - u128(c.deno) * n;
            u128 xd = u128(l.deno) * n - u128(l.nume) * d;
            u64 x = floor ? xn / xd : (xn - 1) / xd + 1;
            MoveLeft(x);
            return {'L', x};
        }
        else{
            u128 xn = u128(c.deno) * n - u128(c.nume) * d;
            u128 xd = u128(r.nume) * d - u128(r.deno) * n;
            u64 x = floor ? xn / xd : (xn - 1) / xd + 1;
            MoveRight(x);
            return {'R', x};
        }
    }

    vector<pair<char, u64>> Encode(const u64 n, const u64 d){
        vector<pair<char, u64>> ret;
        SBTR t(n, d);
        Reset();
        while(1){
            auto c = Current();
            if(t == c) break;
            ret.emplace_back(MoveStraight(n, d));
        }
        return ret;
    }

    SBTR Decode(const vector<pair<char, u64>> &p){
        Reset();
        for(const auto &[c, n] : p){
            Move(c, n);
        }
        return Current();
    }

    SBTR LowestCommonAncestor(const u64 an, const u64 ad, const u64 bn, const u64 bd){
        auto ap = Encode(an, ad);
        auto bp = Encode(bn, bd);
        Reset();
        if(ap.empty() || bp.empty()) return Current();
        if(ap.front().first != bp.front().first) return Current();
        for(int i = 0; i < min(ap.size(), bp.size()); ++i){
            if(ap[i] == bp[i]){
                Move(ap[i].first, ap[i].second);
            }
            else{
                Move(ap[i].first, min(ap[i].second, bp[i].second));
                break;
            }
        }
        return Current();
    }

    SBTR Ancestor(const u64 k, const u64 n, const u64 d){
        auto p = Encode(n, d);
        vector<u64> pref(p.size() + 1);
        for(int i = 0; i < p.size(); ++i){
            pref[i + 1] = pref[i] + p[i].second;
        }
        if(k > pref.back() || k < 0) return SBTR(-1);
        int t = distance(pref.begin(), upper_bound(pref.begin(), pref.end(), k)) - 1;
        Reset();
        for(int i = 0; i < t; ++i){
            Move(p[i].first, p[i].second);
        }
        Move(p[t].first, k - pref[t]);
        return Current();
    }

    pair<SBTR, SBTR> Range(const u64 n, const u64 d){
        Encode(n, d);
        return {l, r};
    }

    private:
    SBTR l, r;
};