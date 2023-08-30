#pragma once

/**
 * @file GraphTemplate.hpp
 * @author log K (lX57)
 * @brief Graph Template - グラフテンプレート
 * @version 2.0
 * @date 2023-08-31
 */

#include <bits/stdc++.h>
using namespace std;

using Vertex = int;
using EdgeID = int;

template<typename CostType>
struct Edge{
    Vertex from, to;
    CostType cost;

    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost){}

    Vertex getto(Vertex v){
        assert(v == from || v == to);
        return from ^ to ^ v;
    }
};

template<typename CostType>
struct Graph{
    private:
    int __CntVertex, __CntEdge;
    bool __isDirected;
    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;
    vector<vector<EdgeID>> __IncidentList;

    public:
    CostType INF;

    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max() / 2){}

    Graph() = default;

    void add(Vertex s, Vertex t, CostType w = 1){
        assert(0 <= s && s < __CntVertex);
        assert(0 <= t && t < __CntVertex);
        __EdgeSet.push_back(Edge<CostType>(s, t, w));
        __IncidentList[s].push_back(__CntEdge);
        __RevEdgeSet.push_back(Edge<CostType>(t, s, w));
        if(!__isDirected) __IncidentList[t].push_back(__CntEdge);
        ++__CntEdge;
    }

    vector<vector<CostType>> matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){
        vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));
        for(Vertex v = 0; v < __CntVertex; ++v){
            for(EdgeID &eid : __IncidentList[v]){
                ret[v][__EdgeSet[eid].getto(v)] = __EdgeSet[eid].cost;
            }
        }
        return ret;
    }

    void print_edgeset(bool OneIndex = true){
        for(int e = 0; e < __CntEdge; ++e){
            cout << e + OneIndex << " : (" << __EdgeSet[e].from + OneIndex << (__isDirected ? " -> " : " <-> ") << __EdgeSet[e].to + OneIndex << ") = " << __EdgeSet[e].cost << endl;
        }
    }

    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2, bool DisplayINF = true){
        auto mat = matrix(NotAdjacent);
        for(int i = 0; i < __CntVertex; ++i){
            cout << (DisplayINF && mat[i][j] == NotAdjacent ? "INF" : to_string(mat[i][0]));
            for(int j = 1; j < __CntVertex; ++j){
                cout << " " << (DisplayINF && mat[i][j] == NotAdjacent ? "INF" : to_string(mat[i][j]));
            }
            cout << endl;
        }
    }
};