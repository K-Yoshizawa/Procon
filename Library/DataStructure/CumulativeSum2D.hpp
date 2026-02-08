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
            data_.at(i).resize(width_, init_value);
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

    void Set(const int y, const int x, const T value){
        Validate(y, x);
        data_[y][x] = value;
    }

    void Add(const int y, const int x, const T value){
        Add(y, x, y, x, value);
    }

    void Add(const int y1, const int x1, const int y2, const int x2, const T value){
        Validate(y1, x1);
        Validate(y2, x2);
        data_[y1][x1] += value;
        data_[y2 + 1][x1] -= value;
        data_[y1][x2 + 1] -= value;
        data_[y2 + 1][x2 + 1] += value;
    }

    T Sum(const int y, const int x) const {
        Validate(y, x);
        return data_[y][x];
    }

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