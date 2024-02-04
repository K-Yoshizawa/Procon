#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../library/DataStructure/MergeSortTree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<tuple<long long, long long, long long>> p(N);
    for(int i = 0; i < N; ++i){
        long long x, y, w; cin >> x >> y >> w;
        p[i] = {x, y, w};
    }
    sort(p.begin(), p.end());
    vector<long long> x, y, w;
    transform(p.begin(), p.end(), back_inserter(x), [](auto t){return get<0>(t);});
    transform(p.begin(), p.end(), back_inserter(y), [](auto t){return get<1>(t);});
    transform(p.begin(), p.end(), back_inserter(w), [](auto t){return get<2>(t);});
    vector<long long> l(Q), d(Q), r(Q), u(Q);
    for(int i = 0; i < Q; ++i) cin >> l[i] >> d[i] >> r[i] >> u[i];

    MergeSortTree<long long> mst(y, w);
    for(int i = 0; i < Q; ++i){
        int left = lower_bound(x.begin(), x.end(), l[i]) - x.begin() + 1;
        int right = lower_bound(x.begin(), x.end(), r[i]) - x.begin() + 1;
        cout << mst.rect_query(left, right, d[i], u[i]) << endl;
    }
}