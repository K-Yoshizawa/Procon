/**
 * @file SlideMin.hpp
 * @author log K (lX57)
 * @brief Slide-Min - スライド最小値
 * @version 1.0
 * @date 2023-10-30
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> SlideMin(vector<T> A, int K){
    int N = A.size();
    deque<int> Q;
    vector<T> B;
    for(int i = 0; i < N; ++i){
        while(Q.size() and A[Q.back()] >= A[i]) Q.pop_back();
        Q.push_back(i);
        if(Q.front() == i - K) Q.pop_front();
        if(i - K + 1 >= 0) B.push_back(A[Q.front()]);
    }
    return B;
}