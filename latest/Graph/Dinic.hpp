#include "FlowTemplate.hpp"

template<typename CostType>
struct Dinic{
    Flow<CostType> &F;

    vector<int> __Dist, __Iter;

    void __bfs(Vertex Source){
        __Dist.assign(F.vsize(), -1);
        __Dist[Source] = 0;
        queue<Vertex> que; que.push(Source);
        while(que.size()){
            Vertex now = que.front(); que.pop();
            for(auto e : F.get_incident(now)){
                if(e.cap > 0 && __Dist[e.to] < 0){
                    __Dist[e.to] = __Dist[now] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    CostType __dfs(Vertex v, Vertex t, CostType f){
        if(v == t) return f;
        auto IL = F.get_incident(v);
        for(int &i = __Iter[v]; i < F.incsize(v); ++i){
            Edge<CostType> e = IL[i];
            if(e.cap > 0 && __Dist[v] < __Dist[e.to]){
                CostType d = __dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    F.update(v, e.sidx, d);
                    return d;
                }
            }
        }
        return 0;
    }

    public:
    Dinic(Flow<CostType> &F) : F(F){
        __Dist.resize(F.vsize());
        __Iter.resize(F.vsize());
    }

    CostType solve(Vertex Source, Vertex Sink){
        CostType ret = 0;
        while(1){
            __bfs(Source);
            if(__Dist[Sink] < 0) return ret;
            __Iter.assign(F.vsize(), 0);
            CostType f;
            while((f = __dfs(Source, Sink, F.INF)) > 0) ret += f;
        }
    }
};