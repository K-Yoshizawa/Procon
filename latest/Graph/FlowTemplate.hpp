#pragma once

/**
 * @file FlowTemplate.hpp
 * @author log K (lX57)
 * @brief Flow Template - フローテンプレート
 * @version 1.0
 * @date 2023-09-29
 */

#include "GraphTemplate.hpp"

#define LOGK_FLOW

template<typename CostType>
struct Flow : public Graph<CostType>{
    using Graph<CostType>::Graph;

    vector<vector<int>> __Rev;

    public:
    void add(Vertex Source, Vertex To, CostType Capacity = 1, CostType Cost = 1){
        assert(0 <= Source && Source < this->__CntVertex);
        assert(0 <= To && To < this->__CntVertex);
        EdgeIndex sidx = this->__IL[Source].size(), tidx = this->__IL[To].size();
        Edge<CostType> es(this->__CntEdge, Source, To, Cost, Capacity, sidx, tidx);
        Edge<CostType> et(this->__CntEdge, To, Source, -Cost, 0, tidx, sidx);
        this->__ES.push_back(es);
        this->__RES.push_back(et);
        this->__IL[Source].push_back(es), this->__AL[Source].push_back(To);
        this->__IL[To].push_back(et), this->__AL[To].push_back(Source);
        ++this->__CntEdge;
        if(__Rev.empty()) __Rev.resize(this->__CntVertex);
        __Rev[Source].push_back(0), __Rev[To].push_back(1);
    }

    void update(Vertex Source, EdgeIndex Index, CostType Amount){
        Vertex To = this->__IL[Source][Index].to;
        EdgeIndex RIndex = this->__IL[Source][Index].tidx;
        EdgeID eid = this->__IL[Source][Index].ID;
        this->__IL[Source][Index].cap -= Amount;
        this->__IL[To][RIndex].cap += Amount;
        if(this->__ES[eid].src != Source) Amount *= -1;
        this->__ES[eid].cap -= Amount;
        this->__RES[eid].cap += Amount;
    }

    EdgeSet<CostType> restore_cut(Vertex Source){
        EdgeSet<CostType> ret;
        vector<int> arrive(this->vsize(), 0);
        queue<Vertex> que; que.push(Source);
        while(que.size()){
            Vertex now = que.front(); que.pop();
            if(arrive[now]) continue; arrive[now] = 1;
            for(auto e : this->get_incident(now)){
                if(e.cap <= 0 || arrive[e.to]) continue;
                que.push(e.to);
            }
        }
        for(int i = 0; i < this->esize(); ++i){
            Edge<CostType> e = this->__ES[i], re = this->__RES[i];
            // cerr << "[" << e.src << ", " << e.to << "] Cap = " << e.cap << endl;
            if(e.cap == 0 && arrive[e.src] && !arrive[e.to]){
                Edge<CostType> ne = e;
                ne.cap = re.cap;
                ret.push_back(ne);
            }
        }
        return ret;
    }
};