#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include <bits/stdc++.h>

#include "../library/Math/PrimeFactorize.hpp"

int main(){
    long long n; cin >> n;
    auto ans = PrimeFactorize(n);
    cout << n << ":";
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].second; ++j){
            cout << " " << ans[i].first;
        }
    }
    cout << endl;
}