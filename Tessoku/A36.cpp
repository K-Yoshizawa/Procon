#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K; cin >> N >> K;

    if(K < (N - 1) * 2) cout << "No" << endl;
    else if((K - (N - 1) * 2) % 2) cout << "No" << endl;
    else cout << "Yes" << endl;
}