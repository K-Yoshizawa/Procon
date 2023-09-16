#include "FordFulkerson.hpp"

struct BipartiteMatching{
    private:
    Graph<int> G, H;
    int X, Y, s, t;
    set<pair<Vertex, Vertex>> remain_edge;
    vector<int> mark_X, mark_Y;

    public:
    BipartiteMatching(int X, int Y, int src_flow = 1, int sink_flow = 1) : X(X), Y(Y), s(X + Y), t(X + Y + 1){
        G = Graph<int>(X + Y + 2, true);
        for(Vertex x = 0; x < X; ++x) G.add_flow(s, x, src_flow);
        for(Vertex y = X; y < X + Y; ++y) G.add(y, t, sink_flow);
    }

    void add_flow(int x, int y, int flow = 1){
        G.add_flow(x, X + y, flow);
        remain_edge.insert({x, X + y});
    }

    int solve(bool MakeSubGraph = false){
        FordFulkerson<int> ff(G);
        int ret = ff.solve(s, t);
        if(MakeSubGraph){
            H = Graph<int>(X + Y, true);
            mark_X.resize(X, 1), mark_Y.resize(Y, 0);
            for(auto [e, f] : ff.flew_list){
                auto [x, y] = e;
                H.add(y, x);
                remain_edge.erase({x, y});
                mark_X[x] = 0;
            }
            for(auto [x, y] : remain_edge){
                H.add(x, y);
            }
            for(Vertex x = 0; x < X; ++x){
                if(!mark_X[x]) continue;
                queue<Vertex> que;
                que.push(x);
                while(que.size()){
                    Vertex now = que.front();
                    que.pop();
                    for(auto e : H.get_incident(now)){
                        if(e.to < X && !mark_X[e.to]){
                            mark_X[e.to] = 1;
                            que.push(e.to);
                        }
                        if(e.to >= X && !mark_Y[e.to - X]){
                            mark_Y[e.to - X] = 1;
                            que.push(e.to);
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    // todo : ここに最小辺被覆とか書く
};