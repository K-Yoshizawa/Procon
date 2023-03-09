#include <bits/stdc++.h>
using namespace std;

int main(void){
    int Q; cin >> Q;
    
    for(int i = 0; i < Q; ++i){
        int X; cin >> X;
        bool isprime = true;
        for(int j = 2; j * j <= X; ++j){
            isprime &= (X % j != 0);
        }
        cout << (isprime ? "Yes" : "No") << endl;
    }
}