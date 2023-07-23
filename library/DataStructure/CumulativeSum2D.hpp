/**
 * @file CumulativeSum2D.hpp
 * @author log K (lX57)
 * @brief Cumulative Sum 2D - 二次元累積和
 * @date 2023-07-24
 */

#include <bits/stdc++.h>
using namespace std;

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
     * @note (sy, sx)と(ty, tx)はそれぞれ長方形"内部"の隅（閉区間）
     * @param sx 左上マスのx座標 (0-index)
     * @param sy 左上マスのy座標 (0-index)
     * @param tx 右下マスのx座標 (0-index)
     * @param ty 右下マスのy座標 (0-index)
     * @param value 加算する値
     */
    void add(int sx, int sy, int tx, int ty, T value){
        assert(0 <= sx && sx < X && 0 <= sy && sy < Y);
        assert(0 <= tx && tx < X && 0 <= ty && ty < Y);
        cum[sy + 1][sx + 1] += value;
        cum[sy + 1][tx + 2] -= value;
        cum[ty + 2][sx + 1] -= value;
        cum[ty + 2][tx + 2] += value;
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
     * @note (sy, sx)と(ty, tx)はそれぞれ長方形"内部"の隅（閉区間）
     * @param sx 左上マスのx座標 (0-index)
     * @param sy 左上マスのy座標 (0-index)
     * @param tx 右下マスのx座標 (0-index)
     * @param ty 右下マスのy座標 (0-index)
     * @return T クエリの結果
     */
    T query(int sx, int sy, int tx, int ty){
        assert(0 <= sx && sx < X && 0 <= sy && sy < Y);
        assert(0 <= tx && tx < X && 0 <= ty && ty < Y);
        return cum[ty + 1][tx + 1] - cum[ty + 1][sx] - cum[sy][tx + 1] + cum[sy][sx];
    }

    /**
     * @brief 累積和配列全体の最大値を求める。
     * @return T 最大値
     */
    T max(){
        T ret = numeric_limits<T>::min();
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
        T ret = numeric_limits<T>::max();
        for(int i = 1; i <= Y; ++i){
            for(int j = 1; j <= X; ++j){
                ret = std::min(ret, cum[i][j]);
            }
        }
        return ret;
    }
};