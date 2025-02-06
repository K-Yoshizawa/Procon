/**
 * @file WeightedUnionFind.hpp
 * @author log K (lX57)
 * @brief Weighted Union-Find - 重み付き素集合データ構造
 */

#include "../Common.hpp"

template<typename Abel = int32_t>
class WeightedUnionFind{
    public:
    /**
     * @brief 要素数 `size` で重み付き Union-Find を初期化します。
     * @note 要素番号は 0-index です。
     * @param size 要素数
     */
    WeightedUnionFind(int size) : data_(size, -1), weight_(size, Abel{}){}

    /**
     * @brief 要素 `k` が属する集合の代表元を返します。
     * @param k 探索する要素
     * @return 要素 `k` が属する集合の代表元
     */
    int Find(const int k){
        if(data_[k] < 0) return k;
        int r = Find(data_[k]);
        weight_[k] += weight_[data_[k]];
        return data_[k] = r;
    }

    /**
     * @brief 要素 `k` と要素 `k` が所属する代表元との重みの差を取得します。
     * @param k 探索する要素
     * @return 代表元との重みの差
     */
    Abel Weight(const int k) const {
        Find(k);
        return weight_[k];
    }

    /**
     * @brief 要素 `x` と要素 `y` の重みの差を取得します。
     * @attention 要素 `x` と要素 `y` が異なる集合に属しているときの挙動は未定義です。
     * @param x 要素番号
     * @param y 要素番号
     * @return 要素 `x` と要素 `y` の重みの差
     */
    Abel Diff(const int x, const int y) const {
        return Weight(y) - Weight(x);
    }

    /**
     * @brief 要素 `x` と要素 `y` が同じ集合に属しているかを判定します。
     * @param x 要素番号
     * @param y 要素番号
     * @return 同じ集合に属しているか
     */
    bool Same(const int x, const int y) const {
        return Find(x) == Find(y);
    }

    /**
     * @brief 要素 `x` と要素 `y` を関係 `weight[x] - weight[y] = w` が成立するように併合します。併合した場合は `true` を返します。
     * @param x 要素番号
     * @param y 要素番号
     * @param w 重み
     * @return 併合を行ったか
     */
    bool Unite(int x, int y, Abel w){
        w += Weight(x) - Weight(y);
        x = Find(x), y = Find(y);
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y), w = -w;
        data_[x] += data_[y];
        data_[y] = x;
        weight_[y] = w;
        return true;
    }

    private:
    vector<int> data_;
    vector<Abel> weight_;
};