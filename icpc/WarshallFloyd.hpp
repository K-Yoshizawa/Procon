#include "Template.hpp"

ll INF = (1LL << 31) - 1;

bool warshallfloyd(vvl &g){
    int v = g.size();
    for(int i = 0; i < v; ++i) g[i][i] = 0;
    for(int k = 0; k < v; ++k){
        for(int i = 0; i < v; ++i){
            for(int j = 0; j < v; ++j){
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    bool f = false;
    for(int i = 0; i < v; ++i) f |= g[i][i] < 0;
    return f;
}