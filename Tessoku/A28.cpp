#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int now = 0;
    for(int i = 0; i < N; ++i){
        char T; int A; cin >> T >> A;
        switch(T){
            case '+': now += A; break;
            case '-': now -= A; break;
            case '*': now *= A; break;
        }
        now += 10000;
        now %= 10000;
        cout << now << endl;
    }
}