#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, H, W; cin >> N >> H >> W;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    int nim = 0;
    for(int i = 0; i < N; ++i){
        nim ^= (A[i] - 1);
        nim ^= (B[i] - 1);
    }
    cout << (nim != 0 ? "First" : "Second") << endl;
}