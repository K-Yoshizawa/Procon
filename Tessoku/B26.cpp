#include <bits/stdc++.h>
using namespace std;

bool isprime[1000010];

int main(void){
    int N; cin >> N;

    for(int i = 2; i <= N; ++i){
        isprime[i] = true;
    }
    for(int i = 2; i <= N; ++i){
        if(!isprime[i]) continue;
        for(int j = i * 2; j <= N; j += i) isprime[j] = false;
    }
    for(int i = 2; i <= N; ++i){
        if(isprime[i]) cout << i << endl;
    }
}