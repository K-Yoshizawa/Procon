#include "Template.hpp"

struct segtree{
    int sz, ofs;
    vl dat, laz;
    ll e, oe;

    ll merge(ll x, ll y){
        return min(x, y);
    }

    ll mapping(ll m, ll x){
        return x;
    }

    ll composite(ll x, ll y){
        return y;
    }

    void eval(int i){
        if(laz[i] == oe) return;
        if(i < sz){
            laz[i * 2] = composite(laz[i * 2], laz[i]);
            laz[i * 2 + 1] = composite(laz[i * 2 + 1], laz[i]);
        }
        dat[i] = mapping(dat[i], laz[i]);
        laz[i] = oe;
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
            dat[i] = merge(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    ll subquery(int ql, int qr, int l, int r, int i){
        eval(i);
        if(qr <= l || r <= ql) return e;
        if(ql <= l && r <= qr) return dat[i];
        int m = (l + r) / 2;
        ll al = subquery(ql, qr, l, m, i * 2);
        ll ar = subquery(ql, qr, m, r, i * 2 + 1);
        return merge(al, ar);
    }

    segtree(vl &init) : e((1LL << 31) - 1), oe((1LL << 31) - 1){
        sz = 1;
        while(sz < init.size()) sz <<= 1;
        ofs = sz - 1;
        dat.resize(sz * 2, e);
        laz.resize(sz * 2, oe);
        for(int i = 0; i < init.size(); ++i) dat[sz + i] = init[i];
        for(int i = ofs; i >= 1; --i) dat[i] = merge(dat[i * 2], dat[i * 2 + 1]);
    }

    void update(int l, int r, ll v){
        subupdate(l, r, v, 1, sz + 1, 1);
    }

    ll query(int l, int r){
        return subquery(l, r, 1, sz + 1, 1);
    }

    ll get(int k){
        return query(k, k + 1);
    }
};