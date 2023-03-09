#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    int xorsum = 0;
    for(int i = 0; i < N; ++i) xorsum ^= A[i];

    cout << (xorsum == 0 ? "Second" : "First") << endl;
}