#pragma once

#include "../Common.hpp"

template<typename IMonoid>
class SparseTable{
    public:
    SparseTable() = default;

    SparseTable(
        const vector<IMonoid> &A,
        const function<IMonoid(IMonoid, IMonoid)> f = [](IMonoid x, IMonoid y){
            return min(x, y);
        }
    ) : op_(f){
        N_ = (int)A.size(), rows_ = 0;
        while(1 << (rows_ + 1) <= N_) ++rows_;
        data_.resize(rows_ + 1, vector<IMonoid>(N_ + 1));
        for(int i = 0; i < N_; ++i) data_[0][i] = A[i];
        for(int k = 0; k < rows_; ++k){
            for(int i = 0; i + (1 << k) <= N_; ++i){
                data_[k + 1][i] = op_(data_[k][i], data_[k][i + (1 << k)]);
            }
        }
    }

    inline IMonoid Query(const int &l, const int &r) const {
        assert(0 <= l && l < r && r <= N_);
        int k = bit_width((uint32_t)r - l) - 1;
        return op_(data_[k][l], data_[k][r - (1 << k)]);
    }

    private:
    vector<vector<IMonoid>> data_;
    function<IMonoid(IMonoid, IMonoid)> op_;
    int N_, rows_;
};