#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A"

#include "../Library/Template.hpp"
#include "../Library/Tree/Tree.hpp"

int main(){
    int n; cin >> n;
    RootedTree T(n, -1);
    for(int i = 0; i < n; ++i){
        int id, k; cin >> id >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            T.AddEdge(id, c);
        }
    }

    auto depth = CalculateTreeDepth(T);
    for(int i = 0; i < n; ++i){
        cout << "node " << i << ": ";
        cout << "parent = " << T.get_parent(i) << ", ";
        cout << "depth = " << depth[i] << ", ";
        cout << (T.RootVertex(i) ? "root" : (T.LeafVertex(i) ? "leaf" : "internal node")) << ", ";
        cout << "[";
        auto c = T.get_child(i);
        for(int j = 0; j < c.size(); ++j){
            cout << c[j] << (j + 1 == c.size() ? "" : ", ");
        }
        cout << "]\n";
    }
}