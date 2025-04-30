#include "../Common.hpp"
#include "../Tree/Tree.hpp"

template<int MAXSIZE = 500010>
class Trie{
    public:
    Trie(vector<string> &S_) : S(S_), n((int)S_.size()), v(1), vertex_(n), child_(MAXSIZE){
        for(int i = 0; i < MAXSIZE; ++i){
            child_[i].fill(-1);
        }
        for(int i = 0; i < n; ++i){
            int p = 0, m = S[i].size();
            vertex_[i].resize(m + 1, 0);
            for(int j = 0; j < m; ++j){
                int c = S[i][j] - 'a';
                if(child_[p][c] == -1){
                    child_[p][c] = v++;
                }
                p = child_[p][c];
                vertex_[i][j + 1] = p;
            }
        }
    }

    Graph<int32_t> Build() const {
        Graph<int32_t> ret(v);
        for(int i = 0; i < v; ++i){
            for(int j = 0; j < 26; ++j){
                if(child_[i][j] == -1) continue;
                ret.AddUndirectedEdge(i, child_[i][j]);
            }
        }
        return ret;
    }

    vector<int> &operator[](const int i){
        return vertex_[i];
    }

    private:
    vector<string> &S;
    int n, v;
    vector<vector<int>> vertex_;
    vector<array<int, 26>> child_;
};