#include <bits/stdc++.h>
using namespace std;

/**
 *  Problem : CF2016 qual_A C - Next Letter
 *  Date    : 2023 / 02 / 04
 *  Solve   : Myself
 */

int main(){
    string s;
    int K;
    cin >> s >> K;

    vector<int> need(s.size());
    for(int i = 0; i < s.size(); ++i){
        need[i] = 'a' - s[i] + 26;
    }

    string ans = s;
    int remain = K;
    for(int i = 0; i < s.size(); ++i){
        if(ans[i] == 'a') continue;
        if(remain >= need[i]){
            remain -= need[i];
            ans[i] = 'a';
        }
    }
    if(remain > 0){
        ans[s.size() - 1] = ((ans[s.size() - 1] - 'a' + remain) % 26) + 'a';
    }
    cout << ans << endl;
}