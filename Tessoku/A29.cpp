#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main(){
    int a, b; cin >> a >> b;
    long long int ans = 1, mul = a;
    for(int bit = 0; bit < 31; ++bit){
        if((1 << bit) & b){
            ans = (ans * mul) % mod;
        }
        mul = (mul * mul) % mod;
    }
    cout << ans << endl;
}