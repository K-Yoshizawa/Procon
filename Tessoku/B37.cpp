#include <bits/stdc++.h>
using namespace std;

long long fracsum(long long x, long long div){
    long long ret = 0;
    long long frac = div / 10; // 同じ数字が連続する数
    long long now = 0;
    while(x >= frac){
        ret += frac * now;
        ++now;
        x -= frac;
    }
    ret += x * now;

    return ret;
}

int main(){
    long long N; cin >> N;

    long long ans = 0LL;
    // 各桁ごとに考えていく
    for(long long div = 10, mul = 45; div < 1e16; div *= 10, mul *= 10){
        long long times = N / div;
        cerr << (div / 10) << "の位 : 周期 = " << (N / div) << " 端数 = " << (N % div) << endl;
        ans += mul * times;
        cerr << "    周期による和加算後 = " << ans << endl;
        ans += fracsum(N % div + 1, div);
        cerr << "    端数による和加算後 = " << ans << endl;
    }
    
    cout << ans << endl;
}