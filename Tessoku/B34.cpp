#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long int;

int main(){
    int N, X, Y; cin >> N >> X >> Y;
    vector<ull> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    int Grundy[] = {0, 0, 1, 1, 2};

    int nim = 0;
    for(int i = 0; i < N; ++i) nim ^= Grundy[A[i] % 5];
    cout << (nim != 0 ? "First" : "Second") << endl;
}