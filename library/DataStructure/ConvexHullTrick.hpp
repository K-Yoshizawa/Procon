/**
 * @file ConvexHullTrick.hpp
 * @brief Convex Hull Trick
 * @version 1.0
 * @date 2024-02-21
 */

#include <bits/stdc++.h>
using namespace std;

template<typename Line, typename Point = Line>
struct ConvexHullTrick{
    private:
    union{
        map<Line, Line, greater<Line>> slp_inc;
    };
    map<Line, Point> slp_rht;
    map<Point, Line> rht_slp;
    
    bool is_max{false}, add_monotone{false}, query_monotone{false};
    Point INF{numeric_limits<Point>::max() / 4};

    Point f(Line al, Line bl, Line ar, Line br){
        return (Point)(br - bl) / (Point)(al - ar);
    }

    void m_add(Line a, Line b){
        if(slp_inc.contains(a) and slp_inc[a] <= b) return;
        slp_inc[a] = b;
        auto itr = slp_inc.find(a);
        if(itr != slp_inc.begin() and next(itr) != slp_inc.end()){
            auto [al, bl] = *prev(itr);
            auto [ar, br] = *next(itr);
            if(f(al, bl, a, b) >= f(a, b, ar, br)){
                slp_inc.erase(a);
                if(slp_rht.contains(a)){
                    rht_slp.erase(slp_rht[a]);
                    slp_rht.erase(a);
                }
                return;
            }
        }
        auto litr = prev(itr);
        while(itr != slp_inc.begin() and litr != slp_inc.begin()){
            auto [all, bll] = *prev(litr);
            auto [al, bl] = *litr;
            if(f(all, bll, al, bl) >= f(al, bl, a, b)){
                slp_inc.erase(litr);
                rht_slp.erase(slp_rht[al]);
                slp_rht.erase(al);
                litr = prev(itr);
            }
            else break;
        }
        auto ritr = next(itr);
        while(ritr != slp_inc.end() and next(ritr) != slp_inc.end()){
            auto [arr, brr] = *next(ritr);
            auto [ar, br] = *ritr;
            if(f(a, b, ar, br) >= f(ar, br, arr, brr)){
                slp_inc.erase(ritr);
                rht_slp.erase(slp_rht[ar]);
                slp_rht.erase(ar);
                ritr = next(itr);
            }
            else break;
        }
        if(itr != slp_inc.begin()){
            auto [al, bl] = *prev(itr);
            Point lrht = f(al, bl, a, b);
            rht_slp.erase(slp_rht[al]);
            slp_rht[al] = lrht;
            rht_slp[lrht] = al;
        }
        if(next(itr) != slp_inc.end()){
            auto [ar, br] = *next(itr);
            Point rht = f(a, b, ar, br);
            if(slp_rht.contains(a)){
                rht_slp.erase(slp_rht[a]);
            }
            slp_rht[a] = rht;
            rht_slp[rht] = a;
        }
        else{
            if(slp_rht.contains(a)){
                rht_slp.erase(slp_rht[a]);
            }
            slp_rht[a] = INF;
            rht_slp[INF] = a;
        }
    }

    public:
    ConvexHullTrick(bool isMax = false, bool AddMonotone = false, bool QueryMonotone = false) : 
    is_max(isMax), add_monotone(AddMonotone), query_monotone(QueryMonotone){}

    void insert(Line a, Line b){
        if(is_max) a = -a, b = -b;
        if(add_monotone);
        else m_add(a, b);
    }

    Line query(Point x){
        auto [r, a] = *(rht_slp.lower_bound(x));
        auto b = slp_inc[a];
        if(is_max) a = -a, b = -b;
        return a * x + b;
    }
};