#include "Graph.hpp"
#include "GraphMisc.hpp"

template<typename CostType>
struct StronglyConnectedComponents{
    public:
    StronglyConnectedComponents(Graph<CostType> &graph) :
        G(graph), RG(ReverseGraph(graph)), n(G.VertexSize()), belong_(n, -1){
        vector<int> label(n, -1);
        vector<bool> state(n, false);
        int nex = 0;
        vector<Vertex> vs(n);
        iota(vs.begin(), vs.end(), 0);
        for(auto v : vs){
            if(!state[v]) dfs1(v, label, nex, state);
        }
        sort(vs.begin(), vs.end(), [&](Vertex u, Vertex v){
            return label[u] > label[v];
        });
        for(auto v : vs){
            if(state[v]){
                int c = components_.size();
                components_.push_back(vector<Vertex>{});
                dfs2(v, label, c, state);
            }
        }
    }

    inline vector<vector<Vertex>> &Components(){
        return components_;
    }

    inline int ComponentCount() const {
        return (int)components_.size();
    }

    inline int BelongComponent(const Vertex &v) const {
        return belong_[v];
    }

    vector<Vertex> TopologicalSort() const {
        vector<Vertex> ret;
        for(const auto &vs : components_){
            for(const auto &v : vs){
                ret.emplace_back(v);
            }
        }
        return ret;
    }
    
    Graph<CostType> ContractedGraph() const {
        int nn = ComponentCount();
        Graph<CostType> ret(nn);
        for(int u = 0; u < n; ++u){
            int nu = BelongComponent(u);
            for(const Edge<CostType> &e : G[u]){
                int nv = BelongComponent(e.to);
                if(nu == nv) continue;
                ret.AddDirectedEdge(nu, nv, e.cost);
            }
        }
        return ret;
    }

    inline int operator[](const Vertex &v){
        return BelongComponent(v);
    }

    inline const int operator[](const Vertex &v) const {
        return BelongComponent(v);
    }

    private:
    Graph<CostType> &G;
    Graph<CostType> RG;
    int n;
    vector<vector<Vertex>> components_;
    vector<int> belong_;

    void dfs1(Vertex v, vector<int> &label, int &nex, vector<bool> &state){
        state[v] = true;
        for(const Edge<CostType> &e : G[v]){
            if(state[e.to]) continue;
            dfs1(e.to, label, nex, state);
        }
        label[v] = nex++;
        return;
    }

    void dfs2(Vertex v, vector<int> &label, int component, vector<bool> &state){
        components_[component].push_back(v);
        belong_[v] = component;
        state[v] = false;
        for(const Edge<CostType> &e : RG[v]){
            if(!state[e.to]) continue;
            dfs2(e.to, label, component, state);
        }
        return;
    }
};