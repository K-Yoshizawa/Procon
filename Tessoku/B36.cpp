#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int cnt = 0;
    for(int i = 0; i < N; ++i) cnt += (S[i] == '1');

    if(abs(cnt - K) % 2) cout << "No" << endl;
    else cout << "Yes" << endl;
}