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
    using Hash = uint64_t;
    using HashTable = vector<Hash>;

    private:
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static const u64 MOD = (1UL << 61) - 1;

    static Hash base;
    static HashTable power;

    static inline u64 add(u64 a, u64 b){
        if((a += b) >= MOD) a -= MOD;
        return a;
    }

    static inline u64 mul(u64 a, u64 b){
        u128 c = u128(a) * b;
        return add(c >> 61, c & MOD);
    }

    public:
    /**
     * @brief ハッシュのベースを構築する。同時に部分文字列用の `power` 配列も初期化する。
     * @attention 必ず最初に呼び出すこと
     * @param MaxLength powerの配列長、文字列としてあり得る最大長 `(default = 10^6)`
     */
    static void generate_base(const int MaxLength = 1000020){
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

    /**
     * @brief 文字列 `S` に対するハッシュテーブルを作成する。
     * @note 文字列自体のハッシュは `HashTable.back()` の値
     * @param S ハッシュテーブルを作成する文字列
     * @return HashTable ハッシュテーブル、1-indexで i 番目の要素は先頭から i 文字の部分文字列のハッシュ値を表す。
     */
    HashTable build(string S){
        HashTable ret;
        u64 x = 0;
        ret.push_back(0);
        for(auto c : S){
            x = add(mul(x, base), c);
            ret.push_back(x);
        }
        return ret;
    }

    /**
     * @brief 文字 `c` に対するハッシュ値を返す。
     * @note セグメント木とかで使える。
     */
    Hash build(char c){
        return add(0, c);
    }

    /**
     * @brief ハッシュテーブル `hash` において、部分文字列 `[l, r]` のハッシュを取得する
     * @attention `l`, `r` は 1-index
     * @return 部分文字列 `[l, r]` のハッシュ値 
     */
    Hash substr(HashTable &hash, int l, int r){
        return add(hash[r], MOD - mul(hash[l - 1], power[r - l + 1]));
    }

    /**
     * @brief ハッシュで表された2つの文字列をこの順番で連結したハッシュ値を返す。
     * @param l 連結する左側の文字列のハッシュ値
     * @param r 連結する右側の文字列のハッシュ値
     * @param r_len 右側の文字列の長さ
     * @return Hash 連結した文字列のハッシュ値
     */
    Hash connect(Hash l, Hash r, int r_len){
        return add(mul(l, power[r_len]), r);
    }
};

typename RollingHash::Hash RollingHash::base;
typename RollingHash::HashTable RollingHash::power;
using Hash = RollingHash::Hash;
using HashTable = RollingHash::HashTable;