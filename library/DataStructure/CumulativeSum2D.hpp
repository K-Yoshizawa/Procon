/**
 * @file CumulativeSum2D.hpp
 * @author log K (lX57)
 * @brief Cumulative Sum 2D - 二次元累積和
 * @version 1.1
 * @date 2023-08-24
 */

#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @attention 配列は外側に1要素大きくとって実装していることに注意すること 
 */
template<typename T>
struct CumulativeSum2D{
    private:
    int Y, X;
    vector<vector<T>> cum;

    public:
    /**
     * @brief  二次元累積和の初期化
     * @param  Y_size 縦のサイズ
     * @param  X_size 横のサイズ
     * @param  init 初期値
     */
    CumulativeSum2D(int Y_size, int X_size, T init = 0) : Y(Y_size), X(X_size){
        cum.resize(Y + 2, vector<T>(X + 2, init));
        for(int i = 0; i <= Y; ++i) cum[i][0] = cum[i][X + 1] = 0;
        for(int j = 0; j <= X; ++j) cum[0][j] = cum[Y + 1][j] = 0;
    }

    /**
     * @brief  (y, x)要素にvalueをセットする。
     * @attention build前に呼び出すこと
     * @param  x 要素の添字 (0-index)
     * @param  y 要素の添字 (0-index)
     * @param  value セットする値
     */
    void set(int x, int y, T value){
        assert(0 <= x && x < X && 0 <= y && y < Y);
        cum[y + 1][x + 1] = value;
    }

    /**
     * @brief (sy, sx)を左上、(ty, tx)を右下とする長方形領域に対してvalueを加算する。
     * @note (sy, sx)と(ty, tx)はそれぞれ長方形の隅（半開区間）
     * @param sx 左上マスのx座標 (0-index)
     * @param sy 左上マスのy座標 (0-index)
     * @param tx 右下マスのx座標 (0-index)
     * @param ty 右下マスのy座標 (0-index)
     * @param value 加算する値
     */
    void add(int sx, int sy, int tx, int ty, T value){
        assert(0 <= sx && sx < X && 0 <= sy && sy < Y);
        assert(0 <= tx && tx < X && 0 <= ty && ty < Y);
        ++sx, ++sy, ++tx, ++ty;
        cum[sy][sx] += value;
        cum[sy][tx] -= value;
        cum[ty][sx] -= value;
        cum[ty][tx] += value;
    }

    /**
     * @brief 累積和配列を構築する。
     * @attention setで初期値の入力を済ませておくこと
     */
    void build(){
        for(int i = 1; i <= Y; ++i){
            for(int j = 1; j <= X; ++j){
                cum[i][j] += cum[i][j - 1];
            }
        }
        for(int j = 1; j <= X; ++j){
            for(int i = 1; i <= Y; ++i){
                cum[i][j] += cum[i - 1][j];
            }
        }
    }

    /**
     * @brief (sy, sx)を左上、(ty, tx)を右下とする長方形領域に対するクエリを解く。
     * @note (sy, sx)と(ty, tx)はそれぞれ長方形の隅（半開区間）
     * @param sx 左上マスのx座標 (0-index)
     * @param sy 左上マスのy座標 (0-index)
     * @param tx 右下マスのx座標 (0-index)
     * @param ty 右下マスのy座標 (0-index)
     * @return T クエリの結果
     */
    T query(int sx, int sy, int tx, int ty){
        assert(0 <= sx && sx < X && 0 <= sy && sy < Y);
        assert(0 <= tx && tx < X && 0 <= ty && ty < Y);
        ++sx, ++sy, ++tx, ++ty;
        return cum[ty][tx] - cum[ty][sx - 1] - cum[sy - 1][tx] + cum[sy - 1][sx - 1];
    }

    /**
     * @brief 累積和配列全体の最大値を求める。
     * @return T 最大値
     */
    T max(){
        T ret = numeric_limits<T>::min() / 2;
        for(int i = 1; i <= Y; ++i){
            for(int j = 1; j <= X; ++j){
                ret = std::max(ret, cum[i][j]);
            }
        }
        return ret;
    }
    
    /**
     * @brief 累積和配列全体の最小値を求める。
     * @return T 最小値
     */
    T min(){
        T ret = numeric_limits<T>::max() / 2;
        for(int i = 1; i <= Y; ++i){
            for(int j = 1; j <= X; ++j){
                ret = std::min(ret, cum[i][j]);
            }
        }
        return ret;
    }

    bool test(int y, int x, function<bool(T)> func){
        ++y, ++x;
        return func(cum[y][x]);
    }

    /**
     * @brief 渡した関数の条件を満たす要素の数を数える
     * @param func 条件判定の関数
     * @return int 条件を満たす要素の数
     */
    int count_if(function<bool(T)> func){
        int ret = 0;
        for(int i = 1; i <= Y; ++i){
            for(int j = 1; j <= X; ++j){
                if(func(cum[i][j])) ++ret;
            }
        }
        return ret;
    }

    void print(bool edge = false){
        for(int i = !edge; i <= Y + edge; ++i){
            for(int j = !edge; j <= X + edge; ++j){
                cerr << cum[i][j] << " ";
            }
            cerr << endl;
        }
    }
};