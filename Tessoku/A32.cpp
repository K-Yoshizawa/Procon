#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B; cin >> N >> A >> B;

    vector<bool> iswin(N * 2); // 残りの石がi個のときに手番が回ってきたら勝てるか
    for(int i = 0; i < A; ++i) iswin[i] = false;

    for(int i = A; i <= N; ++i){
        bool able = !iswin[i - A]; // 負けの状態に遷移できるか
        if(i >= B) able |= !iswin[i - B];
        iswin[i] = able;
    }
    cout << (iswin[N] ? "First" : "Second") << endl;
}