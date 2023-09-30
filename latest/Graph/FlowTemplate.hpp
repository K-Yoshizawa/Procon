#pragma once

/**
 * @file FlowTemplate.hpp
 * @author log K (lX57)
 * @brief Flow Template - フローテンプレート
 * @version 0.1
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
        Edge<CostType> es{this->__CntEdge, Source, To, Cost, Capacity, sidx, tidx};
        Edge<CostType> et{this->__CntEdge, To, Source, -Cost, 0, tidx, sidx};
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
        this->__IL[Source][Index].cap -= Amount;
        this->__IL[To][RIndex].cap += Amount;
    }

    EdgeSet<CostType> get(){
        EdgeSet<CostType> ret;
        for(Vertex i = 0; i < this->__CntVertex; ++i){
            for(EdgeIndex j = 0; j < this->__IL[i].size(); ++j){
                if(!__Rev[i][j]){
                    ret.push_back(this->__IL[i][j]);
                }
            }
        }
        return ret;
    }
};