#include "../Common.hpp"

template<typename T>
class Compress{
    public:
    Compress(vector<T> &A, bool unique_flag = true) : data_(A){
        sort(data_.begin(), data_.end());
        if(unique_flag) data_.erase(unique(data_.begin(), data_.end()), data_.end());
        n_ = (int)data_.size();
    }

    int Index(const T x) const {
        int ret = distance(data_.begin(), lower_bound(data_.begin(), data_.end(), x));
        assert(ret < n_ && data_[ret] == x);
        return ret;
    }

    int LowerBound(const T x) const {
        int ret = distance(data_.begin(), lower_bound(data_.begin(), data_.end(), x));
        return ret;
    }

    int UpperBound(const T x) const {
        int ret = distance(data_.begin(), upper_bound(data_.begin(), data_.end(), x));
        return ret;
    }

    size_t Size() const {
        return n_;
    }

    T operator[](const int k) const {
        return data_.at(k);
    }

    private:
    size_t n_;
    vector<T> data_;
};