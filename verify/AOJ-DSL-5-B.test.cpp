#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "../library/DataStructure/CumulativeSum2D.hpp"

int main(){
    int N; cin >> N;
    vector<vector<int>> Init(1010, vector<int>(1010, 0));

    CumulativeSum2D<int> cum(Init);
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2, --x2, --y2;
        cum.add(y1, x1, y2, x2, 1);
    }
    cum.build();
    cout << cum.search([](int s, int t){return max(s, t);}) << endl;
}