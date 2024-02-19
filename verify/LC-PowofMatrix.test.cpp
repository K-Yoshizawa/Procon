#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../library/modint.hpp"
#include "../library/Math/Matrix.hpp"

int main(){
    int N; cin >> N;
    long long K; cin >> K;
    Matrix<modint998> a(N); cin >> a;

    auto b = a ^ K;
    cout << b << endl;
}