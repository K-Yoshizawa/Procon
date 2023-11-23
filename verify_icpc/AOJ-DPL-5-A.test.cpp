#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A"

#include "../icpc/ModInt.hpp"

int main(){
    int n, k;
    cin >> n >> k;

    cout << m107(k).pow(n) << endl;
}