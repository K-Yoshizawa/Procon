#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D"

#include "../library/DataStructure/SlideMin.hpp"

int main(){
    int N, L; cin >> N >> L;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    vector<int> b = SlideMin(a, L);
    
    cout << b[0];
    for(int i = 1; i < b.size(); ++i) cout << " " << b[i];
    cout << endl;
}