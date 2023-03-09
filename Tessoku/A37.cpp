#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, M, B; cin >> N >> M >> B;
    vector<int> A(N), C(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> C[i];

    long long ans = B * N * M;
    for(int i = 0; i < N; ++i) ans += A[i] * M;
    for(int i = 0; i < M; ++i) ans += C[i] * N;
    
    cout << ans << endl;
}