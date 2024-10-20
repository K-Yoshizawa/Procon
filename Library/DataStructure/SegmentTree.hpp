/**
 * @file SegmentTree.hpp
 * @author log K (lX57)
 * @brief Segment Tree - セグメント木
 * @version 3.0
 * @date 2024-09-04
 */

#include "../Common.hpp"

template<typename Monoid>
class SegmentTree{
    public:
    using F = function<Monoid(Monoid, Monoid)>;

    /**
     * @brief セグメント木を要素数 `size` で初期化する。
     * @param size セグメント木の要素数
     * @param merge 区間取得を行う演算
     * @param monoid_identity モノイドの単位元
     * @param zero_index 0-indexとして扱いたいか (default = `false`)
     */
    SegmentTree(int size, F merge, const Monoid &monoid_identity, bool zero_index = false) :
            f(merge), id_(monoid_identity), zero_index_(zero_index){
        size_ = 1;
        while(size_ < size) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, id_);
    }

    /**
     * @brief セグメント木を構築する。
     * @attention 必ず `Set()` で初期値を代入してから呼び出すこと！
     */
    void Build(){
        for(int i = offset_; i >= 1; --i){
            data_[i] = f(data_[i * 2 + 0], data_[i * 2 + 1]);
        }
    }

    /**
     * @brief セグメント木の初期値を代入する。
     * @param index 代入先の要素番号 (default = 1-index)
     * @param value 代入する値
     */
    void Set(int index, Monoid value){
        Validate(index + zero_index_);
        data_[offset_ + index + zero_index_] = value;
    }

    /**
     * @brief セグメント木を配列 `init_data` で初期化する。
     * @param init_data 初期データの配列
     * @param merge 区間取得を行う演算
     * @param monoid_identity モノイドの単位元
     * @param zero_index 0-indexとして扱いたいか (default = `false`)
     */
    SegmentTree(vector<Monoid> &init_data, F merge, const Monoid &monoid_identity, bool zero_index = false) :
            f(merge), id_(monoid_identity), zero_index_(zero_index){
        size_ = 1;
        while(size_ < (int)init_data.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, id_);
        for(int i = 0; i < (int)init_data.size(); ++i){
            data_[size_ + i] = init_data[i];
        }
        Build();
    }

    /**
     * @brief 一点更新クエリを処理する。
     * @param index 更新先の要素番号 (default = 1-index)
     * @param value 更新する値
     */
    void Update(int index, Monoid value){
        Validate(index + zero_index_);
        int k = offset_ + index + zero_index_;
        data_[k] = value;
        while(k >>= 1){
            data_[k] = f(data_[2 * k], data_[2 * k + 1]);
        }
    }

    /**
     * @brief 半開区間 `[left, Right)` に対して区間取得クエリを行う。
     * @param left 半開区間の左端
     * @param right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid Query(int left, int right){
        if(left == right) return id_;
        Validate(left + zero_index_);
        Validate(right + zero_index_ - 1);
        int l = left + zero_index_ + offset_, r = right + zero_index_ + offset_;
        Monoid al = id_, ar = id_;
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
    Monoid get_value(int k){
        Validate(k + zero_index_);
        return data_[offset_ + k + zero_index_];
    }

    Monoid operator[](const int &k){
        return get_value(k);
    }

    private:
    int size_, offset_, zero_index_;
    vector<Monoid> data_;
    const F f;
    const Monoid id_;

    inline void Validate(int x) const {
        assert(1 <= x && x <= size_);
    }
};