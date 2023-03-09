#include <bits/stdc++.h>
using namespace std;

using unweighted_graph = vector<vector<int>>;

int main(){
    int N, M; cin >> N >> M;
    unweighted_graph g(N);
    for(int i = 0; i < M; ++i){
        int A, B; cin >> A >> B;
        g[A - 1].push_back(B);
        g[B - 1].push_back(A);
    }

    for(int i = 0; i < N; ++i){
        cout << i + 1 << ": {";
        for(int j = 0; j < g[i].size(); ++j){
            if(j != 0) cout << ", ";
            cout << g[i][j];
        }
        cout << "}" << endl;
    }
}