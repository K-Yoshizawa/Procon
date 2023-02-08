#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
using ll = long long int;

ll power(ll a, ll b){ // a^b mod M
    ll ret = 1, mul = a;
    for(int i = 0; i < 63; ++i){
        if((1LL << i) & b) ret = (ret * mul) % M;
        mul = (mul * mul) % M;
    }
    return ret;
}

ll inverse(ll a){ // aの逆元
    return power(a, M - 2);
}

ll fact(ll n){ // n!
    ll ret = 1;
    for(int i = 2; i <= n; ++i){
        ret = (ret * i) % M;
    }
    return ret;
}

ll comb(ll n, ll r){
    ll ret = fact(n);
    ll div = (fact(r) * fact(n - r)) % M;
    return (ret * inverse(div)) % M;
}

int main(){
    int H, W; cin >> H >> W;
    cout << comb(H + W - 2, W - 1) << endl;
}