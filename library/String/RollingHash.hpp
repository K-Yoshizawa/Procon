/**
 * @file RollingHash.hpp
 * @author log K (lX57)
 * @brief Rolling Hash - ローリングハッシュ
 * @version 1.0
 * @date 2023-12-03
 */

#include <bits/stdc++.h>
using namespace std;

namespace rh{
    const ulong MASK30 = (1UL << 30) - 1;
    const ulong MASK31 = (1UL << 31) - 1;
    const ulong MOD = (1UL << 61) - 1;
    const ulong MASK61 = MOD;
    const ulong POSITIVIZER = MOD * 4;
    vector<ulong> base;
    vector<vector<ulong>> pow;

    ulong Mod(ulong x){
        ulong xu = x >> 61, xd = x & MASK61;
        ulong res = xu + xd;
        if(res >= MOD) res -= MOD;
        return res;
    }

    ulong Mul(ulong a, ulong b){
        ulong au = a >> 31, ad = a & MASK31;
        ulong bu = b >> 31, bd = b & MASK31;
        ulong m = ad * bu + au * bd;
        ulong mu = m >> 30, md = m & MASK30;
        return au * bu * 2 + mu + (md << 31) + ad * bd;
    }
};

/**
 * @brief ローリングハッシュの基底を生成する
 * @attention ローリングハッシュを使う前に必ず呼び出すこと
 * @param N 文字列の最大文字数 (default = 1e6 + 10)
 * @param Cnt 生成する基底の数 (default = 3)
 */
void RollingHash_createbase(int N = 1000010, int Cnt = 3){
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<ulong> dist(1, rh::MOD - 1);
    for(int i = 0; i < Cnt; ++i) rh::base.push_back(dist(mt));
    rh::pow.resize(Cnt, vector<ulong>(N + 1, 1UL));
    for(int i = 0; i < Cnt; ++i){
        for(int j = 1; j <= N; ++j){
            rh::pow[i][j] = rh::Mod(rh::Mul(rh::pow[i][j - 1], rh::base[i]));
        }
    }
}

struct RollingHash{
    private:
    vector<vector<ulong>> __PrefixHash;
    bool __ValidPrefixHash{false};
    vector<ulong> __Hash;
    int __Hashsize, __Length;

    public:
    RollingHash() : __Hashsize(rh::base.size()), __Hash(rh::base.size(), 0), __Length(0){}

    /**
     * @brief 文字列 `S` からハッシュを生成する
     * @note この場合に限り、 `PrefixHash` が計算され、 `substr` を使うことができる
     */
    RollingHash(string S) : __Hashsize(rh::base.size()), __Length(S.size()){
        __PrefixHash.resize(__Hashsize);
        for(int i = 0; i < __Hashsize; ++i){
            ulong x = 0, b = rh::base[i];
            __PrefixHash[i].push_back(0);
            for(auto c : S){
                x = rh::Mod(rh::Mul(x, b) + c);
                __PrefixHash[i].push_back(x);
            }
            __Hash.push_back(x);
        }
        __ValidPrefixHash = true;
    }

    /**
     * @brief 文字 `c` からハッシュを生成する
     */
    RollingHash(char c) : __Hashsize(rh::base.size()), __Length(1){
        __Hash.resize(__Hashsize, c);
    }

    /**
     * @brief 初期のハッシュ値と文字列長からハッシュを生成する
     */
    RollingHash(vector<ulong> &InitHash, int Length) : __Hashsize(rh::base.size()), __Hash(InitHash), __Length(Length){}

    inline ulong get(int i) const {
        return __Hash[i];
    }

    inline int length(){
        return __Length;
    }

    /**
     * @brief 文字列の部分文字列 `[l, r]` のハッシュを取得する
     * @attention `l, r` は1-index
     */
    RollingHash substr(int l, int r){
        assert(__ValidPrefixHash);
        vector<ulong> ret;
        for(int i = 0; i < __Hashsize; ++i){
            ret.push_back(rh::Mod(__PrefixHash[i][r] + rh::POSITIVIZER - rh::Mul(__PrefixHash[i][l - 1], rh::pow[i][r - l + 1])));
        }
        return RollingHash(ret, r - l + 1);
    }

    /**
     * @brief ハッシュ `l` とハッシュ `r` をこの順に連結する
     */
    static RollingHash connect(RollingHash &l, RollingHash &r){
        vector<ulong> ret;
        for(int i = 0; i < rh::base.size(); ++i){
            ret.push_back(rh::Mod(rh::Mul(l.get(i), rh::pow[i][r.length()]) + r.get(i)));
        }
        return RollingHash(ret, l.length() + r.length());
    }

    bool operator==(const RollingHash& r) const {
        bool ret = true;
        for(int i = 0; i < rh::base.size(); ++i){
            ret &= get(i) == r.get(i);
        }
        return ret;
    }
};