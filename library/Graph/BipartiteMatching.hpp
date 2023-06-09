#pragma once

/**
 * @brief Bipartite Matching - 二部マッチング
 */

#include <bits/stdc++.h>

#include "FordFulkerson.hpp"

using namespace std;

struct BipartiteMatching{
    private:
    Graph<int> G;
    int X, Y, s, t;

    public:
    BipartiteMatching(int X, int Y) : X(X), Y(Y), s(X + Y), t(X + Y + 1){
        G = Graph<int>(X + Y + 2, true);
        for(Vertex x = 0; x < X; ++x) G.add(s, x);
        for(Vertex y = X; y < X + Y; ++y) G.add(y, t);
    }

    void add(int x, int y){
        G.add(x, X + y);
    }

    int solve(){
        FordFulkerson<int> ff(G);
        return ff.query(s, t);
    }
};