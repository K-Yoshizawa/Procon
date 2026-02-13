#include "Tree.hpp"

struct PathSegment{
    PathSegment() = default;
    Vertex head_vertex;
    Vertex tail_vertex;
    int head_index;
    int tail_index;
    bool highest;
    bool reverse;
    friend ostream &operator<<(ostream &os, const PathSegment &p){
        return os << "# Path (" << p.head_vertex << " -> " << p.tail_vertex << ", " << p.head_index << " -> " << p.tail_index << ", " << boolalpha << p.highest << ", " << p.reverse << ")";
    }
};

template<typename WeightType>
class HeavyLightDecomposition{
    public:
    HeavyLightDecomposition(Graph<WeightType> &tree, Vertex r = 0) :
        T(tree), parent(CalculateTreeParent(tree, r)), child(RootedTreeAdjacentList(tree, r)), n((int)tree.VertexSize()), euler_tour_(n), rev_order_(n), depth_(CalculateTreeDepth(tree, r)), belong_hp_id_(n){
        vector<int> ss = CalculateSubtreeSize(T, r);
        for(int i = 0; i < n; ++i){
            if(child[i].empty()) continue;
            nth_element(child[i].begin(), child[i].begin() + 1, child[i].end(), [&](Vertex i, Vertex j){
                return ss[i] > ss[j];
            });
        }
        hp_head_.push_back(r);
        hp_depth_.push_back(0);
        belong_hp_id_[r] = 0;
        timer_ = 0;
        dfs(r, 0, 0);
    }

    Vertex LowestCommonAncestor(Vertex u, Vertex v) const {
        if(PathDepth(u) < PathDepth(v)) swap(u, v);
        while(PathDepth(u) != PathDepth(v)){
            u = parent[Head(u)];
        }
        while(Belong(u) != Belong(v)){
            u = parent[Head(u)];
            v = parent[Head(v)];
        }
        return depth_[u] < depth_[v] ? u : v;
    }

    Vertex LevelAncestor(Vertex v, int k){
        assert(k <= depth_[v]);
        Vertex ret = v;
        while(1){
            int h = Head(ret);
            int x = depth_[ret] - depth_[h];
            if(k <= x){
                ret = RevOrder(PreOrder(ret) - k);
                break;
            }
            ret = parent[h];
            k -= x + 1;
        }
        return ret;
    }

    int Jump(Vertex u, Vertex v, int k){
        Vertex w = LowestCommonAncestor(u, v);
        int p = depth_[u] - depth_[w], q = depth_[v] - depth_[w];
        if(p + q < k || k < 0) return -1;
        if(k <= p) return LevelAncestor(u, k);
        else return LevelAncestor(v, p + q - k);
    }

    vector<PathSegment> PathQuery(Vertex u, Vertex v){
        vector<PathSegment> ret;
        Vertex lca = LowestCommonAncestor(u, v);
        while(Belong(u) != Belong(lca)){
            PathSegment path;
            Vertex h = Head(u);
            path.head_vertex = h, path.tail_vertex = u;
            path.head_index = PreOrder(h), path.tail_index = PreOrder(u) + 1;
            path.highest = false, path.reverse = true;
            ret.push_back(path);
            u = parent[h];
        }
        if(u != lca){
            PathSegment path;
            path.head_vertex = lca, path.tail_vertex = u;
            path.head_index = PreOrder(lca), path.tail_index = PreOrder(u) + 1;
            path.highest = true, path.reverse = true;
            ret.push_back(path);
        }
        int size = ret.size();
        while(Belong(v) != Belong(lca)){
            PathSegment path;
            Vertex h = Head(v);
            path.head_vertex = h, path.tail_vertex = v;
            path.head_index = PreOrder(h), path.tail_index = PreOrder(v) + 1;
            path.highest = false, path.reverse = false;
            ret.push_back(path);
            v = parent[h];
        }
        if(v != lca){
            PathSegment path;
            path.head_vertex = lca, path.tail_vertex = v;
            path.head_index = PreOrder(lca), path.tail_index = PreOrder(v) + 1;
            path.highest = true, path.reverse = false;
            ret.push_back(path);
        }
        if(u == lca && v == lca){
            PathSegment path;
            path.head_vertex = path.tail_vertex = lca;
            path.head_index = PreOrder(lca), path.tail_index = PreOrder(lca) + 1;
            path.highest = true, path.reverse = false;
            ret.push_back(path);
        }
        reverse(ret.begin() + size, ret.end());
        return ret;
    }

    pair<int, int> SubtreeQuery(Vertex v) const {
        return euler_tour_[v];
    }

    template<typename T>
    void SortVertex(vector<T> &A){
        assert(A.size() == n);
        vector<T> sub(n);
        for(int i = 0; i < n; ++i){
            sub[PreOrder(i)] = A[i];
        }
        swap(A, sub);
    }

    int operator[](Vertex v){
        return PreOrder(v);
    }

    const int operator[](Vertex v) const {
        return PreOrder(v);
    }

    private:
    int dfs(Vertex v, int h, int d){
        euler_tour_[v].first = timer_;
        rev_order_[timer_] = v;
        ++timer_;
        int ret = timer_;
        if(!child[v].empty()){
            int c = child[v].size();
            belong_hp_id_[child[v].front()] = h;
            ret = max(ret, dfs(child[v].front(), h, d));
            for(int i = 1; i < c; ++i){
                int nh = (int)hp_head_.size();
                hp_head_.push_back(child[v][i]);
                hp_depth_.push_back(d + 1);
                belong_hp_id_[child[v][i]] = nh;
                ret = max(ret, dfs(child[v][i], nh, d + 1));
            }
        }
        euler_tour_[v].second = ret;
        return ret;
    }

    Vertex Head(Vertex v) const {
        return hp_head_[belong_hp_id_[v]];
    }

    int PathDepth(Vertex v) const {
        return hp_depth_[belong_hp_id_[v]];
    }

    int Belong(Vertex v) const {
        return belong_hp_id_[v];
    }

    Vertex RevOrder(int idx) const {
        return rev_order_[idx];
    }

    int PreOrder(Vertex v) const {
        return euler_tour_[v].first;
    }

    int PostOrder(Vertex v) const {
        return euler_tour_[v].second;
    }

    Graph<WeightType> &T;
    vector<Vertex> parent;
    vector<vector<Vertex>> child;
    int n, timer_;

    vector<pair<int, int>> euler_tour_;
    vector<Vertex> rev_order_;
    vector<int> depth_;

    vector<Vertex> hp_head_; // 各 heavy path の最も根に近い頂点
    vector<int> hp_depth_; // 各 heavy path の深さ
    vector<int> belong_hp_id_; // 各頂点が属する heavy path の番号
};