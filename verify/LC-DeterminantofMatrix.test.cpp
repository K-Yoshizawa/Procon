#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../library/modint.hpp"
#include "../library/Math/Matrix.hpp"

int main(){
    int N; cin >> N;
    vvm998 a(N, vm998(N));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> a[i][j];
    
    Matrix<modint998> A(a);
    cout << A.det() << endl;
}