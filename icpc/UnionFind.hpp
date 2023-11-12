#include "Template.hpp"

struct unionfind{
    vi dat;

    unionfind(int sz):dat(sz,-1){}

    int find(int k){
        if(dat[k]<0)return k;
        return dat[k]=find(dat[k]);
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }

    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return false;
        if(dat[x]>dat[y]) swap(x,y);
        dat[x]+=dat[y];
        dat[y]=x;
        return true;
    }
};