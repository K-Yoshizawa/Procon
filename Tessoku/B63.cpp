#include <bits/stdc++.h>
using namespace std;

using unweighted_graph = vector<vector<int>>;

int main(){
    int R, C; cin >> R >> C;
    unweighted_graph g(R * C);
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
    vector<string> st(R);
    for(int i = 0; i < R; ++i) cin >> st[i];
    for(int r = 1; r < R - 1; ++r){
        for(int c = 1; c < C - 1; ++c){
            int v = r * C + c, u;
            if(st[r][c] != '.') continue;
            if(st[r + 1][c] == '.'){
                u = (r + 1) * C + c;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            if(st[r][c + 1] == '.'){
                u = r * C + (c + 1);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }

    int INF = 100100;
    int start = (sy - 1) * C + sx - 1;
    int goal = (gy - 1) * C + gx - 1;
    vector<int> ans(R * C, INF); ans[start] = 0;
    queue<int> que; que.push(start);
    while(!que.empty()){
        int now = que.front(); que.pop();
        int d = ans[now];
        for(auto next : g[now]){
            if(st[now / C][now % C] == '#') continue;
            if(d + 1 < ans[next]){
                que.push(next);
                ans[next] = d + 1;
            }
        }
    }

    cout << ans[goal] << endl;
}