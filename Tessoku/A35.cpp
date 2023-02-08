#include <bits/stdc++.h>
using namespace std;

#define Taro 1
#define Jiro 0

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    int turn = (N - 1) % 2;
    vector<vector<int>> P(N, vector<int>(N));
    for(int i = 0; i < N; ++i) P[N - 1][i] = A[i];

    for(int i = N - 2; i >= 0; --i){
        for(int j = 0; j <= i; ++j){
            if(turn == Taro) P[i][j] = max(P[i + 1][j], P[i + 1][j + 1]);
            if(turn == Jiro) P[i][j] = min(P[i + 1][j], P[i + 1][j + 1]);
        }
        turn = !turn;
    }
    cout << P[0][0] << endl;
}