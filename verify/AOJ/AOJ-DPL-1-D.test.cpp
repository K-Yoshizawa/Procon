#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D"

#include <bits/stdc++.h>

#include "../../library/DynamicPrograming/LongestIncreasingSubsequence.hpp"

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &aa : a) cin >> aa;
    cout << LongestIncreasingSubsequence(a) << endl;
}