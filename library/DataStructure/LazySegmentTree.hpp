/**
 * @file LazySegmentTree.hpp
 * @author log K (lX57)
 * @brief Lazy Segment Tree - 遅延評価セグメント木
 * @version 2.0
 * @date 2023-10-02
 */

#include <bits/stdc++.h>
using namespace std;

template<typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int size_, offset_, zeroindex_;
    vector<Monoid> data_;
    vector<OperatorMonoid> lazy_;
    vector<bool> is_identify_;
    const F f;
    const G g;
    const H h;
    const Monoid m1_;
    const OperatorMonoid om1_;

    inline void check_(int x){
        assert(1 <= x && x <= size_);
    }

    void eval_(int k){
        if(is_identify_[k]) return;
        if(k < size_){
            lazy_[k << 1 | 0] = h(lazy_[k << 1 | 0], lazy_[k]);
            is_identify_[k << 1 | 0] = false;
            lazy_[k << 1 | 1] = h(lazy_[k << 1 | 1], lazy_[k]);
            is_identify_[k << 1 | 1] = false;
        }
        data_[k] = g(data_[k], lazy_[k]);
        lazy_[k] = om1_;
        is_identify_[k] = true;
    }

    void update_(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        eval_(cell);
        if(ul <= left && right <= ur){
            lazy_[cell] = h(lazy_[cell], x);
            is_identify_[cell] = false;
            eval_(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            update_(ul, ur, x, left, mid, cell << 1 | 0);
            update_(ul, ur, x, mid, right, cell << 1 | 1);
            data_[cell] = f(data_[cell << 1 | 0], data_[cell << 1 | 1]);
        }
    }

    Monoid query_(int ql, int qr, int left, int right, int cell){
        eval_(cell);
        if(qr <= left || right <= ql){
            return m1_;
        }
        if(ql <= left && right <= qr){
            return data_[cell];
        }
        int mid = (left + right) / 2;
        Monoid ans_left = query_(ql, qr, left, mid, cell << 1 | 0);
        Monoid ans_right = query_(ql, qr, mid, right, cell << 1 | 1);
        return f(ans_left, ans_right);
    }

    public:
    /**
     * @brief セグメント木を要素数 `Size` で初期化する。
     * @param Size セグメント木の要素数
     * @param Merge 区間取得を行う演算
     * @param Mapping 遅延評価の適用を行う演算
     * @param Composite 遅延評価の合成を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param OperatorMonoid_Identity 操作モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    LazySegmentTree(int Size, F Merge, G Mapping, H Composite,
    const Monoid &Monoid_Identity, const OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)
    : f(Merge), g(Mapping), h(Composite), m1_(Monoid_Identity), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){
        size_ = 1;
        while(size_ < Size) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
        lazy_.resize(2 * size_, om1_);
        is_identify_.resize(2 * size_, true);
    }

    /**
     * @brief セグメント木を構築する。
     * @attention 必ず `set()` で初期値を代入してから呼び出すこと！
     */
    void build(){
        for(int i = offset_; i >= 1; --i){
            data_[i] = f(data_[i << 1 | 0], data_[i << 1 | 1]);
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
     * @param Mapping 遅延評価の適用を行う演算
     * @param Composite 遅延評価の合成を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param OperatorMonoid_Identity 操作モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    LazySegmentTree(vector<Monoid> &Init_Data, F Merge, G Mapping, H Composite,
    const Monoid &Monoid_Identity, const OperatorMonoid &OperatorMonoid_Identity, bool ZeroIndex = false)
    : f(Merge), g(Mapping), h(Composite), m1_(Monoid_Identity), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){
        size_ = 1;
        while(size_ < (int)Init_Data.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
        lazy_.resize(2 * size_, om1_);
        is_identify_.resize(2 * size_, true);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            data_[size_ + i] = Init_Data[i];
        }
        build();
    }

    /**
     * @brief 半開区間 `[left, Right)` に対して区間更新クエリを処理する。
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
     * @brief 半開区間 `[Left, Right)` に対して区間取得クエリを行う。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid query(int Left, int Right){
        check_(Left + zeroindex_);
        check_(Right + zeroindex_ - 1);
        return query_(Left + zeroindex_, Right + zeroindex_, 1, size_ + 1, 1);
    }

    /**
     * @brief 要素番号 `k` の要素を取得する。
     * @param k 取得先の要素番号 (default = 1-index)
     * @return Monoid 取得した結果
     */
    Monoid get(int k){
        check_(k + zeroindex_);
        return query(k, k + 1);
    }

    Monoid operator[](const int &k){
        return get(k);
    }
};