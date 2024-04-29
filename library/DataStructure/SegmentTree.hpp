/**
 * @file SegmentTree.hpp
 * @author log K (lX57)
 * @brief Segment Tree - セグメント木
 * @version 2.2
 * @date 2023-10-02
 */

#include <bits/stdc++.h>
using namespace std;

template<typename Monoid>
struct SegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;

    int size_, offset_, zeroindex_;
    vector<Monoid> data_;
    const F f;
    const Monoid m1_;

    inline void check_(int x){
        assert(1 <= x && x <= size_);
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
    : f(Merge), m1_(Monoid_Identity), zeroindex_(ZeroIndex){
        size_ = 1;
        while(size_ < Size) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
    }

    /**
     * @brief セグメント木を構築する。
     * @attention 必ず `set()` で初期値を代入してから呼び出すこと！
     */
    void build(){
        for(int i = offset_; i >= 1; --i){
            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);
        }
    }

    /**
     * @brief セグメント木の初期値を代入する。
     * @param Index 代入先の要素番号 (default = 1-index)
     * @param Value 代入する値
     */
    void set(int Index, Monoid Value){
        check_(Index + zeroindex_);
        data_[offset_ + Index + zeroindex_] = Value;
    }

    /**
     * @brief セグメント木を配列 `Init_Data` で初期化する。
     * @param Init_Data 初期データの配列
     * @param Merge 区間取得を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    SegmentTree(vector<Monoid> &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)
    : f(Merge), m1_(Monoid_Identity), zeroindex_(ZeroIndex){
        size_ = 1;
        while(size_ < (int)Init_Data.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            data_[size_ + i] = Init_Data[i];
        }
        build();
    }

    /**
     * @brief 一点更新クエリを処理する。
     * @param Index 更新先の要素番号 (default = 1-index)
     * @param Value 更新する値
     */
    void update(int Index, Monoid Value){
        check_(Index + zeroindex_);
        int k = offset_ + Index + zeroindex_;
        data_[k] = Value;
        while(k >>= 1){
            data_[k] = f(data_[2 * k], data_[2 * k + 1]);
        }
    }

    /**
     * @brief 半開区間 `[Left, Right)` に対して区間取得クエリを行う。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid query(int Left, int Right){
        if(Left == Right) return m1_;
        check_(Left + zeroindex_);
        check_(Right + zeroindex_ - 1);
        int l = Left + zeroindex_ + offset_, r = Right + zeroindex_ + offset_;
        Monoid al = m1_, ar = m1_;
        while(l < r){
            if(l & 1) al = f(al, data_[l++]);
            if(r & 1) ar = f(data_[--r], ar);
            l >>= 1, r >>= 1;
        }
        return f(al, ar);
    }

    /**
     * @brief 要素番号 `k` の要素を取得する。
     * @param k 取得先の要素番号 (default = 1-index)
     * @return Monoid 取得した結果
     */
    Monoid get(int k){
        check_(k + zeroindex_);
        return data_[offset_ + k + zeroindex_];
    }

    Monoid operator[](const int &k){
        return get(k);
    }
};