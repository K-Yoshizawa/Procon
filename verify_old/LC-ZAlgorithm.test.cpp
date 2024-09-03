#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../library/String/ZAlgorithm.hpp"

int main(){
    string S; cin >> S;
    auto Z = Z_Algorithm(S);
    for(auto z : Z){
        cout << z << " ";
    }
}