#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main(){
    int N; cin >> N;
    int an, an_ = 1, an__ = 1;
    if(N < 3){
        cout << 1 <<endl;
        return 0;
    }
    for(int i = 3; i <= N; ++i){
        an = an_ + an__;
        an %= mod;
        an__ = an_;
        an_ = an;
    }
    cout << an << endl;
}