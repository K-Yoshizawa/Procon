#include "bits/stdc++.h"
using namespace std;

int main(){
    int W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<int> p(N), q(N);
    for(int i = 0; i < N; ++i) cin >> p[i] >> q[i];
    long long A;
    cin >> A;
    vector<int> a(A);
    for(int i = 0; i < A; ++i) cin >> a[i];
    long long B;
    cin >> B;
    vector<int> b(B);
    for(int i = 0; i < B; ++i) cin >> b[i];

    // lower_boundのために、aとbにWとHをそれぞれ追加しておく（こういうのを番兵などと言ったりします）
    a.push_back(W);
    b.push_back(H);
    map<pair<int, int>, int> cake; // pair型をキーに取る連想配列
    for(int i = 0; i < N; ++i){
        auto itr_x = lower_bound(a.begin(), a.end(), p[i]);
        auto itr_y = lower_bound(b.begin(), b.end(), q[i]);
        ++cake[{*itr_x, *itr_y}];
    }

    int M = 0, m = N + 1;
    // 範囲for文を用いるとmapの中身を簡単に取り出せます
    // [key, val]で連想配列のキーがkeyに、値がvalに入ります
    for(auto &[key, val] : cake){
        if(M < val) M = val;
        if(m > val) m = val;
    }
    // s < (A + 1)(B + 1)ならm = 0
    if(cake.size() < (A + 1) * (B + 1)) m = 0;
    cout << m << " " << M << endl;
}