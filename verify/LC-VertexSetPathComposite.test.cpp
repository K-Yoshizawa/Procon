#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../Library/Template.hpp"
#include "../Library/Tree/HeavyLightDecomposition.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"
#include "../Library/modint.hpp"

struct Affine{
    Affine() = default;
    Affine(mint a, mint b) : a(a), b(b){}
    mint a{1}, b{0};
    static Affine left_merge(Affine l, Affine r){
        return Affine(r.a * l.a, r.a * l.b + r.b);
    }
    static Affine right_merge(Affine l, Affine r){
        return Affine(l.a * r.a, l.a * r.b + l.b);
    }
    friend ostream &operator<<(ostream &os, const Affine &p) {
        return os << "{" << p.a << ", " << p.b << "}";
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<Affine> init_data;
    for(int i = 0; i < N; ++i){
        mint a, b; cin >> a >> b;
        init_data.push_back(Affine(a, b));
    }
    auto T = InputTree(N, 0);

    HeavyLightDecomposition hld(T);
    hld.SortVertex(init_data);
    SegmentTree<Affine> seg1(init_data, [](Affine l, Affine r){return Affine::left_merge(l, r);}, Affine(), true);
    SegmentTree<Affine> seg2(init_data, [](Affine l, Affine r){return Affine::right_merge(l, r);}, Affine(), true);
    while(Q--){
        int t; cin >> t;
        if(t == 0){
            int p, c, d; cin >> p >> c >> d;
            seg1.Update(hld[p], Affine(c, d));
            seg2.Update(hld[p], Affine(c, d));
        }
        else{
            int u, v, x; cin >> u >> v >> x;
            Affine ans;
            for(auto &path : hld.PathQuery(u, v)){
                if(path.reverse) ans = Affine::left_merge(ans, seg2.Query(path.head_index, path.tail_index));
                else ans = Affine::left_merge(ans, seg1.Query(path.head_index, path.tail_index));
            }
            cout << ans.a * x + ans.b << endl;
        }
    }
}