/**
 * @file LazySegmentTree.hpp
 * @author log K (lX57)
 * @brief Lazy Segment Tree - 遅延評価セグメント木
 * @version 2.0
 * @date 2023-10-02
 */

#include "../Common.hpp"

template<typename Monoid, typename OperatorMonoid = Monoid>
class LazySegmentTree{
    public:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    /**
     * @brief セグメント木を要素数 `size` で初期化する。
     * @param size セグメント木の要素数
     * @param merge 区間取得を行う演算
     * @param mapping 遅延評価の適用を行う演算
     * @param composite 遅延評価の合成を行う演算
     * @param monoid_identity モノイドの単位元
     * @param operator_identity 操作モノイドの単位元
     * @param zero_index 0-indexとして扱いたいか (default = `false`)
     */
    LazySegmentTree(int size, F merge, G mapping, H composite,
    const Monoid &monoid_identity, const OperatorMonoid &operator_identity, bool zero_index = false)
    : f(merge), g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){
        size_ = 1;
        while(size_ < size) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
        lazy_.resize(2 * size_, om1_);
        is_identity_.resize(2 * size_, true);
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
        Validate(index + zeroindex_);
        data_[offset_ + index + zeroindex_] = value;
    }

    /**
     * @brief セグメント木を配列 `init_data` で初期化する。
     * @param init_data 初期データの配列
     * @param merge 区間取得を行う演算
     * @param mapping 遅延評価の適用を行う演算
     * @param composite 遅延評価の合成を行う演算
     * @param monoid_identity モノイドの単位元
     * @param operator_identity 操作モノイドの単位元
     * @param zero_index 0-indexとして扱いたいか (default = `false`)
     */
    LazySegmentTree(vector<Monoid> &init_data, F merge, G mapping, H composite,
    const Monoid &monoid_identity, const OperatorMonoid &operator_identity, bool zero_index = false)
    : f(merge), g(mapping), h(composite), m1_(monoid_identity), om1_(operator_identity), zeroindex_(zero_index){
        size_ = 1;
        while(size_ < (int)init_data.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_, m1_);
        lazy_.resize(2 * size_, om1_);
        is_identity_.resize(2 * size_, true);
        for(int i = 0; i < (int)init_data.size(); ++i){
            data_[size_ + i] = init_data[i];
        }
        Build();
    }

    /**
     * @brief 半開区間 `[left, right)` に対して区間更新クエリを処理する。
     * @param left 半開区間の左端
     * @param right 半開区間の右端
     * @param OP 更新操作
     */
    void Update(int left, int right, OperatorMonoid operation){
        Validate(left + zeroindex_);
        Validate(right + zeroindex_ - 1);
        RecursiveUpdate(left + zeroindex_, right + zeroindex_, operation, 1, size_ + 1, 1);
    }

    /**
     * @brief 半開区間 `[left, right)` に対して区間取得クエリを行う。
     * @param left 半開区間の左端
     * @param right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid Query(int left, int right){
        Validate(left + zeroindex_);
        Validate(right + zeroindex_ - 1);
        return RecursiveQuery(left + zeroindex_, right + zeroindex_, 1, size_ + 1, 1);
    }

    /**
     * @brief 要素番号 `k` の要素を取得する。
     * @param k 取得先の要素番号 (default = 1-index)
     * @return Monoid 取得した結果
     */
    Monoid get_value(int k){
        Validate(k + zeroindex_);
        return Query(k, k + 1);
    }

    Monoid operator[](const int &k){
        return get_value(k);
    }

    private:
    int size_, offset_, zeroindex_;
    vector<Monoid> data_;
    vector<OperatorMonoid> lazy_;
    vector<bool> is_identity_;
    const F f;
    const G g;
    const H h;
    const Monoid m1_;
    const OperatorMonoid om1_;

    inline void Validate(int x){
        assert(1 <= x && x <= size_);
    }

    void Evaluate(int k){
        if(is_identity_[k]) return;
        if(k < size_){
            lazy_[k * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);
            is_identity_[k * 2 + 0] = false;
            lazy_[k * 2 + 1] = h(lazy_[k * 2 + 1], lazy_[k]);
            is_identity_[k * 2 + 1] = false;
        }
        data_[k] = g(data_[k], lazy_[k]);
        lazy_[k] = om1_;
        is_identity_[k] = true;
    }

    void RecursiveUpdate(int ul, int ur, OperatorMonoid x, int left, int right, int cell){
        Evaluate(cell);
        if(ul <= left && right <= ur){
            lazy_[cell] = h(lazy_[cell], x);
            is_identity_[cell] = false;
            Evaluate(cell);
        }
        else if(ul < right && left < ur){
            int mid = (left + right) / 2;
            RecursiveUpdate(ul, ur, x, left, mid, cell * 2 + 0);
            RecursiveUpdate(ul, ur, x, mid, right, cell * 2 + 1);
            data_[cell] = f(data_[cell * 2 + 0], data_[cell * 2 + 1]);
        }
    }

    Monoid RecursiveQuery(int ql, int qr, int left, int right, int cell){
        Evaluate(cell);
        if(qr <= left || right <= ql){
            return m1_;
        }
        if(ql <= left && right <= qr){
            return data_[cell];
        }
        int mid = (left + right) / 2;
        Monoid ans_left = RecursiveQuery(ql, qr, left, mid, cell * 2 + 0);
        Monoid ans_right = RecursiveQuery(ql, qr, mid, right, cell * 2 + 1);
        return f(ans_left, ans_right);
    }
};