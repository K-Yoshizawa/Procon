#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
int TreeDiamiter(Graph<CostType> &G){
    vector<int> dist(G.vsize(), G.INF);
    dist[0] = 0;
    queue<Vertex> que; que.push(0);
    while(que.size()){
        Vertex now = que.front(); que.pop();
        int d = dist[now];
        for(auto e : G.get_incident(now)){
            if(dist[e.to] == G.INF){
                dist[e.to] = d + e.cost;
                que.push(e.to);
            }
        }
    }
    Vertex Farther = max_element(dist.begin(), dist.end()) - dist.begin();
    que.push(Farther);
    dist.assign(dist.size(), G.INF);
    dist[Farther] = 0;
    while(que.size()){
        Vertex now = que.front(); que.pop();
        int d = dist[now];
        for(auto e : G.get_incident(now)){
            if(dist[e.to] == G.INF){
                dist[e.to] = d + e.cost;
                que.push(e.to);
            }
        }
    }
    return *max_element(dist.begin(), dist.end());
}