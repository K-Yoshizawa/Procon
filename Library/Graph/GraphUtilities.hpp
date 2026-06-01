#pragma once

#include "Graph.hpp"

template<typename WeightType>
vector<Edge<WeightType>> ConvertEdgeSet(const Graph<WeightType> &G){
    vector<Edge<WeightType>> ret;
    vector<bool> check(G.EdgeSize(), false);
    int V = G.VertexSize();
    for(int u = 0; u < V; ++u){
        for(const Edge<WeightType> &e : G[u]){
            if(check[e.idx]) continue;
            check[e.idx] = true;
            ret.push_back(e);
        }
    }
    return ret;
}

template<typename WeightType>
vector<vector<WeightType>> ConvertDistanceMatrix(const Graph<WeightType> &G){
    int V = G.VertexSize();
    vector<vector<WeightType>> ret(V, vector<WeightType>(V, WeightType(INF)));
    for(int u = 0; u < V; ++u){
        ret[u][u] = WeightType(0);
        for(const Edge<WeightType> &e : G[u]){
            ret[u][e.to] = e.cost;
        }
    }
    return ret;
}

template<typename WeightType>
Graph<WeightType> ReverseGraph(const Graph<WeightType> &G){
    int V = G.VertexSize();
    Graph<WeightType> ret(V);
    for(int u = 0; u < V; ++u){
        for(const Edge<WeightType> &e : G[u]){
            ret.AddDirectedEdge(e.to, e.from, e.cost);
        }
    }
    return ret;
}