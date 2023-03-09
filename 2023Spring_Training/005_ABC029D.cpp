#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/**
 *  Problem : ABC029D - 1
 *  Date    : 2023 / 02 / 08
 *  Solve   : Editorial
 */

int main(){
    string n; cin >> n;
    int N = stoi(n);

    ll ans = 0;
    for(int i = 10; i <= 1e9; i *= 10){
        ans += (i / 10) * ((N + 1) / i) + max(0, min((N + 1) % i - i / 10, i / 10));
    }    
    cout << ans << endl;
}