#define PROBLEM "https://yukicoder.me/problems/no/649"

#include <bits/stdc++.h>
#include "../library/DataStructure/K-th_MultiSet.hpp"

int main(){
    int Q, K;
    cin >> Q >> K;

    Kth_MultiSet<long long> ms(K);
    while(Q--){
        int query;
        cin >> query;
        if(query == 1){
            long long v;
            cin >> v;
            ms.insert(v);
        }
        else{
            cout << (ms.exist() ? ms.get() : -1) << endl;
            if(ms.exist()) ms.erase(ms.get());
        }
    }
}