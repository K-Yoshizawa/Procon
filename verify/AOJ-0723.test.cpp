#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0723"

#include "../Library/DataStructure/RollbackUnionFind.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;
    vector<int> U(M), V(M);
    for(int i = 0; i < M; ++i) cin >> U[i] >> V[i], --U[i], --V[i];
    vector<int> S(N);
    for(int i = 0; i < N; ++i) cin >> S[i], --S[i];

    RollbackUnionFind uf(N);
    map<pair<int, int>, vector<pair<int, int>>> Road;
    for(int i = 0; i < M; ++i){
        int u = U[i], v = V[i];
        int su = S[u], sv = S[v];
        if(su == sv) uf.Unite(u, v);
        else{
            if(su > sv) swap(su, sv);
            Road[{su, sv}].push_back({u, v});
        }
    }
    int Q; cin >> Q;
    map<pair<int, int>, vector<tuple<int, int, int>>> Query;
    vector<int> ans(Q, -1);
    for(int i = 0; i < Q; ++i){
        int A, B; cin >> A >> B, --A, --B;
        int sa = S[A], sb = S[B];
        if(sa == sb){
            ans[i] = uf.Same(A, B);
        }
        else{
            if(sa > sb) swap(sa, sb);
            Query[{sa, sb}].push_back({i, A, B});
        }
    }
    uf.Record();
    for(auto [state_pair, qs] : Query){
        for(auto [u, v] : Road[state_pair]){
            uf.Unite(u, v);
        }
        for(auto [i, a, b] : qs){
            ans[i] = uf.Same(a, b);
        }
        uf.Rollback();
    }
    for(auto a : ans){
        assert(a != -1);
        cout << a << '\n';
    }
}