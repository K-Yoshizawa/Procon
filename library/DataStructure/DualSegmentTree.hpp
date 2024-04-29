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

    int size_, offset_, zeroindex_;
    vector<OperatorMonoid> lazy_;
    const H h;
    const OperatorMonoid om1_;

    inline void check_(int x){
        assert(1 <= x && x <= size_);
    }

    void eval_(int k){
        if(lazy_[k] == om1_) return;
        if(k < size_){
            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);
            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);
            lazy_[k] = om1_;
        }
    }

    void update_(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        eval_(cell);
        if(ul <= left && right <= ur){
            lazy_[cell] = h(lazy_[cell], x);
            eval_(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            update_(ul, ur, x, left, mid, cell * 2 + 0);
            update_(ul, ur, x, mid, right, cell * 2 + 1);
        }
    }
    
    OperatorMonoid query_(int k, int left, int right, int cell){
        eval_(cell);
        if(k == left && right - left == 1) return lazy_[cell];
        int mid = (left + right) / 2;
        if(k < mid) return query_(k, left, mid, cell * 2 + 0);
        else return query_(k, mid, right, cell * 2 + 1);
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
    : h(Composite), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){
        size_ = 1;
        while(size_ < Size) size_ <<= 1;
        offset_ = size_ - 1;
        lazy_.resize(2 * size_, om1_);
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
    : h(Composite), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){
        size_ = 1;
        while(size_ < (int)Init_Data.size()) size_ <<= 1;
        offset_ = size_ - 1;
        lazy_.resize(2 * size_, om1_);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            lazy_[size_ + i] = Init_Data[i];
        }
    }

    /**
     * @brief 半開区間 `[Left, Right)` に対して区間更新クエリを処理する。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @param OP 更新操作
     */
    void update(int Left, int Right, OperatorMonoid OP){
        check_(Left + zeroindex_);
        check_(Right + zeroindex_ - 1);
        update_(Left + zeroindex_, Right + zeroindex_, OP, 1, size_ + 1, 1);
    }

    /**
     * @brief 要素番号 `k` の要素を取得する。
     * @param k 取得先の要素番号 (default = 1-index)
     * @return OperatorMonoid 取得した結果
     */
    OperatorMonoid query(int k){
        check_(k + zeroindex_);
        return query_(k + zeroindex_, 1, size_ + 1, 1);
    }

    OperatorMonoid operator[](const int &k){
        return query(k);
    }
};