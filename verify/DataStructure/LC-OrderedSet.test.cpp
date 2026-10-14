#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../../Library/DataStructure/RedBlackTree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    RedBlackTree<int> st(N + Q + 1);
    for(int i = 0; i < N; ++i){
        int a; cin >> a;
        st.Insert(a);
    }
    while(Q--){
        int t, x; cin >> t >> x;
        int ans;
        switch(t){
            case 0 : st.Insert(x); break;
            case 1 : st.Erase(x); break;
            case 2 : cout << st.KthElement(x, -1) << '\n'; break;
            case 3 : cout << st.CountLessEqual(x) << '\n'; break;
            case 4 : 
                ans = st.MaximumLessEqual(x);
                cout << (ans == numeric_limits<int>::min() ? -1 : ans) << '\n'; break;
            case 5 : 
                ans = st.MinimumGreaterEqual(x);
                cout << (ans == numeric_limits<int>::max() ? -1 : ans) << '\n'; break;
        }
    }
}