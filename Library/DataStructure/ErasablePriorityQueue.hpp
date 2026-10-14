#include "../Common.hpp"

template<typename T>
class ErasablePriorityQueue{
    public:
    ErasablePriorityQueue() = default;

    void Push(T x){
        que_.push({x, priority_--});
    }

    void Pop(){
        Normalize();
        if(!Empty()) que_.pop();
    }

    void Erase(T value){
        erase_.push({value, priority_--});
    }

    T Top(){
        Normalize();
        if(Empty()) return null_;
        else return que_.top().first;
    }

    bool Empty(){
        Normalize();
        return que_.empty();
    }

    private:
    using P = pair<T, int>;
    priority_queue<P> que_, erase_;
    int priority_{0};
    T null_{numeric_limits<T>::min()};

    void Normalize(){
        while(!que_.empty() && !erase_.empty()){
            P x = que_.top(), y = erase_.top();
            if(x.first < y.first || x.first == y.first && x.second < y.second){
                erase_.pop();
                continue;
            }
            if(x.first == y.first && x.second > y.second){
                que_.pop();
                erase_.pop();
                continue;
            }
            if(x.first > y.first){
                break;
            }
        }
    }
};