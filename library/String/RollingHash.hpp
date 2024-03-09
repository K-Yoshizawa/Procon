/**
 * @file RollingHash.hpp
 * @author log K (lX57)
 * @brief Rolling Hash - ローリングハッシュ
 * @version 1.0
 * @date 2023-12-03
 */

#include <bits/stdc++.h>
using namespace std;

struct RollingHash{
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static const u64 MOD = (1UL << 61) - 1;

    using Hash = u64;
    using HashTable = vector<Hash>;
    static Hash base;
    static HashTable power;
    HashTable hash;

    static inline u64 add(u64 a, u64 b){
        if((a += b) >= MOD) a -= MOD;
        return a;
    }

    static inline u64 mul(u64 a, u64 b){
        u128 c = u128(a) * b;
        return add(c >> 61, c & MOD);
    }

    static void generate_base(const int MaxLength = 200010){
        random_device rnd;
        mt19937 mt(rnd());
        uniform_int_distribution<u64> dist(1, MOD - 1);
        base = dist(mt);
        power.resize(MaxLength);
        power[0] = 1;
        for(int i = 1; i <= MaxLength; ++i){
            power[i] = mul(power[i - 1], base);
        }
    }

    int len;

    RollingHash(string S) : len(S.size()) {
        u64 x = 0;
        hash.push_back(0);
        for(auto c : S){
            x = add(mul(x, base), c);
            hash.push_back(x);
        }
    }

    Hash get() const {
        return hash.back();
    }

    int size(){
        return len;
    }

    /**
     * @brief 文字列の部分文字列 `[l, r]` のハッシュを取得する
     * @attention `l`, `r` は 1-index
     * @return 部分文字列 `[l, r]` のハッシュ値 
     */
    Hash substr(int l, int r){
        return add(hash[r], MOD - mul(hash[l - 1], power[r - l + 1]));
    }

    static Hash connect(Hash l, Hash r, int r_len){
        return add(mul(l, power[r_len]), r);
    }

    bool operator==(const RollingHash &r){
        return get() == r.get();
    }

    operator Hash(){
        return get();
    }
};

typename RollingHash::Hash RollingHash::base;
typename RollingHash::HashTable RollingHash::power;