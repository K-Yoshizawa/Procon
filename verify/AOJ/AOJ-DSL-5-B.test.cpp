#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "../../library/DataStructure/CumulativeSum2D.hpp"

int main(){
    int N; cin >> N;
    CumulativeSum2D<int> cum(1001, 1001);
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cum.add(x1, y1, x2, y2, 1);
    }
    cum.build();
    cout << cum.max() << endl;
}
