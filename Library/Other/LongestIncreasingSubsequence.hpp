/**
 * @file LongestIncreasingSubsequence.hpp
 * @brief Longest Increasing Subsequence - 最長増加部分列
 * @author ei1333 (Original)
 * @version 2.0
 * @date 2024-10-29
 */

#include "../Common.hpp"

/**
 * @brief 配列 `data` の最長増加部分列を求める。
 * @tparam Strict 狭義単調増加であるか
 * @param data 求める配列
 * @return vector<T> 最長増加部分列の 1 つで、各要素を `data` における添え字で表した配列
 * @note 返り値の配列の長さが最長増加部分列の長さである。
 */
template<bool Strict, typename T>
vector<T> LongestIncreasingSubsequence(const vector<T> &data){
    int N = (int)data.size();
    T inf = numeric_limits<T>::min();
    vector<T> L, pre, S;
    for(auto &x : data){
        typename vector<T>::iterator itr;
        if(Strict) itr = lower_bound(L.begin(), L.end(), x);
        else itr = upper_bound(L.begin(), L.end(), x);
        if(itr == L.begin()) pre.emplace_back(inf);
        else pre.emplace_back(*prev(itr));
        if(itr == L.end()) L.emplace_back(x);
        else *itr = x;
    }
    T x = L.back();
    for(int i = N - 1; x != inf;){
        while(data[i] != x) --i;
        S.emplace_back(i);
        x = pre[i];
    }
    reverse(S.begin(), S.end());
    return S;
}