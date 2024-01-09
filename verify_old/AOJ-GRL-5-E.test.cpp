#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../old/Tree/HeavyLightDecomposition.hpp"
#include "../old/DataStructure/LazySegmentTree.hpp"

struct Data{
    long long val{0};
    long long len{1};

    Data() : val(0), len(1){}
    Data(int val, int len) : val(val), len(len){}

    bool operator==(const Data& y){
        return val == y.val && len == y.len;
    }

    static Data Merge(const Data& x, const Data& y){
        Data ret;
        ret.val = x.val + y.val;
        ret.len = x.len + y.len;
        return ret;
    }

    static Data Mapping(const Data& x, const long long y){
        Data ret;
        ret.val = x.val + y * x.len;
        ret.len = x.len;
        return ret;
    }
};

int main(){
    int n; cin >> n;
    Graph<long long> G(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G.add(i, c);
        }
    }

    HeavyLightDecomposition<long long> HLD(G);
    auto vdic = HLD.get_vertex_locations();
    vector<Data> Init_Data(n, Data());
    LazySegmentTree<Data, long long> seg(Init_Data,
        [](const Data l, const Data r){return Data::Merge(l, r);},
        [](const Data l, const long long r){return Data::Mapping(l, r);},
        [](const long long l, const long long r){return l + r;},
        Data(), 0, true
    );

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int v, w; cin >> v >> w;
            auto ret = HLD.path_query(0, v);
            for(auto [l, r] : ret){
                seg.update(l, r, w);
            }
            seg.update(0, 1, -w);
        }
        else{
            int u; cin >> u;
            auto ret = HLD.path_query(0, u);
            long long ans = 0LL;
            for(auto [l, r] : ret){
                ans += seg.query(l, r).val;
            }
            cout << ans << endl;
        }
    }
}