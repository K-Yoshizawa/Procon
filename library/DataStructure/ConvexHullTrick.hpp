/**
 * @file ConvexHullTrick.hpp
 * @brief Convex Hull Trick
 * @version 1.0
 * @date 2024-02-21
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 直線 `ax + b` の集合に対して、`x` における最小値(最大値)を求める
 * @tparam Type 直線の傾き `a` と切片 `b` の型
 */
template<typename Type>
struct ConvexHullTrick{
    private:
    map<Type, Type, greater<Type>> slope_to_intercept_;
    map<Type, Type> slope_to_rightend_;
    map<Type, Type> rightend_to_slope_;
    
    bool is_max_{false};
    Type inf_{numeric_limits<Type>::max() >> 2};

    Type calc_(Type al, Type bl, Type ar, Type br){
        return (Type)(br - bl) / (Type)(al - ar);
    }

    void add_(Type a, Type b){
        if(slope_to_intercept_.find(a) != slope_to_intercept_.end() and slope_to_intercept_[a] <= b) return;
        slope_to_intercept_[a] = b;
        auto itr = slope_to_intercept_.find(a);
        if(itr != slope_to_intercept_.begin() and next(itr) != slope_to_intercept_.end()){
            auto [al, bl] = *prev(itr);
            auto [ar, br] = *next(itr);
            if(calc_(al, bl, a, b) >= calc_(a, b, ar, br)){
                slope_to_intercept_.erase(a);
                if(slope_to_rightend_.find(a) != slope_to_rightend_.end()){
                    rightend_to_slope_.erase(slope_to_rightend_[a]);
                    slope_to_rightend_.erase(a);
                }
                return;
            }
        }
        auto litr = prev(itr);
        while(itr != slope_to_intercept_.begin() and litr != slope_to_intercept_.begin()){
            auto [all, bll] = *prev(litr);
            auto [al, bl] = *litr;
            if(calc_(all, bll, al, bl) >= calc_(al, bl, a, b)){
                slope_to_intercept_.erase(litr);
                rightend_to_slope_.erase(slope_to_rightend_[al]);
                slope_to_rightend_.erase(al);
                litr = prev(itr);
            }
            else break;
        }
        auto ritr = next(itr);
        while(ritr != slope_to_intercept_.end() and next(ritr) != slope_to_intercept_.end()){
            auto [arr, brr] = *next(ritr);
            auto [ar, br] = *ritr;
            if(calc_(a, b, ar, br) >= calc_(ar, br, arr, brr)){
                slope_to_intercept_.erase(ritr);
                rightend_to_slope_.erase(slope_to_rightend_[ar]);
                slope_to_rightend_.erase(ar);
                ritr = next(itr);
            }
            else break;
        }
        if(itr != slope_to_intercept_.begin()){
            auto [al, bl] = *prev(itr);
            Type lrht = calc_(al, bl, a, b);
            rightend_to_slope_.erase(slope_to_rightend_[al]);
            slope_to_rightend_[al] = lrht;
            rightend_to_slope_[lrht] = al;
        }
        if(next(itr) != slope_to_intercept_.end()){
            auto [ar, br] = *next(itr);
            Type rht = calc_(a, b, ar, br);
            if(slope_to_rightend_.find(a) != slope_to_rightend_.end()){
                rightend_to_slope_.erase(slope_to_rightend_[a]);
            }
            slope_to_rightend_[a] = rht;
            rightend_to_slope_[rht] = a;
        }
        else{
            if(slope_to_rightend_.find(a) != slope_to_rightend_.end()){
                rightend_to_slope_.erase(slope_to_rightend_[a]);
            }
            slope_to_rightend_[a] = inf_;
            rightend_to_slope_[inf_] = a;
        }
    }

    public:
    /**
     * @brief Convex Hull Trick を初期化する。
     * @param isMax 最大値クエリを処理する。
     */
    ConvexHullTrick(bool isMax = false) : is_max_(isMax){}

    /**
     * @brief 直線 `ax + b` を追加する。
     */
    void insert(Type a, Type b){
        if(is_max_) a = -a, b = -b;
        else add_(a, b);
    }

    /**
     * @brief `x` における最小値(最大値)クエリを処理する。
     */
    Type query(Type x){
        auto [r, a] = *(rightend_to_slope_.lower_bound(x));
        auto b = slope_to_intercept_[a];
        if(is_max_) a = -a, b = -b;
        return a * x + b;
    }
};