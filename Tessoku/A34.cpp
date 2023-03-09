#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    vector<int> Grundy(100010, 0);
    for(int i = 0; i <= 100000; ++i){
        set<int> st;
        if(i >= X) st.insert(Grundy[i - X]);
        if(i >= Y) st.insert(Grundy[i - Y]);
        int g = 0;
        while(st.find(g) != st.end()) ++g;
        Grundy[i] = g;
    }
    
    int nim = 0;
    for(int i = 0; i < N; ++i) nim ^= Grundy[A[i]];
    cout << (nim != 0 ? "First" : "Second") << endl;
}