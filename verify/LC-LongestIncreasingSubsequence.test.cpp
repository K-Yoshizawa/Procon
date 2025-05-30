#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../Library/Template.hpp"
#include "../Library/Other/LongestIncreasingSubsequence.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A(N); cin >> A;

    auto ans = LongestIncreasingSubsequence<true>(A);
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i << " ";
    }
    cout << '\n';
}