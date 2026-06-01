#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../Library/Template.hpp"
#include "../Library/Math/MillerRabin.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int Q; cin >> Q;
    while(Q--){
        long long N; cin >> N;
        YnPrint(MillerRabin(N));
    }
}