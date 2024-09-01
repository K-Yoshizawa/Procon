#pragma once

/**
 * @file lX57Lib.hpp
 * @author log K / lX57
 * @brief lX57 Usual Library - 細々としたライブラリ群
 * @version 0.1
 * @date 2024-08-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

inline bool YnPrint(bool flag, bool upper_case = false){printf("%s\n", flag ? (upper_case ? "YES" : "Yes") : (upper_case ? "NO" : "No")); return flag;}
template<typename Type>
bool chmin(Type &src, const Type &cmp){if(src > cmp){src = cmp; return true;} return false;}
template<typename Type>
bool chmax(Type &src, const Type &cmp){if(src < cmp){src = cmp; return true;} return false;}
template<typename Type>
inline bool between(const Type &min_value, const Type &cmp_value, const Type &max_value){return min_value <= cmp_value && cmp_value <= max_value;}
template<typename Type>
inline bool ingrid(const Type &y, const Type &x, const Type &y_max, const Type &x_max){return between(0, y, y_max) && between(0, x, x_max);}
template<typename Type>
inline Type except(const Type &src_value, const Type &condition_value, const Type &except_value){return (src_value == condition_value ? except_value : src_value);}
template<typename Type>
inline Type min(const vector<Type> &v){return *min_element(v.begin(), v.end());}
template<typename Type>
inline Type max(const vector<Type> &v){return *max_element(v.begin(), v.end());}
vector<int> sequence(int size, int start = 0){
    vector<int> ret(size);
    iota(ret.begin(), ret.end(), start);
    return ret;
}

template<typename Type>
inline Type get_inf(){
    return numeric_limits<Type>::max() >> 2;
}