#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../Library/Template.hpp"
#include "../Library/Other/LongestIncreasingSubsequence.hpp"

int main(){
    int N; cin >> N;
    vector<int> A(N); cin >> A;

    auto ans = LongestIncreasingSubsequence<true>(A);
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
}