#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../library/modint.hpp"
#include "../library/Math/Matrix.hpp"

int main(){
    int N, M, K; cin >> N >> M >> K;
    vvm998 a(N, vm998(M)), b(M, vm998(K));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < K; ++j){
            cin >> b[i][j];
        }
    }

    Matrix<modint998> A(a), B(b), C;
    C = A * B;
    cout << C << endl;
}