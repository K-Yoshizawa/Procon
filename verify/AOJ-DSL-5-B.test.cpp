#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/CumulativeSum2D.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;

    CumulativeSum2D<int> cum(2000, 2000);
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cum.Add(y1, x1, y2 - 1, x2 - 1, 1);
    }
    cum.Build();
    cout << cum.Max() << '\n';
}