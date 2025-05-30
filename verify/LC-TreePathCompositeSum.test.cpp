#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../Library/Template.hpp"
#include "../Library/modint.hpp"
#include "../Library/Tree/RerootingDP.hpp"

struct Affine{
    Affine() = default;
    Affine(mint b, mint c) : b(b), c(c){}
    mint b{1}, c{0};
    friend ostream &operator<<(ostream &os, const Affine &p) {
        return os << "{" << p.b << ", " << p.c << "}";
    }
};

struct Monoid{
    Monoid() = default;
    Monoid(mint v, mint c) : val(v), cnt(c){}
    mint val{0}, cnt{0};
    friend ostream &operator<<(ostream &os, const Monoid &p) {
        return os << "{" << p.val << ", " << p.cnt << "}";
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    RootedTree<Affine> T(N);
    vm a(N); cin >> a;
    {
        vector<vector<pair<Vertex, Affine>>> graph(N);
        for(int i = 0; i < N - 1; ++i){
            int u, v; cin >> u >> v;
            mint b, c; cin >> b >> c;
            graph[u].emplace_back(v, Affine(b, c));
            graph[v].emplace_back(u, Affine(b, c));
        }
        auto rec = [&](auto self, Vertex v, Vertex p) -> void {
            for(auto [u, w] : graph[v]){
                if(u == p) continue;
                T.AddEdge(v, u, w);
                self(self, u, v);
            }
        };
        rec(rec, 0, -1);
    }

    RerootingDP<Affine, Monoid> dp(
        T,
        [](Monoid l, Monoid r, Vertex i){
            return Monoid(l.val + r.val, l.cnt + r.cnt);
        },
        [&](Monoid x, Affine m, Vertex i){
            return Monoid(m.b * (a[i] + x.val) + (x.cnt + 1) * m.c, x.cnt + 1);
        },
        [&](Monoid x, Vertex i){
            return Monoid(x.val + a[i], x.cnt + 1);
        },
        Monoid()
    );
    for(int i = 0; i < N; ++i){
        cout << dp[i].val << " ";
    }
}