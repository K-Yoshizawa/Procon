/**
 * @file CumulativeSum2D.hpp
 * @author log K (lX57)
 * @brief Cumulative Sum 2D - 二次元累積和
 * @version 2.0
 * @date 2023-10-03
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct CumulativeSum2D{
    private:
    int __YSize, __XSize;
    vector<vector<T>> __Data;

    public:
    CumulativeSum2D(int Y, int X, T Init = 0) : __YSize(Y), __XSize(X){
        __Data.resize(__YSize + 1, vector<T>(__XSize + 1, Init));
    }

    void add(int y, int x, T value = 1){
        assert(0 <= y && y <= __YSize);
        assert(0 <= x && x <= __XSize);
        __Data[y][x] += value;
    }

    void add(int sy, int sx, int ty, int tx, T value = 1){
        add(sy, sx, value);
        add(sy, tx, -value);
        add(ty, sx, -value);
        add(ty, tx, value);
    }

    void build(){
        for(int i = 0; i <= __YSize; ++i){
            for(int j = 1; j <= __XSize; ++j){
                __Data[i][j] += __Data[i][j - 1];
            }
        }
        for(int j = 0; j <= __XSize; ++j){
            for(int i = 1; i <= __YSize; ++i){
                __Data[i][j] += __Data[i - 1][j];
            }
        }
    }

    CumulativeSum2D(vector<vector<T>> Init_Data) : __YSize(Init_Data.size()), __XSize(Init_Data[0].size()){
        __Data.resize(__YSize + 1);
        for(int i = 0; i < __YSize; ++i){
            __Data[i].resize(__XSize + 1);
            for(int j = 0; j < __XSize; ++j){
                __Data[i][j] = Init_Data[i][j];
            }
        }
        __Data[__YSize].resize(__XSize, 0);
        build();
    }

    /**
     * @brief `(0, 0)` を左上、 `(y, x)` を右下とする長方形領域の合計を求める。
     * @attention 座標系はすべて0-indexである
     * @return T 合計
     */
    T sum(int y, int x){
        assert(y <= __YSize);
        assert(x <= __XSize);
        if(y < 0 || x < 0) return 0;
        return __Data[y][x];
    }

    /**
     * @brief `(sy, sx)` を左上、 `(ty, tx)` を右下とする長方形領域の合計を求める。
     * @attention 座標系はすべて0-indexである
     * @return T 合計
     */
    T sum(int sy, int sx, int ty, int tx){
        return sum(ty, tx) - sum(ty, sx - 1) - sum(sy - 1, tx) + sum(sy - 1, sx - 1);
    }

    /**
     * @brief 累積和配列全体の最大値を取得する。
     */
    T max(){
        T ret = __Data[0][0];
        for(int i = 0; i <= __YSize; ++i){
            for(int j = 0; j <= __XSize; ++j){
                ret = std::max(ret, __Data[i][j]);
            }
        }
        return ret;
    }

    /**
     * @brief 累積和配列全体の最小値を取得する。
     */
    T min(){
        T ret = __Data[0][0];
        for(int i = 0; i <= __YSize; ++i){
            for(int j = 0; j <= __XSize; ++j){
                ret = std::min(ret, __Data[i][j]);
            }
        }
        return ret;
    }
};