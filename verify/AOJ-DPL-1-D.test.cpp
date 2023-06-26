#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D"

#include "../library/Template.hpp"

#include "../library/DynamicPrograming/LongestIncreasingSubsequence.hpp"

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cout << LongestIncreasingSubsequence(a) << endl;
}