#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

#include "../../Library/Math/Combinatorics.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k;
    cout << Combinatorics<mmint>().Homogeneous(k, n) << endl;
}