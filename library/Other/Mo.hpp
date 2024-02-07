/**
 * @file Mo.hpp
 * @author log K (lX57)
 * @brief Mo's Algorithm
 * @version 1.0
 * @date 2024-02-08
 */

#include <bits/stdc++.h>
using namespace std;

struct Mo{
    private:
    using q = pair<int, int>;
    using f = function<void(int)>;
    int m_querysize, m_rootq, m_blocksize;
    vector<q> m_query;
    vector<vector<int>> m_index;

    public:
    /**
     * @brief 区間長 `Segment_Size` の配列に対するクエリを登録する。
     * @param Segment_Size 配列の区間長
     * @param Query_Left クエリ `[l, r)` の半開区間左端の配列
     * @param Query_Right クエリ `[l, r)` の半開区間右端の配列
     */
    Mo(int Segment_Size, vector<int> &Query_Left, vector<int> &Query_Right){
        Segment_Size = max(1, Segment_Size);
        m_querysize = (int)Query_Left.size();
        m_rootq = max(1, (int)sqrt(m_querysize));
        m_blocksize = (Segment_Size + m_rootq - 1) / m_rootq;
        m_query.resize(m_querysize);
        m_index.resize(m_blocksize);
        for(int i = 0; i < m_querysize; ++i){
            m_query[i] = {Query_Left[i], Query_Right[i]};
            m_index[Query_Left[i] / m_rootq].push_back(i);
        }
        bool odd = true;
        for(auto &v : m_index){
            if(odd){
                sort(v.begin(), v.end(), [&](int i, int j){
                    return Query_Right[i] < Query_Right[j];
                });
            }
            else{
                sort(v.begin(), v.end(), [&](int i, int j){
                    return Query_Right[i] > Query_Right[j];
                });
            }
            odd = ~odd;
        }
    }

    /**
     * @brief クエリを処理する。
     * @param add 区間に含めるときの処理。引数には配列のインデックス番号(0-index)が渡される。
     * @param sub 区間から除くときの処理。引数には配列のインデックス番号(0-index)が渡される。
     * @param out クエリの答えを求めるときの処理。引数にはクエリの番号(0-index)が渡される。
     */
    void run(f add, f sub, f out){
        int left = 0, right = 0;
        for(auto &m : m_index){
            for(auto i : m){
                auto [l, r] = m_query[i];
                while(right < r) add(right++);
                while(right > r) sub(--right);
                while(left < l) sub(left++);
                while(left > l) add(--left);
                out(i);
            }
        }
    }
};