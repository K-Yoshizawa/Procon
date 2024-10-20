#pragma once

/**
 * @brief Longest Increasing Subsequence - 最長部分増加列
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 配列Xに対して最長部分増加列の長さを求める。
 * @param X 求めたい配列X
 * @param strict 狭義単調増加か広義単調増加か（default = true）
 * @return int 最長部分増加列の長さ
 */
template<typename T>
int LongestIncreasingSubsequence(const vector<T> &X, bool strict = true){
    int N = X.size();
    vector<int> L;
    for(auto &x : X){
        vector<int>::iterator itr;
        if(strict) itr = lower_bound(L.begin(), L.end(), x);
        else itr = upper_bound(L.begin(), L.end(), x);
        if(itr == L.end()) L.emplace_back(x);
        else *itr = x;
    }
    return L.size();
}