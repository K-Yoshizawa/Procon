#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../library/Graph/BellmanFord.hpp"

using namespace std;

int main(){
    int V, E, r; cin >> V >> E >> r;
    GraphE<int> G(V, true);
    G.input(E, true, true);

    auto ans = BellmanFord(G, r);
    if(ans.empty()){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(auto &d : ans){
            if(d == G.INF){
                cout << "INF" <<endl;
            }
            else{
                cout << d << endl;
            }
        }
    }
}