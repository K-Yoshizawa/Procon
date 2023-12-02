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
class CumulativeSum2D{
    int __Y, __X;
    vector<vector<T>> __Data;

    public:
    /**
     * @brief 二次元累積和を `Init` で初期化する
     * @attention この時点では構築されていないので注意
     * @param Init 初期配列
     */
    CumulativeSum2D(vector<vector<T>> &Init){
        __Y = Init.size(), __X = Init[0].size();
        __Data.resize(__Y, vector<T>(__X));
        for(int i = 0; i < __Y; ++i){
            for(int j = 0; j < __X; ++j){
                __Data[i][j] = Init[i][j];
            }
        }
    }

    /**
     * @brief 二次元累積和を構築する
     */
    void build(){
        for(int i = 0; i < __Y; ++i){
            for(int j = 1; j < __X; ++j){
                __Data[i][j] += __Data[i][j - 1];
            }
        }
        for(int i = 1; i < __Y; ++i){
            for(int j = 0; j < __X; ++j){
                __Data[i][j] += __Data[i - 1][j];
            }
        }
    }

    /**
     * @brief `(y, x)` に値 `value` を加算する
     * @attention `y, x` は0-index
     */
    void add(int y, int x, T value){
        __Data[y][x] += value;
    }

    /**
     * @brief `(y1, x1)` を左上、 `(y2, x2)` を右下とする長方形領域に値 `value` を加算する
     * @attention `y1, x1, y2, x2` は0-indexで、領域は `[y1, y2] and [x1, x2]` を指す
     */
    void add(int y1, int x1, int y2, int x2, T value){
        __Data[y1][x1] += value;
        if(y2 + 1 < __Y) __Data[y2 + 1][x1] -= value;
        if(x2 + 1 < __X) __Data[y1][x2 + 1] -= value;
        if(y2 + 1 < __Y and x2 + 1 < __X) __Data[y2 + 1][x2 + 1] += value;
    }

    /**
     * @brief `(0, 0)` を左上、 `(y, x)` を右下とする長方形領域の累積値を求める
     * @attention `y, x` は0-indexで、領域は `[0, y] and [0, x]` を指す
     */
    T query(int y, int x){
        return __Data[y][x];
    }

    /**
     * @brief `(y1, x1)` を左上、 `(y2, x2)` を右下とする長方形領域の累積値を求める
     * @attention `y1, x1, y2, x2` は0-indexで、領域は `[y1, y2] and [x1, x2]` を指す
     */
    T query(int y1, int x1, int y2, int x2){
        T ret = __Data[y2][x2];
        if(y1 > 0) ret -= __Data[y1 - 1][x2];
        if(x1 > 0) ret -= __Data[y2][x1 - 1];
        if(y1 > 0 and x1 > 0) ret += __Data[y1 - 1][x1 - 1];
        return ret;
    }

    /**
     * @brief 領域全体に比較関数を適用させ、その結果を得る
     * @param compare 比較関数 : 引数は `src, cmp` で戻り値は `T`
     */
    T search(function<T(T, T)> compare){
        T ret = __Data[0][0];
        for(int i = 0; i < __Y; ++i){
            for(int j = 0; j < __X; ++j){
                ret = compare(ret, __Data[i][j]);
            }
        }
        return ret;
    }

    /**
     * @brief 領域全体の条件を満たすマスの数を数える
     * @param condition 関数 : 引数は `T` で戻り値は `bool`
     */
    int count(function<bool(T)> condition){
        int ret = 0;
        for(int i = 0; i < __Y; ++i){
            for(int j = 0; j < __X; ++j){
                ret += condition(__Data[i][j]);
            }
        }
        return ret;
    }
};