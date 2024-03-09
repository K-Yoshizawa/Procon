#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../library/String/RollingHash.hpp"

int main(){
    string T, P; cin >> T >> P;

    RollingHash::generate_base();
    RollingHash RHT(T), RHP(P);
    for(int i = 0; i < (int)T.size() - (int)P.size() + 1; ++i){
        if(RHT.substr(i + 1, i + P.size()) == RHP){
            cout << i << endl;
        }
    }
}