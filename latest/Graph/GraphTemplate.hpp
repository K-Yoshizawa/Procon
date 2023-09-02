#pragma once

/**
 * @file GraphTemplate.hpp
 * @author log K (lX57)
 * @brief Graph Template - グラフテンプレート
 * @version 2.1
 * @date 2023-08-31
 */

#include <bits/stdc++.h>
using namespace std;

using Vertex = int;
using EdgeID = int;

template<typename CostType>
struct Edge{
    Vertex from, to;
    CostType cost, cap;

    Edge(Vertex from, Vertex to, CostType cost) : from(from), to(to), cost(cost), cap(1){}
    Edge(Vertex from, Vertex to, CostType cap, CostType cost) : from(from), to(to), cost(cost), cap(cap){}

    Vertex getto(Vertex v){
        assert(v == from || v == to);
        return from ^ to ^ v;
    }

    void swap(){
        Vertex tmp = from;
        from = to;
        to = tmp;
    }
};

template<typename CostType>
struct Graph{
    private:
    int __CntVertex, __CntEdge;
    bool __isDirected;
    vector<Edge<CostType>> __EdgeSet, __RevEdgeSet;
    vector<vector<pair<EdgeID, bool>>> __IncidentList;
    vector<pair<int, int>> __EdgePlace;

    public:
    CostType INF;

    Graph(int VertexSize, bool isDirected = false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0), __IncidentList(VertexSize), INF(numeric_limits<CostType>::max() / 2){}

    Graph() = default;

    void add(Vertex s, Vertex t, CostType w = 1){
        assert(0 <= s && s < __CntVertex);
        assert(0 <= t && t < __CntVertex);
        __EdgePlace.push_back({(int)__IncidentList[s].size(), (int)__IncidentList[t].size()});
        __EdgeSet.push_back(Edge<CostType>(s, t, w));
        __IncidentList[s].push_back({__CntEdge, false});
        __RevEdgeSet.push_back(Edge<CostType>(t, s, w));
        if(!__isDirected) __IncidentList[t].push_back({__CntEdge, true});
        ++__CntEdge;
    }

    void add_flow(Vertex Source, Vertex Sink, CostType Capacity, CostType Cost = 1){
        assert(0 <= Source && Source < __CntVertex);
        assert(0 <= Sink && Sink < __CntVertex);
        __EdgeSet.push_back(Edge<CostType>(Source, Sink, Capacity, Cost));
        __IncidentList[Source].push_back({__CntEdge, false});
        __RevEdgeSet.push_back(Edge<CostType>(Sink, Source, 0, -Cost));
        __IncidentList[Sink].push_back({__CntEdge, true});
        ++__CntEdge;
    }

    void update_flow(EdgeID edge_id, bool isReverse, CostType Decrease){
        if(isReverse) Decrease *= -1;
        __EdgeSet[edge_id].cap -= Decrease;
        __RevEdgeSet[edge_id].cap += Decrease;
    }

    vector<vector<CostType>> matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){
        vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));
        for(Vertex v = 0; v < __CntVertex; ++v){
            ret[v][v] = 0;
            for(auto [eid, rev] : __IncidentList[v]){
                if(!rev) ret[v][__EdgeSet[eid].to] = __EdgeSet[eid].cost;
                else ret[v][__RevEdgeSet[eid].to] = __RevEdgeSet[eid].cost;
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

    inline Edge<CostType> get_edge(EdgeID edge_id, bool isReverse){
        return (isReverse ? __RevEdgeSet[edge_id] : __EdgeSet[edge_id]);
    }

    inline vector<Edge<CostType>>& get_edgeset(){
        return __EdgeSet;
    }

    vector<Edge<CostType>> get_incident(Vertex v){
        assert(0 <= v && v < __CntVertex);
        vector<Edge<CostType>> ret;
        for(auto [eid, rev] : __IncidentList[v]){
            Edge<CostType> e = __EdgeSet[eid];
            if(rev) e = __RevEdgeSet[eid];
            ret.push_back(e);
        }
        return ret;
    }

    vector<pair<EdgeID, bool>> get_raw_incident(Vertex v){
        assert(0 <= v && v < __CntVertex);
        return __IncidentList[v];
    }

    vector<pair<Vertex, EdgeID>> convert_rootedtree(Vertex Root = 0){
        assert(0 <= Root && Root < __CntVertex);
        vector<pair<Vertex, EdgeID>> ret(__CntVertex, {-1, -1});
        vector<int> visited(__CntVertex, 0);
        queue<Vertex> que;
        que.push(Root);
        while(que.size()){
            Vertex now = que.front(); que.pop();
            if(visited[now]) continue;
            visited[now] = 1;
            for(int i = 0; i < __IncidentList[now].size(); ++i){
                auto [eid, rev] = __IncidentList[now][i];
                Edge<CostType> e = get_edge(eid, rev);
                if(visited[e.to]) continue;
                que.push(e.to);
                ret[e.to] = {now, eid};
                if(rev){
                    __IncidentList[e.from][__EdgePlace[eid].second].second = false;
                    __IncidentList[e.to][__EdgePlace[eid].first].second = true;
                    __EdgeSet[eid].swap();
                    __RevEdgeSet[eid].swap();
                    swap(__EdgePlace[eid].first, __EdgePlace[eid].second);
                }
            }
        }
        return ret;
    }

    vector<Edge<CostType>> operator[](Vertex v){
        return get_incident(v);
    }

    void print_edgeset(bool OneIndex = true){
        for(int e = 0; e < __CntEdge; ++e){
            cout << e + OneIndex << " : (" << __EdgeSet[e].from + OneIndex << (__isDirected ? " -> " : " <-> ") << __EdgeSet[e].to + OneIndex << ") = " << __EdgeSet[e].cost << " (" << __EdgeSet[e].cap << ")" << endl;
        }
    }

    void print_incidentlist(bool OneIndex = true){
        for(int i = 0; i < __CntVertex; ++i){
            cout << i + OneIndex << " :";
            for(int j = 0; j < __IncidentList[i].size(); ++j){
                cout << " (" << __IncidentList[i][j].first << " / " << __IncidentList[i][j].second << ")";
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