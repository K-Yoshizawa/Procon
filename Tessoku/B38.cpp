#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> Grass(N, 1);
    int lowest = 1, index = 0;
    string S; cin >> S;

    for(int i = 0; i < N - 1; ++i){
        if(S[i] == 'A') Grass[i + 1] = Grass[i] + 1;
        else{
            Grass[i + 1] = Grass[i] - 1;
            if(lowest > Grass[i + 1]){
                lowest = Grass[i + 1];
                index = i + 1;
            }
        }
    }
    for(int i = 0; i < N; ++i) Grass[i] += (1 - lowest);
}