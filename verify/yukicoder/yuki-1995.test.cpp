#define IGNORE
// #define PROBLEM "https://yukicoder.me/problems/no/1995"

#include "../../library/Template.hpp"

<<<<<<< HEAD:verify/yukicoder/yuki-1995.test.cpp
#include "../../library/Compress.hpp"
#include "../../library/Graph/GraphTemplate.hpp"
#include "../../library/Graph/Dijkstra.hpp"
=======
#include "../library/Other/Compress.hpp"
#include "../library/Graph/GraphTemplate.hpp"
#include "../library/Graph/Dijkstra.hpp"
>>>>>>> be2aefab603660a7d7bca2e7379c1a3e8c9840a3:verify/yuki-1995.test.cpp

int main(){
    int N, M;
    cin >> N >> M;
    vector<long long> A(M), B(M);
    vector<int> city{1, N};
    for(int i = 0; i < M; ++i){
        cin >> A[i] >> B[i];
        city.emplace_back(A[i]);
        city.emplace_back(B[i]);
    }
    Compress cp(city);
    Graph<long long> G(cp.sz);
    for(int i = 0; i < cp.sz - 1; ++i){
        G.add(i, i + 1, (cp.iv(i + 1) - cp.iv(i)) * 2LL);
    }
    for(int i = 0; i < M; ++i){
        G.add(cp.vi(A[i]), cp.vi(B[i]), 2 * B[i] - 2 * A[i] - 1);
    }
    Dijkstra dk(G);
    dk.build(0);
    cout << dk.dist[cp.sz - 1] << endl;
}
