#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SparseTable.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    SparseTable<int> st(a);

    while(Q--){
        int l, r; cin >> l >> r;
        cout << st.Fold(l, r) << '\n';
    }
}