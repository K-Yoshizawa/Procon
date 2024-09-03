#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "library/Other/Compress.hpp"
#include "library/Other/Mo.hpp"

using ll = long long;

int main(){
    int N, Q; cin >> N >> Q;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    vector<int> l(Q), r(Q);
    vector<ll> x(Q);
    for(int i = 0; i < Q; ++i) cin >> l[i] >> r[i] >> x[i];

    Compress<ll> cp(a);
    for(int i = 0; i < Q; ++i) cp.add(x[i]);
    cp.build();
    for(int i = 0; i < N; ++i) a[i] = cp[a[i]];

    vector<int> cnt(cp.size(), 0);
    Mo mo(N, l, r);
    vector<int> ans(Q);
    auto add = [&](int i){
        ++cnt[a[i]];
    };
    auto sub = [&](int i){
        --cnt[a[i]];
    };
    auto out = [&](int i){
        ans[i] = cnt[cp[x[i]]];
    };
    mo.run(add, sub, out);

    for(auto a : ans) cout << a << endl;
}