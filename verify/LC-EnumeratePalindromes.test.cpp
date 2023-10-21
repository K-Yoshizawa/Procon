#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../library/String/Manacher.hpp"

int main(){
    string S; cin >> S;
    auto ans = Manacher(S);
    for(auto a : ans){
        cout << a << " ";
    }
}