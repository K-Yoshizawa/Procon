#pragma once

/**
 * @file GraphTemplate.hpp
 * @author log K (lX57)
 * @brief Graph Template - グラフテンプレート
 * @version 2.2
 * @date 2023-10-02
 */

#include <bits/stdc++.h>
using namespace std;

using Vertex = int;
using EdgeID = int;
using EdgeIndex = int;

template<typename CostType>
struct Edge{
    EdgeID ID{-1};
    Vertex src, to;
    CostType cost, cap;
    EdgeIndex sidx, tidx;

    Edge() = default;
    Edge(EdgeID ID, Vertex src, Vertex to, CostType cost, CostType cap, EdgeIndex sidx, EdgeIndex tidx) :
        ID(ID), src(src), to(to), cost(cost), cap(cap), sidx(sidx), tidx(tidx){}

    void print(){
        cerr << "Edge " << ID << " : (" << src << " -> " << to << "), Cost = " << cost << ", Capacity = " << cap << ", Place = [" << sidx << ", " << tidx << "]" << endl;
    }
};

template<typename CostType>
using EdgeSet = vector<Edge<CostType>>;
template<typename CostType>
using IncidentList = vector<vector<Edge<CostType>>>;
using AdjacentList = vector<vector<Vertex>>;

template<typename CostType>
struct Graph{
    protected:
    int __CntVertex, __CntEdge;
    bool __isDirected;
    EdgeSet<CostType> __ES, __RES;
    IncidentList<CostType> __IL;
    AdjacentList __AL;

    public:
    CostType INF;

    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IL(VertexSize), __AL(VertexSize), INF(numeric_limits<CostType>::max() / 2){}

    Graph() = default;

    void add(Vertex Source, Vertex To, CostType Cost = 1){
        assert(0 <= Source && Source < __CntVertex);
        assert(0 <= To && To < __CntVertex);
        EdgeIndex sidx = __IL[Source].size(), tidx = __IL[To].size();
        Edge<CostType> es{__CntEdge, Source, To, Cost, 1, sidx, tidx};
        Edge<CostType> et{__CntEdge, To, Source, Cost, 1, tidx, sidx};
        __ES.push_back(es);
        __RES.push_back(et);
        __IL[Source].push_back(es), __AL[Source].push_back(To);
        if(!__isDirected) __IL[To].push_back(et), __AL[To].push_back(Source);
        ++__CntEdge;
    }

    vector<vector<CostType>> matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){
        vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));
        for(Vertex v = 0; v < __CntVertex; ++v){
            ret[v][v] = 0;
            for(auto e : __IL[v]){
                ret[v][e.to] = e.cost;
            }
        }
        return ret;
    }

    inline int vsize(){
        return __CntVertex;
    }

    inline int esize(){
        return __CntEdge;
    }

    inline int incsize(Vertex v){
        return __IL[v].size();
    }

    inline EdgeSet<CostType> get_edgeset(){
        return __ES;
    }

    inline IncidentList<CostType> get_incidentlist(){
        return __IL;
    }

    inline vector<Edge<CostType>> get_incident(Vertex v){
        assert(0 <= v && v < __CntVertex);
        return __IL[v];
    }

    inline AdjacentList get_adjacentlist(){
        return __AL;
    }

    inline vector<Vertex> get_adjacent(Vertex v){
        assert(0 <= v && v < __CntVertex);
        return __AL[v];
    }

    vector<Edge<CostType>> operator[](Vertex v){
        return get_incident(v);
    }

    void print_edgeset(bool OneIndex = true){
        for(int e = 0; e < __CntEdge; ++e){
            cout << e + OneIndex << " : (" << __ES[e].from + OneIndex << (__isDirected ? " -> " : " <-> ") << __ES[e].to + OneIndex << ") = " << __ES[e].cost << " (" << __ES[e].cap << ")" << endl;
        }
    }

    void print_incidentlist(bool OneIndex = true){
        for(int i = 0; i < __CntVertex; ++i){
            cout << i + OneIndex << " :";
            for(int j = 0; j < __IL[i].size(); ++j){
                cout << " (" << __IL[i][j].to << " / " << __IL[i][j].cost << ", " << __IL[i][j].cap << ")";
            }
            cout << endl;
        }
    }

    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2, bool DisplayINF = true){
        auto mat = matrix(NotAdjacent);
        for(int i = 0; i < __CntVertex; ++i){
            cout << (DisplayINF && mat[i][0] == NotAdjacent ? "INF" : to_string(mat[i][0]));
            for(int j = 1; j < __CntVertex; ++j){
                cout << " " << (DisplayINF && mat[i][j] == NotAdjacent ? "INF" : to_string(mat[i][j]));
            }
            cout << endl;
        }
    }
};