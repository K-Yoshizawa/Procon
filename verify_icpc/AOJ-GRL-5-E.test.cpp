#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../icpc/HeavyLightDecomposition.hpp"

struct segtree{
    int sz, ofs;

    using pl = pair<ll, ll>;
    vector<pl> dat;
    vl laz;
    pl e;
    ll oe;

    pl merge(pl x, pl y){
        return {x.first + y.first, x.second + y.second};
    }

    pl mapping(pl m, ll x){
        return {m.first + x * m.second, m.second};
    }

    ll composite(ll x, ll y){
        return x + y;
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

    pl subquery(int ql, int qr, int l, int r, int i){
        eval(i);
        if(qr <= l || r <= ql) return e;
        if(ql <= l && r <= qr) return dat[i];
        int m = (l + r) / 2;
        pl al = subquery(ql, qr, l, m, i * 2);
        pl ar = subquery(ql, qr, m, r, i * 2 + 1);
        return merge(al, ar);
    }

    segtree(vl &init) : e({0, 1}), oe(0){
        sz = 1;
        while(sz < init.size()) sz <<= 1;
        ofs = sz - 1;
        dat.resize(sz * 2, e);
        laz.resize(sz * 2, oe);
        for(int i = 0; i < init.size(); ++i) dat[sz + i].first = init[i];
        for(int i = ofs; i >= 1; --i) dat[i] = merge(dat[i * 2], dat[i * 2 + 1]);
    }

    void update(int l, int r, ll v){
        subupdate(l, r, v, 1, sz + 1, 1);
    }

    ll query(int l, int r){
        return subquery(l, r, 1, sz + 1, 1).first;
    }

    ll get(int k){
        return query(k, k + 1);
    }
};

int main(){
    int n; cin >> n;
    Graph G(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G[i].push_back({c, 1});
            G[c].push_back({i, 1});
        }
    }

    hld HLD(G);
    vi p = HLD.location();
    vl init(n, 0);
    segtree seg(init);

    int q; cin >> q;
    ll cum = 0;
    for(int i = 0; i < q; ++i){
        int com; cin >> com;
        if(com == 0){
            int v, w; cin >> v >> w;
            cum += w;
            for(auto [l, r] : HLD.pathquery(v)){
                seg.update(l, r, w);
            }
        }
        else{
            int u; cin >> u;
            ll ans = 0;
            for(auto [l, r] : HLD.pathquery(u)){
                ans += seg.query(l, r);
            }
            cout << ans - cum << endl;
        }
    }
}