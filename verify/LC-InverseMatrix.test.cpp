#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../library/modint.hpp"
#include "../library/Math/Matrix.hpp"

int main(){
    int N; cin >> N;
    vvm998 a(N, vm998(N));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> a[i][j];
        }
    }

    Matrix<modint998> A(a);
    if(A.isRegular()){
        auto B = Matrix<modint998>::inv(A);
        cout << B << endl;
    }
    else{
        cout << -1 << endl;
    }
}