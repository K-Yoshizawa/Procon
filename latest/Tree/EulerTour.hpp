

#include "../Graph/GraphTemplate.hpp"

template<typename CostType>
struct EulerTour{
    private:
    int __Size, __Offset, __Counter;
    Vertex __Root;
    Graph<CostType> &G;
    vector<int> __Arrival, __Departure;

    void __dfs(Vertex now, Vertex parent){
        __Arrival[now] = __Counter++;
        for(auto &e : G[now]){
            if(e.to == parent) continue;
            __dfs(e.to, now);
        }
        __Departure[now] = __Counter++;
    }

    public:
    EulerTour(Graph<CostType> &G, Vertex Root = 0, int Offset = 1) : G(G), __Size(G.vsize()), __Root(Root), __Arrival(G.vsize()), __Departure(G.vsize()), __Offset(Offset){
        __Counter = __Offset;
        __dfs(__Root, -1);
    }

    vector<int> get_arrival_list(){
        return __Arrival;
    }

    vector<int> get_departure_list(){
        return __Departure;
    }

    pair<int, int> get_way(Vertex Target){
        assert(0 <= Target && Target < G.vsize());
        return {__Arrival[__Root], __Arrival[Target]};
    }

    pair<int, int> get_around(Vertex Target){
        assert(0 <= Target && Target < G.vsize());
        return {__Arrival[Target], __Departure[Target]};
    }
};