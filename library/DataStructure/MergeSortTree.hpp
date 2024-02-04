/**
 * @file MergeSortTree.hpp
 * @brief Merge-Sort Tree - 領域木
 * @version 1.0
 * @date 2024-02-04
 */

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct MergeSortTree{
    private:
    vector<vector<T>> m_data, m_cum, m_weight;
    int m_size, m_offset;

    void build(vector<T> &V, vector<T> &W){
        m_size = 1;
        while(m_size < V.size()) m_size <<= 1;
        m_offset = m_size - 1;
        m_data.resize(2 * m_size);
        m_weight.resize(2 * m_size);
        for(int i = 0; i < (int)V.size(); ++i){
            m_data[m_size + i].push_back(V[i]);
            m_weight[m_size + i].push_back(W[i]);
        }
        for(int i = m_offset; i >= 1; --i){
            int l = i * 2, r = i * 2 + 1, x = 0, y = 0;
            while(x < m_data[l].size() or y < m_data[r].size()){
                if(x == m_data[l].size()){
                    m_data[i].push_back(m_data[r][y]);
                    m_weight[i].push_back(m_weight[r][y++]);
                    continue;
                }
                if(y == m_data[r].size()){
                    m_data[i].push_back(m_data[l][x]);
                    m_weight[i].push_back(m_weight[l][x++]);
                    continue;
                }
                if(m_data[l][x] < m_data[r][y]){
                    m_data[i].push_back(m_data[l][x]);
                    m_weight[i].push_back(m_weight[l][x++]);
                }
                else{
                    m_data[i].push_back(m_data[r][y]);
                    m_weight[i].push_back(m_weight[r][y++]);
                }
            }
        }
        m_cum.resize(2 * m_size);
        for(int i = 0; i < m_cum.size(); ++i){
            m_cum[i].resize(m_data[i].size() + 1, 0);
            for(int j = 0; j < m_data[i].size(); ++j){
                m_cum[i][j + 1] += m_cum[i][j];
                m_cum[i][j + 1] += m_weight[i][j];
            }
        }
    }

    T query(int ql, int qr, int left, int right, int cell, T x){
        if(qr <= left || right <= ql) return 0;
        if(ql <= left && right <= qr){
            int index = upper_bound(m_data[cell].begin(), m_data[cell].end(), x) - m_data[cell].begin();
            return m_cum[cell][index];
        }
        int mid = (left + right) / 2;
        T al = query(ql, qr, left, mid, 2 * cell, x);
        T ar = query(ql, qr, mid, right, 2 * cell + 1, x);
        return al + ar;
    }

    public:
    MergeSortTree(vector<T> &V){
        build(V, vector<T>(V.size(), 1));
    }

    MergeSortTree(vector<T> &V, vector<T> &W){
        build(V, W);
    }

    /**
     * @brief `[left, right)` に含まれる `x` 以下の値の `w` の総和を求める。
     * @param left 半開区間の左端(1-index)
     * @param right 半開区間の右端(1-index)
     * @param x 境界値
     * @return T クエリの答え
     */
    T query(int left, int right, T x){
        return query(left, right, 1, m_size + 1, 1, x);
    }

    /**
     * @brief `[left, right) x [lower, upper)` に含まれる `w` の総和を求める。
     * @param left x軸半開区間の左端(1-index)
     * @param right x軸半開区間の右端(1-index)
     * @param lower y軸半開区間の下端(1-index)
     * @param upper y軸半開区間の上端(1-index)
     * @return T 
     */
    T rect_query(int left, int right, T lower, T upper){
        return query(left, right, upper - 1) - query(left, right, lower - 1);
    }

    /**
     * @brief MSTの中身を出力する
     */
    void print(){
        int i = 1;
        for(int d = 1; i < m_size * 2; d <<= 1){
            for(int j = 0; j < d; ++i, ++j){
                cerr << j << " {";
                for(int k = 0; k < m_data[i].size(); ++k){
                    cerr << m_data[i][k] << (k + 1 == m_data[i].size() ? "} " : ", ");
                }
                cerr << endl;
                cerr << "  {";
                for(int k = 0; k <= m_data[i].size(); ++k){
                    cerr << m_cum[i][k] << (k == m_data[i].size() ? "} " : ", ");
                }
                cerr << endl;
            }
            cerr << "========================================\n";
        }
    }
};