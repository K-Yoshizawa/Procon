#include <bits/stdc++.h>
using namespace std;

/**
 *  Problem : ABC102C - Linear Approximation
 *  Date    : 2023 / 02 / 04
 *  Solve   : Myself
 */

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    vector<int> min_b(N);
    for(int i = 0; i < N; ++i) min_b[i] = A[i] - (i + 1);
    sort(min_b.begin(), min_b.end());
    
    int b = min_b[N / 2];
    long long ans = 0;
    for(int i = 0; i < N; ++i){
        ans += abs(A[i] - (b + i + 1));
    }
    cout << ans << endl;
}