

#include <bits/stdc++.h>
using namespace std;

vector<int> Manacher(string S, bool NeedEven = true, char Dummy = '$'){
    string T = S;
    if(NeedEven){
        T = S[0];
        for(int i = 1; i < S.size(); ++i){
            T.push_back(Dummy);
            T.push_back(S[i]);
        }
    }
    vector<int> ret(T.size(), 0);
    int i = 0, j = 0;
    while(i < T.size()){
        while(i - j >= 0 && i + j < T.size() && T[i - j] == T[i + j]) ++j;
        ret[i] = j;
        int k = 1;
        while(i - k >= 0 && k + ret[i - k] < j){
            ret[i + k] = ret[i - k], ++k;
        }
        i += k;
        j -= k;
    }
    if(NeedEven){
        for(int i = 0; i < T.size(); ++i){
            if(i % 2) ret[i] = ret[i] / 2 * 2;
            else ret[i] = (ret[i] + 1) / 2 * 2 - 1;
        }
    }
    else{
        for(int i = 0; i < T.size(); ++i){
            ret[i] = ret[i] * 2 - 1;
        }
    }
    return ret;
}