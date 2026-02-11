#include "../Common.hpp"

template <typename T, typename U = T>
class MergeSortTree{
    public:
    MergeSortTree(
        const vector<T> &A,
        const vector<U> &B,
        bool zero_index = false
    ) : zero_index_(zero_index){
        Build(A, B);
    }
    
    MergeSortTree(
        const vector<T> &A,
        bool zero_index = false
    ) : zero_index_(zero_index){
        Build(A, A);
    }

    int CountAtMost(int l, int r, T x) const {
        if(l >= r) return 0;
        Validate(l + zero_index_);
        Validate(r + zero_index_ - 1);
        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;
        int lcnt = 0, rcnt = 0;
        while(lh < rh){
            if(lh & 1){
                lcnt += distance(data_[lh].begin(), upper_bound(data_[lh].begin(), data_[lh].end(), x));
                ++lh;
            }
            if(rh & 1){
                --rh;
                rcnt += distance(data_[rh].begin(), upper_bound(data_[rh].begin(), data_[rh].end(), x));
            }
            lh >>= 1, rh >>= 1;
        }
        return lcnt + rcnt;
    }

    U SumAtMost(int l, int r, T x) const {
        if(l >= r) return 0;
        Validate(l + zero_index_);
        Validate(r + zero_index_ - 1);
        int lh = l + zero_index_ + offset_, rh = r + zero_index_ + offset_;
        U lval = 0, rval = 0;
        while(lh < rh){
            if(lh & 1){
                int idx = distance(data_[lh].begin(), upper_bound(data_[lh].begin(), data_[lh].end(), x));
                lval += prefix_sum_[lh][idx];
                ++lh;
            }
            if(rh & 1){
                --rh;
                int idx = distance(data_[rh].begin(), upper_bound(data_[rh].begin(), data_[rh].end(), x));
                rval += prefix_sum_[rh][idx];
            }
            lh >>= 1, rh >>= 1;
        }
        return lval + rval;
    }
    
    private:
    int n_, offset_, zero_index_;
    vector<vector<T>> data_;
    vector<vector<U>> weight_, prefix_sum_;

    void Build(const vector<T> &data, const vector<U> &weight){
        n_ = 1;
        while(n_ < (int)data.size()) n_ <<= 1;
        offset_ = n_ - 1;
        data_.resize(2 * n_);
        weight_.resize(2 * n_);
        prefix_sum_.resize(2 * n_);
        for(int i = 0; i < (int)data.size(); ++i){
            data_[n_ + i].emplace_back(data[i]);
            weight_[n_ + i].emplace_back(weight[i]);
            prefix_sum_[n_ + i].emplace_back(0);
            prefix_sum_[n_ + i].emplace_back(weight[i]);
        }
        for(int i = offset_; i >= 1; --i){
            int l = i * 2 + 0, r = i * 2 + 1, li = 0, ri = 0, j = 0;
            int ls = (int)data_[l].size(), rs = (int)data_[r].size();
            data_[i].resize(ls + rs);
            weight_[i].resize(ls + rs);
            prefix_sum_[i].resize(ls + rs + 1);
            while(li < ls || ri < rs){
                if(ri == rs || li != ls && data_[l][li] < data_[r][ri]){
                    data_[i][j] = data_[l][li];
                    weight_[i][j] = weight_[l][li];
                    prefix_sum_[i][j + 1] = prefix_sum_[i][j] + weight_[i][j];
                    ++j, ++li;
                }
                else{
                    data_[i][j] = data_[r][ri];
                    weight_[i][j] = weight_[r][ri];
                    prefix_sum_[i][j + 1] = prefix_sum_[i][j] + weight_[i][j];
                    ++j, ++ri;
                }
            }
        }
    }
    
    inline void Validate(int x) const {
        assert(1 <= x && x <= n_);
    }
};