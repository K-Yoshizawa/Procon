#include "../Common.hpp"

#define LEFT 0
#define RIGHT 1
#define SENTINEL 0
#define BLACK 0
#define RED 1

template<typename T>
class RedBlackTree{
    public:
    RedBlackTree(int N = 500010){
        nodes_.resize(N);
        next_ = 1;
        nodes_[SENTINEL].color = BLACK;
        nodes_[SENTINEL].size = 0;
        nodes_[SENTINEL].parent = SENTINEL;
        nodes_[SENTINEL].child[0] = nodes_[SENTINEL].child[1] = SENTINEL;
        root_ = SENTINEL;
    }

    void Insert(T x){
        // 根が空なら根に挿入
        if(root_ == SENTINEL){
            root_ = CreateNode(x, SENTINEL);
            nodes_[SENTINEL].child[0] = root_;
            SetColor(root_, BLACK);
            return;
        }

        // 挿入するノード
        int nt;

        // 既存かのチェックと挿入場所(どのノードの子か)の探索
        for(int nx = root_;;){
            // 既存チェック
            if(nodes_[nx].value == x){
                return;
            }

            // 探索方向の取得
            bool direction = GetDirection(nodes_[nx].value, x);
            // 探索先がNULL(xが葉)なら、その位置にノードを挿入
            if(nodes_[nx].child[direction] == SENTINEL){
                nodes_[nx].child[direction] = CreateNode(x, nx);
                nt = nodes_[nx].child[direction];
                for(int target_node = nx; target_node != SENTINEL; target_node = nodes_[target_node].parent){
                    UpdateSize(target_node);
                }
                break;
            }
            nx = nodes_[nx].child[direction];
        }

        // 整合性チェック
        while(1){
            // 現在のノードが根なら黒くして終わり
            if(nodes_[nt].parent == SENTINEL){
                SetColor(nt, BLACK);
                return;
            }

            // ノードx -> ノードtの親(直前のif文よりcは根ではない)
            int nx;
            bool xt_dir;
            tie(nx, xt_dir) = GetParent(nt);

            // 現在ノードまたは親ノードが黒なら問題なし
            if(GetColor(nt) == BLACK || GetColor(nx) == BLACK){
                break;
            }

            // ノードz -> ノードxの親(直前のif文よりxは根ではない)
            int ny, nz;
            bool yx_dir;
            tie(nz, yx_dir) = GetParent(nx);
            // ノードy -> ノードzの子のうち、xではない方(NULLの場合もあるので注意)
            ny = nodes_[nz].child[!yx_dir];

            if(GetColor(ny) == RED){
                // ノードyが赤ならx,y,zの色を反転
                SetColor(nx, BLACK);
                SetColor(ny, BLACK);
                SetColor(nz, RED);
                // ノードzを起点として次の整合性チェック
                nt = nz;
            }
            else{
                if(xt_dir != yx_dir){
                    // xを回転させてxc_dir == yx_dirのパターンに帰着させる
                    Rotate(nx, yx_dir);
                    swap(nx, nt);
                }
                // zを回転させてxとzの色を変更する
                Rotate(nz, !yx_dir);
                SetColor(nx, BLACK);
                SetColor(nz, RED);
                break;
            }
        }
    }

    void Erase(T x){
        // 削除するノード
        int nt = Search(x);
        if(nt == SENTINEL) return;

        bool removed_color;
        if(nodes_[nt].child[LEFT] != SENTINEL && nodes_[nt].child[RIGHT] != SENTINEL){
            // ノードtが子を2個持つ
            // ノードtの右の子から最も小さいノードsを探す
            int ns = nodes_[nt].child[RIGHT];
            while(nodes_[ns].child[LEFT] != SENTINEL){
                ns = nodes_[ns].child[LEFT];
            }
            // ついでに、その位置に来ることになるノードxの親ノードpを持っておく
            int np;
            bool px_dir;
            tie(np, px_dir) = GetParent(ns);
            if(nodes_[ns].parent == nt){
                Lift(nt);
                nodes_[ns].child[LEFT] = nodes_[nt].child[LEFT];
                np = ns;
            }
            else{
                Lift(ns);
                Replace(nt, ns);
            }
            removed_color = GetColor(ns);
            SetColor(ns, GetColor(nt));

            // ノードxから頑張って色塗りする
            int nx = nodes_[np].child[px_dir];
            UpdateSizeToRoot(np);
            if(removed_color == BLACK){
                Fixup(nx, np, px_dir);
            }
        }
        else{
            // ノードtが子を0or1個持つ
            removed_color = GetColor(nt);
            int np;
            bool pt_dir;
            tie(np, pt_dir) = GetParent(nt);
            Lift(nt);
            int nx = nodes_[np].child[pt_dir];
            UpdateSizeToRoot(np);
            if(removed_color == BLACK){
                Fixup(nx, np, pt_dir);
            }
        }
    }

    bool Contains(T x){
        return Search(x) != SENTINEL;
    }

    inline int Size(){
        return nodes_[root_].size;
    }

    T KthElement(int k, T e = T{}){
        if(k > Size() || k < 1) return e;
        int node = root_;
        int cum = 0;
        while(1){
            int lc = nodes_[nodes_[node].child[LEFT]].size;
            if(cum + lc + 1 == k) return nodes_[node].value;
            if(cum + lc + 1 > k) node = nodes_[node].child[LEFT];
            else cum += lc + 1, node = nodes_[node].child[RIGHT];
        }
    }

    int CountLess(T x){
        return CountLessImpl(x, false);
    }

    int CountLessEqual(T x){
        return CountLessImpl(x, true);
    }

    int CountGreater(T x){
        return Size() - CountLessImpl(x, true);
    }

    int CountGreaterEqual(T x){
        return Size() - CountLessImpl(x, false);
    }

    T MaximumLess(T x, T inf = numeric_limits<T>::min()){
        if(root_ == SENTINEL) return inf;
        int node = root_;
        T ret = inf;
        while(node != SENTINEL){
            if(nodes_[node].value < x){
                ret = nodes_[node].value;
                node = nodes_[node].child[RIGHT];
            }
            else{
                node = nodes_[node].child[LEFT];
            }
        }
        return ret;
    }

    T MaximumLessEqual(T x, T inf = numeric_limits<T>::min()){
        if(root_ == SENTINEL) return inf;
        int node = root_;
        T ret = inf;
        while(node != SENTINEL){
            if(nodes_[node].value <= x){
                ret = nodes_[node].value;
                node = nodes_[node].child[RIGHT];
            }
            else{
                node = nodes_[node].child[LEFT];
            }
        }
        return ret;
    }

    T MinimumGreater(T x, T inf = numeric_limits<T>::max()){
        if(root_ == SENTINEL) return inf;
        int node = root_;
        T ret = inf;
        while(node != SENTINEL){
            if(nodes_[node].value > x){
                ret = nodes_[node].value;
                node = nodes_[node].child[LEFT];
            }
            else{
                node = nodes_[node].child[RIGHT];
            }
        }
        return ret;
    }

    T MinimumGreaterEqual(T x, T inf = numeric_limits<T>::max()){
        if(root_ == SENTINEL) return inf;
        int node = root_;
        T ret = inf;
        while(node != SENTINEL){
            if(nodes_[node].value >= x){
                ret = nodes_[node].value;
                node = nodes_[node].child[LEFT];
            }
            else{
                node = nodes_[node].child[RIGHT];
            }
        }
        return ret;
    }

    private:
    struct Node{
        int parent;
        int child[2];
        bool color;
        T value;
        int size;
    };

    vector<Node> nodes_;
    int root_, next_;

    int CreateNode(T value, int parent){
        int ret = next_++;
        Node &n = nodes_[ret];
        n.parent = parent;
        n.child[LEFT] = n.child[RIGHT] = SENTINEL;
        n.color = RED;
        n.value = value;
        n.size = 1;
        return ret;
    }

    inline void UpdateSize(int node){
        nodes_[node].size = 1 + nodes_[nodes_[node].child[0]].size + nodes_[nodes_[node].child[1]].size;
    }

    inline bool GetDirection(T parent_value, T child_value){
        if(child_value < parent_value) return LEFT;
        if(child_value > parent_value) return RIGHT;
        assert(false);
    }

    pair<int, bool> GetParent(int node){
        int parent = nodes_[node].parent;
        return make_pair(parent, parent == SENTINEL || nodes_[parent].child[LEFT] == node ? LEFT : RIGHT);
    }

    inline void SetParent(int node, int parent){
        if(node){
            nodes_[node].parent = parent;
        }
    }

    inline bool GetColor(int node){
        return nodes_[node].color;
    }

    inline void SetColor(int node, bool color){
        if(node != SENTINEL){
            nodes_[node].color = color;
        }
    }

    void Rotate(int nx, bool direction){
        // ここでは左回転の話
        assert(nx != SENTINEL);
        // ノードxを左回転 -> ノードxの右の子(ノードy)との親子関係を入れ替える(ので非NULLである必要がある)
        int ny = nodes_[nx].child[!direction];
        assert(ny != SENTINEL);
        // ノードyの左の子(ノードz) -> ノードxの右の子になる
        int nz = nodes_[ny].child[direction];
        // ノードxの親(ノードp)
        int np; bool px_dir;
        tie(np, px_dir) = GetParent(nx);

        // pの子: x -> y
        nodes_[np].child[px_dir] = ny;
        nodes_[ny].parent = np;
        root_ = nodes_[SENTINEL].child[LEFT];

        // xの右の子: y -> z
        nodes_[nx].child[!direction] = nz;
        if(nz != SENTINEL) nodes_[nz].parent = nx;

        // yの左の子: z -> x
        nodes_[ny].child[direction] = nx;
        nodes_[nx].parent = ny;

        UpdateSize(nx);
        UpdateSize(ny);
    }

    int Search(T value){
        int node = root_;
        while(node != SENTINEL){
            if(value == nodes_[node].value) return node;
            if(value < nodes_[node].value) node = nodes_[node].child[LEFT];
            else node = nodes_[node].child[RIGHT];
        }
        return SENTINEL;
    }

    void Lift(int nt){
        assert(nt);
        int np; bool pt_dir;
        tie(np, pt_dir) = GetParent(nt);
        // tの子ノードの内、持ち上げる方をx、そのままの方をyとする
        // 基本はxが右の子だが、xがNULLならyとswapする(両方NULLの場合もあるので注意)
        int nx = nodes_[nt].child[RIGHT], ny = nodes_[nt].child[LEFT];
        if(nx == SENTINEL) swap(nx, ny);
        nodes_[np].child[pt_dir] = nx;
        SetParent(nx, np);
        SetParent(ny, nx);
        root_ = nodes_[SENTINEL].child[LEFT];
    }

    void Replace(int nx, int ny){
        // ノードxの位置にノードyを置換する
        assert(nx && ny);
        int np; bool px_dir;
        tie(np, px_dir) = GetParent(nx);
        int lc = nodes_[nx].child[LEFT], rc = nodes_[nx].child[RIGHT];
        nodes_[np].child[px_dir] = nodes_[lc].parent = nodes_[rc].parent = ny;
        nodes_[ny].parent = np;
        nodes_[ny].child[LEFT] = lc;
        nodes_[ny].child[RIGHT] = rc;
        root_ = nodes_[SENTINEL].child[LEFT];
    }

    void UpdateSizeToRoot(int node){
        for(; node != SENTINEL; node = nodes_[node].parent){
            UpdateSize(node);
        }
    }

    void Fixup(int nx, int np, bool px_dir){
        while(np != SENTINEL && GetColor(nx) == BLACK){
            // ノードy -> ノードpのxではない方の子
            int ny = nodes_[np].child[!px_dir];
            assert(ny);
            if(GetColor(ny) == RED){
                SetColor(np, RED);
                SetColor(ny, BLACK);
                Rotate(np, px_dir);
                ny = nodes_[np].child[!px_dir];
            }
            else{
                // ノードn, f -> ノードyの子のうち、xに近い方と遠い方
                int nn = nodes_[ny].child[px_dir], nf = nodes_[ny].child[!px_dir];
                if(GetColor(nn) == BLACK && GetColor(nf) == BLACK){
                    SetColor(ny, RED);
                    nx = np;
                    tie(np, px_dir) = GetParent(nx);
                }
                else{
                    if(GetColor(nf) == BLACK){
                        SetColor(ny, RED);
                        SetColor(nn, BLACK);
                        Rotate(ny, !px_dir);
                        ny = nodes_[np].child[!px_dir];
                        nf = nodes_[ny].child[!px_dir];
                    }
                    SetColor(ny, GetColor(np));
                    SetColor(np, BLACK);
                    SetColor(nf, BLACK);
                    Rotate(np, px_dir);
                    break;
                }
            }
        }
        SetColor(nx, BLACK);
    }

    int CountLessImpl(T x, bool equal){
        int cum = 0;
        int node = root_;
        while(node != SENTINEL){
            int lc = nodes_[nodes_[node].child[LEFT]].size;
            if(x == nodes_[node].value) return cum + lc + equal;
            if(x < nodes_[node].value) node = nodes_[node].child[LEFT];
            else{
                cum += lc + 1;
                node = nodes_[node].child[RIGHT];
            }
        }
        return cum;
    }
};

#undef LEFT
#undef RIGHT
#undef SENTINEL
#undef BLACK
#undef RED