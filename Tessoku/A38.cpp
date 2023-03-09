#include <bits/stdc++.h>
using namespace std;

int main(){
    int D, N; cin >> D >> N;
    vector<int> lim(D, 24);
    for(int i = 0; i < N; ++i){
        int L, R, H; cin >> L >> R >> H;
        --L, --R;
        for(int j = L; j <= R; ++j){
            lim[j] = min(lim[j], H);
        }
    }
    cout << accumulate(lim.begin(), lim.end(), 0) << endl;
}