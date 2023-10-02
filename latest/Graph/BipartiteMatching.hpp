/**
 * @file BipartiteMatching.hpp
 * @author log K (lX57)
 * @brief Bipartite Matching - 二部グラフの最大マッチング
 * @version 2.1
 * @date 2023-10-02
 */

#include "FordFulkerson.hpp"

struct BipartiteMatching{
    private:
    Flow<int> G, H;
    int __L, __R;
    Vertex __S, __T;
    vector<pair<Vertex, Vertex>> __Matching;

    bool __SubGraph;
    set<pair<Vertex, Vertex>> remain_edge;
    vector<int> mark_L, mark_R;
    int ML, MR;

    public:
    BipartiteMatching(int L, int R, int src_flow = 1, int sink_flow = 1, bool MakeSubGraph = false) : __L(L), __R(R), __S(L + R), __T(L + R + 1), __SubGraph(MakeSubGraph){
        G = Flow<int>(__L + __R + 2);
        for(Vertex l = 0; l < __L; ++l) G.add(__S, l, src_flow);
        for(Vertex r = __L; r < __L + __R; ++r) G.add(r, __T, sink_flow);
    }

    void add(int l, int r, int flow = 1){
        G.add(l, __L + r, flow);
        remain_edge.insert({l, __L + r});
    }

    int solve(bool MakeSubGraph = false){
        FordFulkerson<int> ff(G);
        int ret = ff.solve(__S, __T);
        for(auto e : ff.get()) if(e.src != __S && e.to != __T) __Matching.push_back({e.src, e.to - __L});
        if(MakeSubGraph){
            H = Flow<int>(__L + __R);
            mark_L.resize(__L, 1), mark_R.resize(__R, 0);
            for(auto [l, r] : __Matching){
                H.add(r, l);
                remain_edge.erase({l, r});
                mark_L[l] = 0;
            }
            for(auto [l, r] : remain_edge){
                H.add(l, r);
            }
            for(Vertex l = 0; l < __L; ++l){
                if(!mark_L[l]) continue;
                queue<Vertex> que;
                que.push(l);
                while(que.size()){
                    Vertex now = que.front();
                    que.pop();
                    for(auto e : H.get_incident(now)){
                        if(e.to < __L && !mark_L[e.to]){
                            mark_L[e.to] = 1;
                            que.push(e.to);
                        }
                        if(e.to >= __L && !mark_R[e.to - __L]){
                            mark_R[e.to - __L] = 1;
                            que.push(e.to);
                        }
                    }
                }
            }
            ML = accumulate(mark_L.begin(), mark_L.end(), 0);
            MR = accumulate(mark_R.begin(), mark_R.end(), 0);
        }
        return ret;
    }

    vector<pair<Vertex, Vertex>> get_matching(){
        return __Matching;
    }
    
    int MinimumVertexCover(){
        return __L - ML + MR;
    }

    int MaximumIndependentSet(){
        return ML + __R - MR;
    }
};