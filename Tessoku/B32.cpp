#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K; cin >> N >> K;
    vector<int> a(K);
    for(int i = 0; i < K; ++i) cin >> a[i];

    vector<bool> iswin(N + 10, false); // 残りの石がi個のときに手番が回ってきたら勝てるか
    for(int i = 0; i <= N; ++i){
        bool able = false;
        for(int j = 0; j < K; ++j){
            if(i < a[j]) continue;
            able |= !iswin[i - a[j]];
        }
        iswin[i] = able;
    }

    cout << (iswin[N] ? "First" : "Second") << endl;
}