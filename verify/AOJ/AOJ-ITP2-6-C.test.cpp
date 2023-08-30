#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_6_C"

#include "../../library/Template.hpp"

int main(){
    int n; cin >> n;
    vi a(n); cin >> a;
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        cout << LOWERBOUND_IDX(a, k) << endl;
    }
}