#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

#include "../icpc/ModInt.hpp"
#include "../icpc/Combination.hpp"

int main(){
    int n, k;
    cin >> n >> k;

    combination<m107> comb(2010);
    cout << comb.H(k, n) << endl;
}