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
    vector<vector<T>> data_, cum_, weight_;
    int size_, offset_;

    void build_(vector<T> &V, vector<T> &W){
        size_ = 1;
        while(size_ < V.size()) size_ <<= 1;
        offset_ = size_ - 1;
        data_.resize(2 * size_);
        weight_.resize(2 * size_);
        for(int i = 0; i < (int)V.size(); ++i){
            data_[size_ + i].push_back(V[i]);
            weight_[size_ + i].push_back(W[i]);
        }
        for(int i = offset_; i >= 1; --i){
            int l = i * 2, r = i * 2 + 1, x = 0, y = 0;
            while(x < data_[l].size() or y < data_[r].size()){
                if(x == data_[l].size()){
                    data_[i].push_back(data_[r][y]);
                    weight_[i].push_back(weight_[r][y++]);
                    continue;
                }
                if(y == data_[r].size()){
                    data_[i].push_back(data_[l][x]);
                    weight_[i].push_back(weight_[l][x++]);
                    continue;
                }
                if(data_[l][x] < data_[r][y]){
                    data_[i].push_back(data_[l][x]);
                    weight_[i].push_back(weight_[l][x++]);
                }
                else{
                    data_[i].push_back(data_[r][y]);
                    weight_[i].push_back(weight_[r][y++]);
                }
            }
        }
        cum_.resize(2 * size_);
        for(int i = 0; i < cum_.size(); ++i){
            cum_[i].resize(data_[i].size() + 1, 0);
            for(int j = 0; j < data_[i].size(); ++j){
                cum_[i][j + 1] += cum_[i][j];
                cum_[i][j + 1] += weight_[i][j];
            }
        }
    }

    T query_(int ql, int qr, int left, int right, int cell, T x){
        if(qr <= left || right <= ql) return 0;
        if(ql <= left && right <= qr){
            int index = upper_bound(data_[cell].begin(), data_[cell].end(), x) - data_[cell].begin();
            return cum_[cell][index];
        }
        int mid = (left + right) / 2;
        T al = query_(ql, qr, left, mid, 2 * cell, x);
        T ar = query_(ql, qr, mid, right, 2 * cell + 1, x);
        return al + ar;
    }

    public:
    MergeSortTree(vector<T> &V){
        build_(V, vector<T>(V.size(), 1));
    }

    MergeSortTree(vector<T> &V, vector<T> &W){
        build_(V, W);
    }

    /**
     * @brief `[left, right)` に含まれる `x` 以下の値の `w` の総和を求める。
     * @param left 半開区間の左端(1-index)
     * @param right 半開区間の右端(1-index)
     * @param x 境界値
     * @return T クエリの答え
     */
    T query(int left, int right, T x){
        return query_(left, right, 1, size_ + 1, 1, x);
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
        for(int d = 1; i < size_ * 2; d <<= 1){
            for(int j = 0; j < d; ++i, ++j){
                cerr << j << " {";
                for(int k = 0; k < data_[i].size(); ++k){
                    cerr << data_[i][k] << (k + 1 == data_[i].size() ? "} " : ", ");
                }
                cerr << endl;
                cerr << "  {";
                for(int k = 0; k <= data_[i].size(); ++k){
                    cerr << cum_[i][k] << (k == data_[i].size() ? "} " : ", ");
                }
                cerr << endl;
            }
            cerr << "========================================\n";
        }
    }
};