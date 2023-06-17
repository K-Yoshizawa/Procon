#pragma once

/**
 * @brief K-th MultiSet - K番目の値に関するデータ構造
 */

#include <set>
using namespace std;

template<typename T>
struct Kth_MultiSet{
    private:
    int K;
    bool greater;
    multiset<T> small, large;
    T __sum;

    void balance(){
        if(greater){
            while(large.size() < K && small.size()){
                auto itr = --(small.end());
                __sum += (*itr);
                large.insert(*itr);
                small.erase(itr);
            }
            if(small.empty() || large.empty()) return;
            while(1){
                auto si = --(small.end());
                auto li = large.begin();
                T sv = (*si), lv = (*li);
                if(sv <= lv) break;
                __sum += (sv - lv);
                small.erase(si), large.erase(li);
                small.insert(lv), large.insert(sv);
            }
        }
        else{
            while(small.size() < K && large.size()){
                auto itr = large.begin();
                __sum += (*itr);
                small.insert(*itr);
                large.erase(itr);
            }
            if(small.empty() || large.empty()) return;
            while(1){
                auto si = --(small.end());
                auto li = large.begin();
                T sv = (*si), lv = (*li);
                if(sv <= lv) break;
                __sum -= (sv - lv);
                small.erase(si), large.erase(li);
                small.insert(lv), large.insert(sv);
            }
        }
    }

    public:
    Kth_MultiSet(int K, bool greater = false) : K(K), greater(greater), __sum(0){}

    /**
     * @brief 値valueを追加する。
     * @param value 追加したい値
     */
    void insert(T value){
        if(greater) small.insert(value);
        else large.insert(value);
        balance();
    }

    void erase(T value){
        if(greater){
            auto itr = large.find(value);
            if(itr != large.end()){
                __sum -= value;
                large.erase(itr);
            }
            else{
                assert(small.find(value) != small.end());
                small.erase(small.find(value));
            }
        }
        else{
            auto itr = small.find(value);
            if(itr != small.end()){
                __sum -= value;
                small.erase(itr);
            }
            else{
                assert(large.find(value) != large.end());
                large.erase(large.find(value));
            }
        }
        balance();
    }

    inline T sum(){
        return __sum;
    }

    inline bool exist(){
        return greater ? large.size() == K : small.size() == K;
    }

    inline T get(){
        assert(exist());
        return greater ? *(large.begin()) : *(--(small.end()));
    }
};