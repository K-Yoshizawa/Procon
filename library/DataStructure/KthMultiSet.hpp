#include <bits/stdc++.h>
using namespace std;

template<typename Data, typename Value = Data>
struct KthMultiSet{
    using F = function<Value(Value, Data)>;
    using G = function<bool(Data, Data)>;

    private:
    int K_;
    multiset<Data> P_, Q_;
    F add_, sub_;
    G require_;
    Value sum_;

    void balance(){
        while(P_.size() < K_ && Q_.size()){
            auto itr = Q_.begin();
            sum_ = add_(sum_, *itr);
            P_.insert(*itr);
            Q_.erase(itr);
        }
        if(P_.empty() || Q_.empty()) return;
        while(1){
            auto si = --(P_.end());
            auto li = Q_.begin();
            Data sv = (*si), lv = (*li);
            if(require_(sv, lv)) break;
            sum_ = add_(sub_(sum_, sv), lv);
            P_.erase(si), Q_.erase(li);
            P_.insert(lv), Q_.insert(sv);
        }
    }

    public:
    KthMultiSet(int K, 
        F Add = [](Value x, Data y){return x + y;}, 
        F Sub = [](Value x, Data y){return x - y;},
        G Require = [](Data x, Data y){return x <= y;})
        : K_(K), add_(Add), sub_(Sub), require_(Require), sum_(){}

    void insert(Data data){
        Q_.insert(data);
        balance();
    }

    void erase(Data value){
        auto itr = P_.find(value);
        if(itr != P_.end()){
            sum_ = sub_(sum_, value);
            P_.erase(itr);
        }
        else{
            assert(Q_.find(value) != Q_.end());
            Q_.erase(Q_.find(value));
        }
        balance();
    }

    inline bool exist(){
        return P_.size() == K_;
    }

    inline Data get(){
        assert(exist());
        return *(--(P_.end()));
    }

    inline Value sum(){
        return sum_;
    }
};