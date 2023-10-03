#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "../latest/DataStructure/CumulativeSum2D.hpp"

int main(){
    int N; cin >> N;
    CumulativeSum2D<int> cum(1010, 1010);
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cum.add(y1, x1, y2, x2);
    }
    cum.build();
    cout << cum.max() << endl;
}