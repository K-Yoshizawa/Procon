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
    int querysize_, rootq_, blocksize_;
    vector<q> query_;
    vector<vector<int>> index_;

    public:
    /**
     * @brief 区間長 `Segment_Size` の配列に対するクエリを登録する。
     * @param Segment_Size 配列の区間長
     * @param Query_Left クエリ `[l, r)` の半開区間左端の配列
     * @param Query_Right クエリ `[l, r)` の半開区間右端の配列
     */
    Mo(int Segment_Size, vector<int> &Query_Left, vector<int> &Query_Right){
        Segment_Size = max(1, Segment_Size);
        querysize_ = (int)Query_Left.size();
        rootq_ = max(1, (int)sqrt(querysize_));
        blocksize_ = (Segment_Size + rootq_ - 1) / rootq_;
        query_.resize(querysize_);
        index_.resize(blocksize_);
        for(int i = 0; i < querysize_; ++i){
            query_[i] = {Query_Left[i], Query_Right[i]};
            index_[Query_Left[i] / rootq_].push_back(i);
        }
        bool odd = true;
        for(auto &v : index_){
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
        for(auto &m : index_){
            for(auto i : m){
                auto [l, r] = query_[i];
                while(right < r) add(right++);
                while(right > r) sub(--right);
                while(left < l) sub(left++);
                while(left > l) add(--left);
                out(i);
            }
        }
    }
};