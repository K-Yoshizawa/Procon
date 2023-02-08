#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long int;
const int mod = 1000000007;

int main(){
    ll a, b; cin >> a >> b;
    ll ans = 1, mul = a;
    for(int bit = 0; bit < 61; ++bit){
        if((1LL << bit) & b){
            ans = (ans * mul) % mod;
        }
        mul = (mul * mul) % mod;
    }
    cout << ans << endl;
}