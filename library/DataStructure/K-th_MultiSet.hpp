#include <bits/stdc++.h>
using namespace std;

template<typename Data, typename Value = Data>
struct Kth_MultiSet{
    using F = function<Value(Value, Data)>;
    using G = function<bool(Data, Data)>;

    private:
    int __K;
    multiset<Data> __P, __Q;
    F __Add, __Sub;
    G __Require;
    Value __Sum;

    void balance(){
        while(__P.size() < __K && __Q.size()){
            auto itr = __Q.begin();
            __Sum = __Add(__Sum, *itr);
            __P.insert(*itr);
            __Q.erase(itr);
        }
        if(__P.empty() || __Q.empty()) return;
        while(1){
            auto si = --(__P.end());
            auto li = __Q.begin();
            Data sv = (*si), lv = (*li);
            if(__Require(sv, lv)) break;
            __Sum = __Add(__Sub(__Sum, sv), lv);
            __P.erase(si), __Q.erase(li);
            __P.insert(lv), __Q.insert(sv);
        }
    }

    public:
    Kth_MultiSet(int K, 
        F Add = [](Value x, Data y){return x + y;}, 
        F Sub = [](Value x, Data y){return x - y;},
        G Require = [](Data x, Data y){return x <= y;})
        : __K(K), __Add(Add), __Sub(Sub), __Require(Require), __Sum(){}

    void insert(Data data){
        __Q.insert(data);
        balance();
    }

    void erase(Data value){
        auto itr = __P.find(value);
        if(itr != __P.end()){
            __Sum = __Sub(__Sum, value);
            __P.erase(itr);
        }
        else{
            assert(__Q.find(value) != __Q.end());
            __Q.erase(__Q.find(value));
        }
        balance();
    }

    inline bool exist(){
        return __P.size() == __K;
    }

    inline Data get(){
        assert(exist());
        return *(--(__P.end()));
    }

    inline Value sum(){
        return __Sum;
    }
};