#include <bits/stdc++.h>
using namespace std;

/**
 *  Problem : ARC140B - Shorten ARC
 *  Date    : 2023 / 02 / 03
 *  Solve   : Editional
 */

int main(){
    int N;
    string S;
    cin >> N >> S;

    int M = 0, sum = 0;
    for(int i = 1; i < N - 1; ++i){
        if(S.substr(i - 1, 3) == "ARC"){
            int l = i - 1, r = i + 1;
            while(l > 0 && S[l - 1] == 'A') --l;
            while(r < N - 1 && S[r + 1] == 'C') ++r;
            int x = min(i - l, r - i);
            sum += x;
            ++M;
        }
    }
    cout << min(2 * M, sum) << endl;
}