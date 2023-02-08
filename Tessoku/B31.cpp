#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    cout << (N / 3 + N / 5 + N / 7 - N / 15 - N / 21 - N / 35 + N / 105) << endl;
}