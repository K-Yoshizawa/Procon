#pragma once

#include "../Common.hpp"

template<typename ValueType>
class SparseTable{
    public:
    SparseTable(const vector<ValueType> &A) : N((int)A.size()){
        int row = 0;
        while(1 << (row + 1) <= N) ++row;
        data_.resize(row + 1, vector<ValueType>(N + 1));
        for(int i = 0; i < N; ++i) data_[0][i] = A[i];
        for(int k = 0; k < row; ++k){
            for(int i = 0; i + (1 << k) <= N; ++i){
                data_[k + 1][i] = min(data_[k][i], data_[k][i + (1 << k)]);
            }
        }
    }

    inline ValueType Fold(int l, int r) const {
        assert(0 <= l && l < r && r <= N);
        int k = bit_width((uint32_t)r - l) - 1;
        return min(data_[k][l], data_[k][r - (1 << k)]);
    }

    private:
    vector<vector<ValueType>> data_;
    int N;
};