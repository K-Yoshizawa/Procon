#pragma once

/**
 * @file EulerTour.hpp
 * @brief Euler Tour - オイラーツアー
 * @version 4.0
 * @date 2024-10-31
 */

#include "../Common.hpp"
#include "Tree.hpp"

template<typename CostType>
class EulerTour{
    public:
    using F = function<CostType(CostType)>;

    EulerTour(){}

    /**
     * @brief 木 `T` におけるオイラーツアーを構築する。
     * @param one_index `1-index` として扱いたいか `(default = false)`
     */
    EulerTour(RootedTree<CostType> &T, bool one_index = false) :
            T(T),
            vertex_size_(T.get_vertex_size()),
            in_time_(T.get_vertex_size()),
            out_time_(T.get_vertex_size()),
            one_index_(one_index){
        dfs(T.get_root());
    }

    /**
     * @brief 頂点 `v` に入った時刻を返す。
     * @note 時刻は `0-index` で返る。
     * @return int 頂点 `v` に入った時刻
     */
    int get_in(const Vertex v) const {
        return in_time_.at(v - one_index_);
    }

    /**
     * @brief 頂点 `v` から出た時刻を返す。
     * @note 時刻は `0-index` で返る。
     * @return int 頂点 `v` から出た時刻
     */
    int get_out(const Vertex v) const {
        return out_time_.at(v - one_index_);
    }

    /**
     * @brief 頂点 `v` に入った時刻と出た時刻の両方を返す。
     * @note 時刻は `0-index` で返る。
     * @return pair<int, int> 頂点 `v` に入った時刻と出た時刻
     */
    pair<int, int> get_pair(const Vertex v) const {
        return make_pair(in_time_.at(v - one_index_), out_time_.at(v - one_index_));
    }

    /**
     * @brief 配列 `value` をオイラーツアーに基づいて変換した配列を返す。
     * @note セグメント木などの初期配列として渡す場合になどに用いる。
     * @tparam Type 渡すデータの型
     * @param value 変換する配列
     * @param in_converter 頂点 `v` に入る時刻に対するデータを変換する関数
     * @param out_converter 頂点 `v` から出る時刻に対するデータを変換する関数
     * @return vector<Type> 変換した長さ `2 * |V|` の配列
     */
    template<typename Type>
    vector<Type> ConvertVector(const vector<Type> &value, const F in_converter, const F out_converter){
        vector<Type> ret(2 * vertex_size_);
        for(int i = 0; i < vertex_size_; ++i){
            int in_idx = in_time_.at(i), out_idx = out_time_.at(i);
            ret[in_idx] = in_converter(value.at(i));
            ret[out_idx] = out_converter(value.at(i));
        }
        return ret;
    }

    private:
    int time_{0}, one_index_, vertex_size_;

    RootedTree<CostType> &T;
    vector<int> in_time_, out_time_;

    void dfs(Vertex v){
        in_time_[v] = time_++;
        for(Vertex c : T.get_child(v)){
            dfs(c);
        }
        out_time_[v] = time_++;
    }
};