

#include <bits/stdc++.h>
using namespace std;

vector<int> Z_Algorithm(string S){
    vector<int> Z(S.size(), 0);
    Z[0] = S.size();
    int i = 1, j = 0;
    while(i < S.size()){
        while(i + j < S.size() && S[j] == S[i + j]) ++j;
        Z[i] = j;
        if(j == 0){
            ++i;
            continue;
        }
        int k = 1;
        while(k < j && k + Z[k] < j){
            Z[i + k] = Z[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return Z;
}