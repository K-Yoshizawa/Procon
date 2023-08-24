#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/4/DSL_4_A"

#include "../library/Other/Compress.hpp"
#include "../library/DataStructure/CumulativeSum2D.hpp"

int main(){
    int N; cin >> N;
    vector<int> X, Y;
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        X.push_back(x1), X.push_back(x2);
        Y.push_back(y1), Y.push_back(y2);
    }

    Compress<int> cpx(X), cpy(Y);
    CumulativeSum2D<int> cum(2 * N, 2 * N);
    for(int i = 0; i < N; ++i){
        cum.add(cpx.vi(X[i * 2]), cpy.vi(Y[i * 2]), cpx.vi(X[i * 2 + 1]), cpy.vi(Y[i * 2 + 1]), 1);
    }
    cum.build();
    long long ans = 0;
    for(int i = 0; i < 2 * N; ++i){
        for(int j = 0; j < 2 * N; ++j){
            if(cum.test(i, j, [](auto x){return x > 0;})){
                ans += ((long long)cpy.iv(i + 1) - cpy.iv(i)) * (cpx.iv(j + 1) - cpx.iv(j));
            }
        }
    }
    cout << ans << endl;
}