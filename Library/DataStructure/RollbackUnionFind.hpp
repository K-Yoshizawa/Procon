#include "../Common.hpp"

class RollbackUnionFind{
    public:
    RollbackUnionFind(size_t n) : data_(n, -1), record_(0){}

    int Find(const int k) const {
        if(data_[k] < 0) return k;
        return Find(data_[k]);
    }

    bool Same(const int x, const int y) const {
        return Find(x) == Find(y);
    }

    bool Unite(int x, int y){
        x = Find(x), y = Find(y);
        history_.push({x, data_[x]});
        history_.push({y, data_[y]});
        if(x == y) return false;
        if(data_[x] > data_[y]) swap(x, y);
        data_[x] += data_[y];
        data_[y] = x;
        return true;
    }
    
    int Size(const int k) const {
        return -data_[Find(k)];
    }
    
    vector<vector<int>> Group() const {
        vector<vector<int>> ret(data_.size());
        for(int i = 0; i < data_.size(); ++i){
            ret[Find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){
            return v.empty();
        }), end(ret));
        return ret;
    }

    void Record(){
        record_ = history_.size();
    }

    void Undo(){
        auto [y, dy] = history_.top();
        history_.pop();
        data_[y] = dy;
        auto [x, dx] = history_.top();
        history_.pop();
        data_[x] = dx;
    }

    void Rollback(){
        int state = record_;
        while(state < (int)history_.size()) Undo();
    }
    
    private:
    vector<int> data_;
    stack<pair<int, int>> history_;
    int record_;
};