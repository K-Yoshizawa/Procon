#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A"

#include "../Library/Template.hpp"
#include "../Library/Tree/Tree.hpp"

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    Graph T(n);
    vector<int> parent(n, -1);
    for(int i = 0; i < n; ++i){
        int id, k; cin >> id >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            T.AddUndirectedEdge(id, c);
            parent[c] = id;
        }
    }
    int root = [&]{
        for(int i = 0; i < n; ++i){
            if(parent[i] == -1) return i;
        }
        return -1;
    }();

    auto depth = CalculateTreeDepth(T, root);
    for(int i = 0; i < n; ++i){
        cout << "node " << i << ": ";
        cout << "parent = " << parent[i] << ", ";
        cout << "depth = " << depth[i] << ", ";
        cout << (i == root ? "root" : (T[i].size() == 1 ? "leaf" : "internal node")) << ", ";
        cout << "[";
        int child = T[i].size() - 1 + (i == root), cnt = 0;
        for(int j : T[i]){
            if(j == parent[i]) continue;
            ++cnt;
            cout << j << (cnt == child ? "" : ", ");
        }
        cout << "]\n";
    }
}