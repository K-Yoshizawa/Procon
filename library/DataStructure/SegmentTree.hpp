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

    int m_size, m_offset, m_zeroindex;
    vector<Monoid> m_data;
    const F f;
    const Monoid m_m1;

    inline void m_check(int x){
        assert(1 <= x && x <= m_size);
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
    : f(Merge), m_m1(Monoid_Identity), m_zeroindex(ZeroIndex){
        m_size = 1;
        while(m_size < Size) m_size <<= 1;
        m_offset = m_size - 1;
        m_data.resize(2 * m_size, m_m1);
    }

    /**
     * @brief セグメント木を構築する。
     * @attention 必ず `set()` で初期値を代入してから呼び出すこと！
     */
    void build(){
        for(int i = m_offset; i >= 1; --i){
            m_data[i] = f(m_data[i * 2 + 0], m_data[i * 2 + 1]);
        }
    }

    /**
     * @brief セグメント木の初期値を代入する。
     * @param Index 代入先の要素番号 (default = 1-index)
     * @param Value 代入する値
     */
    void set(int Index, Monoid Value){
        m_check(Index + m_zeroindex);
        m_data[m_offset + Index + m_zeroindex] = Value;
    }

    /**
     * @brief セグメント木を配列 `Init_Data` で初期化する。
     * @param Init_Data 初期データの配列
     * @param Merge 区間取得を行う演算
     * @param Monoid_Identity モノイドの単位元
     * @param ZeroIndex 0-indexとして扱いたいか (default = `false`)
     */
    SegmentTree(vector<Monoid> &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false)
    : f(Merge), m_m1(Monoid_Identity), m_zeroindex(ZeroIndex){
        m_size = 1;
        while(m_size < (int)Init_Data.size()) m_size <<= 1;
        m_offset = m_size - 1;
        m_data.resize(2 * m_size, m_m1);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            m_data[m_size + i] = Init_Data[i];
        }
        build();
    }

    /**
     * @brief 一点更新クエリを処理する。
     * @param Index 更新先の要素番号 (default = 1-index)
     * @param Value 更新する値
     */
    void update(int Index, Monoid Value){
        m_check(Index + m_zeroindex);
        int k = m_offset + Index + m_zeroindex;
        m_data[k] = Value;
        while(k >>= 1){
            m_data[k] = f(m_data[2 * k], m_data[2 * k + 1]);
        }
    }

    /**
     * @brief 半開区間 `[Left, Right)` に対して区間取得クエリを行う。
     * @param Left 半開区間の左端
     * @param Right 半開区間の右端
     * @return Monoid 取得した結果
     */
    Monoid query(int Left, int Right){
        if(Left == Right) return m_m1;
        m_check(Left + m_zeroindex);
        m_check(Right + m_zeroindex - 1);
        int l = Left + m_zeroindex + m_offset, r = Right + m_zeroindex + m_offset;
        Monoid al = m_m1, ar = m_m1;
        while(l < r){
            if(l & 1) al = f(al, m_data[l++]);
            if(r & 1) ar = f(m_data[--r], ar);
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
        m_check(k + m_zeroindex);
        return m_data[m_offset + k + m_zeroindex];
    }

    Monoid operator[](const int &k){
        return get(k);
    }
};