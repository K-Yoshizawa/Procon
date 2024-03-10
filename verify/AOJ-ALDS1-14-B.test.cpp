#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../library/String/RollingHash.hpp"

int main(){
    string T, P; cin >> T >> P;

    RollingHash::generate_base();
    RollingHash rh;
    HashTable ht_T = rh.build(T);
    Hash hash_P = rh.build(P).back();
    for(int i = 0; i < (int)T.size() - (int)P.size() + 1; ++i){
        if(rh.substr(ht_T, i + 1, i + P.size()) == hash_P){
            cout << i << endl;
        }
    }
}