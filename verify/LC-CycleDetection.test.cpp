#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../Library/Template.hpp"
#include "../Library/Graph/CycleDetection.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int N, M; cin >> N >> M;
    auto G = InputGraph(N, M, 0, false, true);

    auto ret = CycleDetection(G);
    if(ret.empty()) cout << -1 << '\n';
    else{
        cout << ret.size() << '\n';
        for(const auto &e : ret){
            cout << e.idx << '\n';
        }
    }
}