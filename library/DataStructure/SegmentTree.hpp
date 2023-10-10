/**
 * @file SegmentTree.hpp
 * @author log K (lX57)
 * @brief Segment Tree - セグメント木
 * @version 2.0
 * @date 2023-10-02
 */

#include <bits/stdc++.h>
using namespace std;

template<typename Monoid>
struct SegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;

    int __Size, __Offset, __ZeroIndex;
    vector<Monoid> __Data;
    const F f;
    const Monoid __M1;

    inline void __Check(int x){
        assert(1 <= x && x <= __Size);
    }

    Monoid __query(int ql, int qr, int left, int right, int cell){
        if(qr <= left || right <= ql){
            return __M1;
        }
        if(ql <= left && right <= qr){
            return __Data[cell];
        }
        int mid = (left + right) / 2;
        Monoid ans_left = __query(ql, qr, left, mid, 2 * cell);
        Monoid ans_right = __query(ql, qr, mid, right, 2 * cell + 1);
        return f(ans_left, ans_right);
    }

    public:
    /**
     * @brief セグメント木を要素数 `Size` で初期化する。
     * @param Size セグメント木の要素数
     * @param Merge 区間取得を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    SegmentTree(int Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)
    : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < Size) __Size <<= 1;
        __Offset = __Size - 1;
        __Data.resize(2 * __Size, __M1);
    }

    /**
     * @brief セグメント木を構築する。
     * @attention 必ず `set()` で初期値を代入してから呼び出すこと！
     */
    void build(){
        for(int i = __Offset; i >= 1; --i){
            __Data[i] = f(__Data[i * 2 + 0], __Data[i * 2 + 1]);
        }
    }

    /**
     * @brief セグメント木の初期値を代入する。
     * @param Index 代入先の要素番号 (default = 1-index)
     * @param Value 代入する値
     */
    void set(int Index, Monoid Value){
        __Check(Index + __ZeroIndex);
        __Data[__Offset + Index + __ZeroIndex] = Value;
    }

    /**
     * @brief セグメント木を配列 `Init_Data` で初期化する。
     * @param Init_Data 初期データの配列
     * @param Merge 区間取得を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    SegmentTree(vector<Monoid> &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)
    : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < (int)Init_Data.size()) __Size <<= 1;
        __Offset = __Size - 1;
        __Data.resize(2 * __Size, __M1);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            __Data[__Size + i] = Init_Data[i];
        }
        build();
    }

    /**
     * @brief 一点更新クエリを処理する。
     * @param Index 更新先の要素番号 (default = 1-index)
     * @param Value 更新する値
     */
    void update(int Index, Monoid Value){
        __Check(Index + __ZeroIndex);
        int k = __Offset + Index + __ZeroIndex;
        __Data[k] = Value;
        while(k >>= 1){
            __Data[k] = f(__Data[2 * k], __Data[2 * k + 1]);
        }
    }

    /**
     * @brief 半開区間 `[Left, Right)` に対して区間取得クエリを行う。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid query(int Left, int Right){
        __Check(Left + __ZeroIndex);
        __Check(Right + __ZeroIndex - 1);
        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size + 1, 1);
    }

    /**
     * @brief 要素番号 `k` の要素を取得する。
     * @param k 取得先の要素番号 (default = 1-index)
     * @return Monoid 取得した結果
     */
    Monoid get(int k){
        __Check(k + __ZeroIndex);
        return __Data[__Offset + k + __ZeroIndex];
    }

    Monoid operator[](const int &k){
        return get(k);
    }
};