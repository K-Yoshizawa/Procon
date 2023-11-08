/**
 * @file DualSegmentTree.hpp
 * @author log K (lX57)
 * @brief Dual Segment Tree - 双対セグメント木
 * @version 1.0
 * @date 2023-11-08
 */

#include <bits/stdc++.h>
using namespace std;

template<typename OperatorMonoid>
struct DualSegmentTree{
    private:
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int __Size, __Offset, __ZeroIndex;
    vector<OperatorMonoid> __Lazy;
    const H h;
    const OperatorMonoid __OM1;

    inline void __Check(int x){
        assert(1 <= x && x <= __Size);
    }

    void __eval(int k){
        if(__Lazy[k] == __OM1) return;
        if(k < __Size){
            __Lazy[k * 2 + 0] = h(__Lazy[k * 2 + 0], __Lazy[k]);
            __Lazy[k * 2 + 1] = h(__Lazy[k * 2 + 1], __Lazy[k]);
            __Lazy[k] = __OM1;
        }
    }

    void __update(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        __eval(cell);
        if(ul <= left && right <= ur){
            __Lazy[cell] = h(__Lazy[cell], x);
            __eval(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            __update(ul, ur, x, left, mid, cell * 2 + 0);
            __update(ul, ur, x, mid, right, cell * 2 + 1);
        }
    }
    
    OperatorMonoid __query(int k, int left, int right, int cell){
        __eval(cell);
        if(k == left && right - left == 1) return __Lazy[cell];
        int mid = (left + right) / 2;
        if(k < mid) return __query(k, left, mid, cell * 2 + 0);
        else return __query(k, mid, right, cell * 2 + 1);
    }

    public:
    /**
     * @brief 双対セグメント木を要素数 `Size` で初期化する。
     * @param Size 双対セグメント木の要素数
     * @param Composite 遅延評価の合成を行う演算
     * @param OperatorMonoid_Identity 操作モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    DualSegmentTree(int Size, H Composite,
    const OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)
    : h(Composite), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < Size) __Size <<= 1;
        __Offset = __Size - 1;
        __Lazy.resize(2 * __Size, __OM1);
    }
    
    /**
     * @brief 双対セグメント木を要素数 `Size` で初期化する。
     * @param Init_Data 初期データの配列
     * @param Composite 遅延評価の合成を行う演算
     * @param OperatorMonoid_Identity 操作モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    DualSegmentTree(vector<OperatorMonoid> &Init_Data, H Composite,
    const OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)
    : h(Composite), __OM1(OperatorMonoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < (int)Init_Data.size()) __Size <<= 1;
        __Offset = __Size - 1;
        __Lazy.resize(2 * __Size, __OM1);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            __Lazy[__Size + i] = Init_Data[i];
        }
    }

    /**
     * @brief 半開区間 `[Left, Right)` に対して区間更新クエリを処理する。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @param OP 更新操作
     */
    void update(int Left, int Right, OperatorMonoid OP){
        __Check(Left + __ZeroIndex);
        __Check(Right + __ZeroIndex - 1);
        __update(Left + __ZeroIndex, Right + __ZeroIndex, OP, 1, __Size + 1, 1);
    }

    /**
     * @brief 要素番号 `k` の要素を取得する。
     * @param k 取得先の要素番号 (default = 1-index)
     * @return OperatorMonoid 取得した結果
     */
    OperatorMonoid query(int k){
        __Check(k + __ZeroIndex);
        return __query(k + __ZeroIndex, 1, __Size + 1, 1);
    }

    OperatorMonoid operator[](const int &k){
        return query(k);
    }
};