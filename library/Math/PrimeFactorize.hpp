#pragma once

/**
 * @brief Prime Factorize - 素因数分解
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 整数xを素因数分解し、その結果を返す
 * @param x 素因数分解する整数
 * @return vector<pair<long long, int>> 素因数と含まれる個数の一覧
 */
vector<pair<long long, int>> PrimeFactorize(long long x){
    if(x < 0) x = -x;
    long long y = x;
    vector<pair<long long, int>> ret;
    for(long long div = 2; div * div <= x; ++div){
        int cnt = 0;
        while(y % div == 0) ++cnt, y /= div;
        if(cnt != 0) ret.push_back({div, cnt});
    }
    if(y != 1) ret.push_back({y, 1});
    return ret;
}