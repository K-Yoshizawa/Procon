#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ll A, B; cin >> A >> B;
    cout << A / gcd(A, B) * B << endl;
}