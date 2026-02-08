#pragma once

#include "Common.hpp"

inline bool YnPrint(bool flag){cout << (flag ? "Yes" : "No") << '\n'; return flag;}
inline bool YNPrint(bool flag){cout << (flag ? "YES" : "NO") << '\n'; return flag;}
template<typename Container>
inline void Sort(Container &container){sort(container.begin(), container.end());}
template<typename Container>
inline void ReverseSort(Container &container){sort(container.rbegin(), container.rend());}
template<typename Container>
inline void Reverse(Container &container){reverse(container.begin(), container.end());}
template<typename Value>
inline int PopCount(const Value &value){return __builtin_popcount(value);}
template<typename Value>
inline Value Floor(Value numerator, Value denominator){if(denominator < 0) numerator *= -1, denominator *= -1; return numerator < 0 ? (numerator + 1) / denominator - 1 : numerator / denominator;}
template<typename Value>
inline Value Ceil(Value numerator, Value denominator){if(denominator < 0) numerator *= -1, denominator *= -1; return numerator > 0 ? (numerator - 1) / denominator + 1 : numerator / denominator;}
template<typename Value>
inline int LowerBoundIndex(const vector<Value> &container, const Value &value){return distance(container.begin(), lower_bound(container.begin(), container.end(), value));}
template<typename Value>
inline int UpperBoundIndex(const vector<Value> &container, const Value &value){return distance(container.begin(), upper_bound(container.begin(), container.end(), value));}
template<typename Value>
inline bool Between(const Value &lower, const Value &x, const Value &higher){return lower <= x && x <= higher;}
template<typename Value>
inline bool InGrid(const Value &y, const Value &x, const Value &ymax, const Value &xmax){return Between(0, y, ymax - 1) && Between(0, x, xmax - 1);}
template<typename Value>
inline Value Median(const Value &a, const Value &b, const Value &c){return Between(b, a, c) || Between(c, a, b) ? a : (Between(a, b, c) || Between(c, b, a) ? b : c);}
template<typename Value>
inline Value Except(Value &src, Value &cond, Value &excp){return (src == cond ? excp : src);}

template<class Value>
bool chmin(Value &src, const Value &cmp){if(src > cmp){src = cmp; return true;} return false;}
template<class Value>
bool chmax(Value &src, const Value &cmp){if(src < cmp){src = cmp; return true;} return false;}
template<typename Value>
inline Value min(vector<Value> &v){return *min_element((v).begin(), (v).end());}
template<typename Value>
inline Value max(vector<Value> &v){return *max_element((v).begin(), (v).end());}

const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, -1, 0, 1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};

vector<pair<int, int>> adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8 = false){
    vector<pair<int, int>> ret;
    for(int d = 0; d < 4 * (1 + dir_8); ++d){
        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);
        int next_x = current_x + (dir_8 ? dx8[d] : dx4[d]);
        if(InGrid(next_y, next_x, max_y, max_x)){
            ret.emplace_back(next_y, next_x);
        }
    }
    return ret;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p){
    os << p.first << " " << p.second;
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p){
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v){
    for (int i = 0; i < v.size(); ++i){
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &v){
    for (int i = 0; i < v.size(); ++i){
        os << v[i] << (i + 1 != v.size() ? "\n" : "");
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v){
    for (int i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> &v){
    for (auto &u : v){
        os << u << " ";
    }
    return os;
}

template<typename T1, typename T2>
vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){
    assert(v1.size() == v2.size());
    vector<pair<T1, T2>> v;
    for(int i = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});
    return v;
}

template<typename T1, typename T2>
pair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1, T2>> &v){
    vector<T1> v1;
    vector<T2> v2;
    transform(v.begin(), v.end(), back_inserter(v1), [](auto p){return p.first;});
    transform(v.begin(), v.end(), back_inserter(v2), [](auto p){return p.second;});
    return {v1, v2};
}

template<typename T1, typename T2, typename T3>
tuple<vector<T1>, vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v){
    vector<T1> v1;
    vector<T2> v2;
    vector<T3> v3;
    transform(v.begin(), v.end(), back_inserter(v1), [](auto p){return get<0>(p);});
    transform(v.begin(), v.end(), back_inserter(v2), [](auto p){return get<1>(p);});
    transform(v.begin(), v.end(), back_inserter(v3), [](auto p){return get<2>(p);});
    return {v1, v2, v3};
}

template<typename T1 = int, typename T2 = T1>
pair<vector<T1>, vector<T2>> InputVectorPair(int size){
    vector<pair<T1, T2>> v(size);
    for(auto &[p, q] : v) cin >> p >> q;
    return DisassembleVectorPair(v);
}

template<typename T1 = int, typename T2 = T1, typename T3 = T1>
tuple<vector<T1>, vector<T2>, vector<T3>> InputVectorTuple(int size){
    vector<tuple<T1, T2, T3>> v(size);
    for(auto &[p, q, r] : v) cin >> p >> q >> r;
    return DisassembleVectorTuple(v);
}
