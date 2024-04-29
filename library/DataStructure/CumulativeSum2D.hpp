/**
 * @file CumulativeSum2D.hpp
 * @author log K (lX57)
 * @brief Cumulative Sum 2D - 二次元累積和
 * @version 2.0
 * @date 2023-12-03
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct CumulativeSum2D{
    private:
    int Y_, X_;
    vector<vector<T>> data_;

    public:
    /**
     * @brief 二次元累積和を `Init` で初期化する
     * @attention この時点では構築されていないので注意
     * @param Init 初期配列
     */
    CumulativeSum2D(vector<vector<T>> &Init){
        Y_ = Init.size(), X_ = Init[0].size();
        data_.resize(Y_, vector<T>(X_));
        for(int i = 0; i < Y_; ++i){
            for(int j = 0; j < X_; ++j){
                data_[i][j] = Init[i][j];
            }
        }
    }

    /**
     * @brief 二次元累積和を構築する
     */
    void build(){
        for(int i = 0; i < Y_; ++i){
            for(int j = 1; j < X_; ++j){
                data_[i][j] += data_[i][j - 1];
            }
        }
        for(int i = 1; i < Y_; ++i){
            for(int j = 0; j < X_; ++j){
                data_[i][j] += data_[i - 1][j];
            }
        }
    }

    /**
     * @brief `(y, x)` に値 `Value` を加算する
     * @attention `y, x` は0-index
     */
    void add(int y, int x, T Value){
        data_[y][x] += Value;
    }

    /**
     * @brief `(y1, x1)` を左上、 `(y2, x2)` を右下とする長方形領域に値 `Value` を加算する
     * @attention `y1, x1, y2, x2` は0-indexで、領域は `[y1, y2] and [x1, x2]` を指す
     */
    void add(int y1, int x1, int y2, int x2, T Value){
        data_[y1][x1] += Value;
        if(y2 + 1 < Y_) data_[y2 + 1][x1] -= Value;
        if(x2 + 1 < X_) data_[y1][x2 + 1] -= Value;
        if(y2 + 1 < Y_ and x2 + 1 < X_) data_[y2 + 1][x2 + 1] += Value;
    }

    /**
     * @brief `(0, 0)` を左上、 `(y, x)` を右下とする長方形領域の累積値を求める
     * @attention `y, x` は0-indexで、領域は `[0, y] and [0, x]` を指す
     */
    T query(int y, int x){
        return data_[y][x];
    }

    /**
     * @brief `(y1, x1)` を左上、 `(y2, x2)` を右下とする長方形領域の累積値を求める
     * @attention `y1, x1, y2, x2` は0-indexで、領域は `[y1, y2] and [x1, x2]` を指す
     */
    T query(int y1, int x1, int y2, int x2){
        T ret = data_[y2][x2];
        if(y1 > 0) ret -= data_[y1 - 1][x2];
        if(x1 > 0) ret -= data_[y2][x1 - 1];
        if(y1 > 0 and x1 > 0) ret += data_[y1 - 1][x1 - 1];
        return ret;
    }

    /**
     * @brief 領域全体に比較関数を適用させ、その結果を得る
     * @param Compare 比較関数 : 引数は `src, cmp` で戻り値は `T`
     */
    T search(function<T(T, T)> Compare){
        T ret = data_[0][0];
        for(int i = 0; i < Y_; ++i){
            for(int j = 0; j < X_; ++j){
                ret = Compare(ret, data_[i][j]);
            }
        }
        return ret;
    }

    /**
     * @brief 領域全体の条件を満たすマスの数を数える
     * @param Condition 関数 : 引数は `T` で戻り値は `bool`
     */
    int count(function<bool(T)> Condition){
        int ret = 0;
        for(int i = 0; i < Y_; ++i){
            for(int j = 0; j < X_; ++j){
                ret += Condition(data_[i][j]);
            }
        }
        return ret;
    }
};