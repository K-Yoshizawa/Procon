/**
 * @file CumulativeSum2D.hpp
 * @author log K (lX57)
 * @brief Cumulative Sum 2D - 二次元累積和
 * @version 3.0
 * @date 2024-10-21
 */

#include "../Common.hpp"

template<typename T = int32_t>
struct CumulativeSum2D{
    private:
    int height_, width_;
    vector<vector<T>> data_;

    void Validate(const int y, const int x) const {
        assert(0 <= y && y < height_ - 1);
        assert(0 <= x && x < width_ - 1);
    }

    public:
    CumulativeSum2D(const int height, const int width, const T init_value = 0) : height_(height + 1), width_(width + 1){
        data_.resize(height_);
        for(int i = 0; i < height_; ++i){
            data_.at(i).resize(width_);
        }
    }

    void Build(){
        for(int i = 1; i < height_; ++i){
            for(int j = 0; j < width_; ++j){
                data_[i][j] += data_[i - 1][j];
            }
        }
        for(int i = 0; i < height_; ++i){
            for(int j = 1; j < width_; ++j){
                data_[i][j] += data_[i][j - 1];
            }
        }
    }

    /**
     * @brief 座標 `(y, x)` に値 `value` を代入する。
     * @attention 座標指定は 0-indexで行うこと
     * @param value 代入する値
     */
    void Set(const int y, const int x, const T value){
        Validate(y, x);
        data_[y][x] = value;
    }

    /**
     * @brief 座標 `(y, x)` に値 `value` を加算する。
     * @attention 座標指定は 0-indexで行うこと
     * @param value 加算する値
     */
    void Add(const int y, const int x, const T value){
        Add(y, x, y, x, value);
    }

    /**
     * @brief 長方形領域 `[y1, y2] × [x1, x2]` に値 `value` を加算する。
     * @attention 座標指定は 0-index, 閉区間で行うこと
     * @param y1 長方形領域左上の y 座標
     * @param x1 長方形領域左上の x 座標
     * @param y2 長方形領域右下の y 座標
     * @param x2 長方形領域右下の x 座標
     * @param value 加算する値
     */
    void Add(const int y1, const int x1, const int y2, const int x2, const T value){
        Validate(y1, x1);
        Validate(y2, x2);
        data_[y1][x1] += value;
        data_[y2 + 1][x1] -= value;
        data_[y1][x2 + 1] -= value;
        data_[y2 + 1][x2 + 1] += value;
    }

    /**
     * @brief 長方形領域 `[0, y] × [0, x]` の累積和を計算する。
     * @attention 座標指定は 0-index, 閉区間で行うこと
     * @param y 長方形領域右下の y 座標
     * @param x 長方形領域右下の x 座標
     * @return T 
     */
    T Sum(const int y, const int x) const {
        Validate(y, x);
        return data_[y][x];
    }

    /**
     * @brief 長方形領域 `[y1, y2] × [x1, x2]` の累積和を計算する。
     * @attention 座標指定は 0-index, 閉区間で行うこと
     * @param y1 長方形領域左上の y 座標
     * @param x1 長方形領域左上の x 座標
     * @param y2 長方形領域右下の y 座標
     * @param x2 長方形領域右下の x 座標
     * @param value 加算する値
     * @return T 
     */
    T Sum(const int y1, const int x1, const int y2, const int x2) const {
        Validate(y1, x1);
        Validate(y2, x2);
        T ret = Sum(y2, x2);
        if(y1 > 0) ret -= Sum(y1 - 1, x2);
        if(x1 > 0) ret -= Sum(y2, x1 - 1);
        if(y1 > 0 && x1 > 0) ret += Sum(y1 - 1, x1 - 1);
        return ret;
    }

    T Max() const {
        T ret = data_[0][0];
        for(int i = 0; i < height_; ++i){
            for(int j = 0; j < width_; ++j){
                ret = max(ret, data_[i][j]);
            }
        }
        return ret;
    }

    T Min() const {
        T ret = data_[0][0];
        for(int i = 0; i < height_; ++i){
            for(int j = 0; j < width_; ++j){
                ret = min(ret, data_[i][j]);
            }
        }
        return ret;
    }

    vector<T> &operator[](const int k){
        return data_.at(k);
    }
};