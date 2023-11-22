#include "Template.hpp"

struct segtree{
    int sz, ofs;
    vl laz;
    ll oe;

    ll composite(ll x, ll y){
        return y;
    }

    void eval(int i){
        if(laz[i] == oe) return;
        if(i < sz){
            laz[i * 2] = composite(laz[i * 2], laz[i]);
            laz[i * 2 + 1] = composite(laz[i * 2 + 1], laz[i]);
            laz[i] = oe;
        }
    }

    void subupdate(int ul, int ur, ll x, int l, int r, int i){
        eval(i);
        if(ul <= l && r <= ur){
            laz[i] = composite(laz[i], x);
            eval(i);
        }
        else if(ul < r && l < ur){
            int m = (l + r) / 2;
            subupdate(ul, ur, x, l, m, i * 2);
            subupdate(ul, ur, x, m, r, i * 2 + 1);
        }
    }

    ll subquery(int i, int l, int r, int c){
        eval(c);
        if(i == l && r - l == 1) return laz[c];
        int m = (l + r) / 2;
        if(i < m) return subquery(i, l, m, c * 2);
        else return subquery(i, m, r, c * 2 + 1);
    }

    segtree(vl &init) : oe((1LL << 31) - 1){
        sz = 1;
        while(sz < init.size()) sz <<= 1;
        ofs = sz - 1;
        laz.resize(sz * 2, oe);
        for(int i = 0; i < init.size(); ++i) laz[sz + i] = init[i];
    }

    void update(int l, int r, ll v){
        subupdate(l, r, v, 1, sz + 1, 1);
    }

    ll query(int i){
        return subquery(i, 1, sz + 1, 1);
    }
};