---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/DataStructure/LC-OrderedSet.test.cpp
    title: verify/DataStructure/LC-OrderedSet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Common.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nusing ll = int64_t;\n\
    using ull = uint64_t;\n\nconstexpr const ll INF = (1LL << 62) - (3LL << 30) -\
    \ 1;\n#line 2 \"Library/DataStructure/RedBlackTree.hpp\"\n\n#define LEFT 0\n#define\
    \ RIGHT 1\n#define SENTINEL 0\n#define BLACK 0\n#define RED 1\n\ntemplate<typename\
    \ T>\nclass RedBlackTree{\n    public:\n    RedBlackTree(int N = 500010){\n  \
    \      nodes_.resize(N);\n        next_ = 1;\n        nodes_[SENTINEL].color =\
    \ BLACK;\n        nodes_[SENTINEL].size = 0;\n        nodes_[SENTINEL].parent\
    \ = SENTINEL;\n        nodes_[SENTINEL].child[0] = nodes_[SENTINEL].child[1] =\
    \ SENTINEL;\n        root_ = SENTINEL;\n    }\n\n    void Insert(T x){\n     \
    \   // \u6839\u304C\u7A7A\u306A\u3089\u6839\u306B\u633F\u5165\n        if(root_\
    \ == SENTINEL){\n            root_ = CreateNode(x, SENTINEL);\n            nodes_[SENTINEL].child[0]\
    \ = root_;\n            SetColor(root_, BLACK);\n            return;\n       \
    \ }\n\n        // \u633F\u5165\u3059\u308B\u30CE\u30FC\u30C9\n        int nt;\n\
    \n        // \u65E2\u5B58\u304B\u306E\u30C1\u30A7\u30C3\u30AF\u3068\u633F\u5165\
    \u5834\u6240(\u3069\u306E\u30CE\u30FC\u30C9\u306E\u5B50\u304B)\u306E\u63A2\u7D22\
    \n        for(int nx = root_;;){\n            // \u65E2\u5B58\u30C1\u30A7\u30C3\
    \u30AF\n            if(nodes_[nx].value == x){\n                return;\n    \
    \        }\n\n            // \u63A2\u7D22\u65B9\u5411\u306E\u53D6\u5F97\n    \
    \        bool direction = GetDirection(nodes_[nx].value, x);\n            // \u63A2\
    \u7D22\u5148\u304CNULL(x\u304C\u8449)\u306A\u3089\u3001\u305D\u306E\u4F4D\u7F6E\
    \u306B\u30CE\u30FC\u30C9\u3092\u633F\u5165\n            if(nodes_[nx].child[direction]\
    \ == SENTINEL){\n                nodes_[nx].child[direction] = CreateNode(x, nx);\n\
    \                nt = nodes_[nx].child[direction];\n                for(int target_node\
    \ = nx; target_node != SENTINEL; target_node = nodes_[target_node].parent){\n\
    \                    UpdateSize(target_node);\n                }\n           \
    \     break;\n            }\n            nx = nodes_[nx].child[direction];\n \
    \       }\n\n        // \u6574\u5408\u6027\u30C1\u30A7\u30C3\u30AF\n        while(1){\n\
    \            // \u73FE\u5728\u306E\u30CE\u30FC\u30C9\u304C\u6839\u306A\u3089\u9ED2\
    \u304F\u3057\u3066\u7D42\u308F\u308A\n            if(nodes_[nt].parent == SENTINEL){\n\
    \                SetColor(nt, BLACK);\n                return;\n            }\n\
    \n            // \u30CE\u30FC\u30C9x -> \u30CE\u30FC\u30C9t\u306E\u89AA(\u76F4\
    \u524D\u306Eif\u6587\u3088\u308Ac\u306F\u6839\u3067\u306F\u306A\u3044)\n     \
    \       int nx;\n            bool xt_dir;\n            tie(nx, xt_dir) = GetParent(nt);\n\
    \n            // \u73FE\u5728\u30CE\u30FC\u30C9\u307E\u305F\u306F\u89AA\u30CE\u30FC\
    \u30C9\u304C\u9ED2\u306A\u3089\u554F\u984C\u306A\u3057\n            if(GetColor(nt)\
    \ == BLACK || GetColor(nx) == BLACK){\n                break;\n            }\n\
    \n            // \u30CE\u30FC\u30C9z -> \u30CE\u30FC\u30C9x\u306E\u89AA(\u76F4\
    \u524D\u306Eif\u6587\u3088\u308Ax\u306F\u6839\u3067\u306F\u306A\u3044)\n     \
    \       int ny, nz;\n            bool yx_dir;\n            tie(nz, yx_dir) = GetParent(nx);\n\
    \            // \u30CE\u30FC\u30C9y -> \u30CE\u30FC\u30C9z\u306E\u5B50\u306E\u3046\
    \u3061\u3001x\u3067\u306F\u306A\u3044\u65B9(NULL\u306E\u5834\u5408\u3082\u3042\
    \u308B\u306E\u3067\u6CE8\u610F)\n            ny = nodes_[nz].child[!yx_dir];\n\
    \n            if(GetColor(ny) == RED){\n                // \u30CE\u30FC\u30C9\
    y\u304C\u8D64\u306A\u3089x,y,z\u306E\u8272\u3092\u53CD\u8EE2\n               \
    \ SetColor(nx, BLACK);\n                SetColor(ny, BLACK);\n               \
    \ SetColor(nz, RED);\n                // \u30CE\u30FC\u30C9z\u3092\u8D77\u70B9\
    \u3068\u3057\u3066\u6B21\u306E\u6574\u5408\u6027\u30C1\u30A7\u30C3\u30AF\n   \
    \             nt = nz;\n            }\n            else{\n                if(xt_dir\
    \ != yx_dir){\n                    // x\u3092\u56DE\u8EE2\u3055\u305B\u3066xc_dir\
    \ == yx_dir\u306E\u30D1\u30BF\u30FC\u30F3\u306B\u5E30\u7740\u3055\u305B\u308B\n\
    \                    Rotate(nx, yx_dir);\n                    swap(nx, nt);\n\
    \                }\n                // z\u3092\u56DE\u8EE2\u3055\u305B\u3066x\u3068\
    z\u306E\u8272\u3092\u5909\u66F4\u3059\u308B\n                Rotate(nz, !yx_dir);\n\
    \                SetColor(nx, BLACK);\n                SetColor(nz, RED);\n  \
    \              break;\n            }\n        }\n    }\n\n    void Erase(T x){\n\
    \        // \u524A\u9664\u3059\u308B\u30CE\u30FC\u30C9\n        int nt = Search(x);\n\
    \        if(nt == SENTINEL) return;\n\n        bool removed_color;\n        if(nodes_[nt].child[LEFT]\
    \ != SENTINEL && nodes_[nt].child[RIGHT] != SENTINEL){\n            // \u30CE\u30FC\
    \u30C9t\u304C\u5B50\u30922\u500B\u6301\u3064\n            // \u30CE\u30FC\u30C9\
    t\u306E\u53F3\u306E\u5B50\u304B\u3089\u6700\u3082\u5C0F\u3055\u3044\u30CE\u30FC\
    \u30C9s\u3092\u63A2\u3059\n            int ns = nodes_[nt].child[RIGHT];\n   \
    \         while(nodes_[ns].child[LEFT] != SENTINEL){\n                ns = nodes_[ns].child[LEFT];\n\
    \            }\n            // \u3064\u3044\u3067\u306B\u3001\u305D\u306E\u4F4D\
    \u7F6E\u306B\u6765\u308B\u3053\u3068\u306B\u306A\u308B\u30CE\u30FC\u30C9x\u306E\
    \u89AA\u30CE\u30FC\u30C9p\u3092\u6301\u3063\u3066\u304A\u304F\n            int\
    \ np;\n            bool px_dir;\n            tie(np, px_dir) = GetParent(ns);\n\
    \            if(nodes_[ns].parent == nt){\n                Lift(nt);\n       \
    \         nodes_[ns].child[LEFT] = nodes_[nt].child[LEFT];\n                np\
    \ = ns;\n            }\n            else{\n                Lift(ns);\n       \
    \         Replace(nt, ns);\n            }\n            removed_color = GetColor(ns);\n\
    \            SetColor(ns, GetColor(nt));\n\n            // \u30CE\u30FC\u30C9\
    x\u304B\u3089\u9811\u5F35\u3063\u3066\u8272\u5857\u308A\u3059\u308B\n        \
    \    int nx = nodes_[np].child[px_dir];\n            UpdateSizeToRoot(np);\n \
    \           if(removed_color == BLACK){\n                Fixup(nx, np, px_dir);\n\
    \            }\n        }\n        else{\n            // \u30CE\u30FC\u30C9t\u304C\
    \u5B50\u30920or1\u500B\u6301\u3064\n            removed_color = GetColor(nt);\n\
    \            int np;\n            bool pt_dir;\n            tie(np, pt_dir) =\
    \ GetParent(nt);\n            Lift(nt);\n            int nx = nodes_[np].child[pt_dir];\n\
    \            UpdateSizeToRoot(np);\n            if(removed_color == BLACK){\n\
    \                Fixup(nx, np, pt_dir);\n            }\n        }\n    }\n\n \
    \   bool Contains(T x){\n        return Search(x) != SENTINEL;\n    }\n\n    inline\
    \ int Size(){\n        return nodes_[root_].size;\n    }\n\n    T KthElement(int\
    \ k, T e = T{}){\n        if(k > Size() || k < 1) return e;\n        int node\
    \ = root_;\n        int cum = 0;\n        while(1){\n            int lc = nodes_[nodes_[node].child[LEFT]].size;\n\
    \            if(cum + lc + 1 == k) return nodes_[node].value;\n            if(cum\
    \ + lc + 1 > k) node = nodes_[node].child[LEFT];\n            else cum += lc +\
    \ 1, node = nodes_[node].child[RIGHT];\n        }\n    }\n\n    int CountLess(T\
    \ x){\n        return CountLessImpl(x, false);\n    }\n\n    int CountLessEqual(T\
    \ x){\n        return CountLessImpl(x, true);\n    }\n\n    int CountGreater(T\
    \ x){\n        return Size() - CountLessImpl(x, true);\n    }\n\n    int CountGreaterEqual(T\
    \ x){\n        return Size() - CountLessImpl(x, false);\n    }\n\n    T MaximumLess(T\
    \ x, T inf = numeric_limits<T>::min()){\n        if(root_ == SENTINEL) return\
    \ inf;\n        int node = root_;\n        T ret = inf;\n        while(node !=\
    \ SENTINEL){\n            if(nodes_[node].value < x){\n                ret = nodes_[node].value;\n\
    \                node = nodes_[node].child[RIGHT];\n            }\n          \
    \  else{\n                node = nodes_[node].child[LEFT];\n            }\n  \
    \      }\n        return ret;\n    }\n\n    T MaximumLessEqual(T x, T inf = numeric_limits<T>::min()){\n\
    \        if(root_ == SENTINEL) return inf;\n        int node = root_;\n      \
    \  T ret = inf;\n        while(node != SENTINEL){\n            if(nodes_[node].value\
    \ <= x){\n                ret = nodes_[node].value;\n                node = nodes_[node].child[RIGHT];\n\
    \            }\n            else{\n                node = nodes_[node].child[LEFT];\n\
    \            }\n        }\n        return ret;\n    }\n\n    T MinimumGreater(T\
    \ x, T inf = numeric_limits<T>::max()){\n        if(root_ == SENTINEL) return\
    \ inf;\n        int node = root_;\n        T ret = inf;\n        while(node !=\
    \ SENTINEL){\n            if(nodes_[node].value > x){\n                ret = nodes_[node].value;\n\
    \                node = nodes_[node].child[LEFT];\n            }\n           \
    \ else{\n                node = nodes_[node].child[RIGHT];\n            }\n  \
    \      }\n        return ret;\n    }\n\n    T MinimumGreaterEqual(T x, T inf =\
    \ numeric_limits<T>::max()){\n        if(root_ == SENTINEL) return inf;\n    \
    \    int node = root_;\n        T ret = inf;\n        while(node != SENTINEL){\n\
    \            if(nodes_[node].value >= x){\n                ret = nodes_[node].value;\n\
    \                node = nodes_[node].child[LEFT];\n            }\n           \
    \ else{\n                node = nodes_[node].child[RIGHT];\n            }\n  \
    \      }\n        return ret;\n    }\n\n    private:\n    struct Node{\n     \
    \   int parent;\n        int child[2];\n        bool color;\n        T value;\n\
    \        int size;\n    };\n\n    vector<Node> nodes_;\n    int root_, next_;\n\
    \n    int CreateNode(T value, int parent){\n        int ret = next_++;\n     \
    \   Node &n = nodes_[ret];\n        n.parent = parent;\n        n.child[LEFT]\
    \ = n.child[RIGHT] = SENTINEL;\n        n.color = RED;\n        n.value = value;\n\
    \        n.size = 1;\n        return ret;\n    }\n\n    inline void UpdateSize(int\
    \ node){\n        nodes_[node].size = 1 + nodes_[nodes_[node].child[0]].size +\
    \ nodes_[nodes_[node].child[1]].size;\n    }\n\n    inline bool GetDirection(T\
    \ parent_value, T child_value){\n        if(child_value < parent_value) return\
    \ LEFT;\n        if(child_value > parent_value) return RIGHT;\n        assert(false);\n\
    \    }\n\n    pair<int, bool> GetParent(int node){\n        int parent = nodes_[node].parent;\n\
    \        return make_pair(parent, parent == SENTINEL || nodes_[parent].child[LEFT]\
    \ == node ? LEFT : RIGHT);\n    }\n\n    inline void SetParent(int node, int parent){\n\
    \        if(node){\n            nodes_[node].parent = parent;\n        }\n   \
    \ }\n\n    inline bool GetColor(int node){\n        return nodes_[node].color;\n\
    \    }\n\n    inline void SetColor(int node, bool color){\n        if(node !=\
    \ SENTINEL){\n            nodes_[node].color = color;\n        }\n    }\n\n  \
    \  void Rotate(int nx, bool direction){\n        // \u3053\u3053\u3067\u306F\u5DE6\
    \u56DE\u8EE2\u306E\u8A71\n        assert(nx != SENTINEL);\n        // \u30CE\u30FC\
    \u30C9x\u3092\u5DE6\u56DE\u8EE2 -> \u30CE\u30FC\u30C9x\u306E\u53F3\u306E\u5B50\
    (\u30CE\u30FC\u30C9y)\u3068\u306E\u89AA\u5B50\u95A2\u4FC2\u3092\u5165\u308C\u66FF\
    \u3048\u308B(\u306E\u3067\u975ENULL\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\
    )\n        int ny = nodes_[nx].child[!direction];\n        assert(ny != SENTINEL);\n\
    \        // \u30CE\u30FC\u30C9y\u306E\u5DE6\u306E\u5B50(\u30CE\u30FC\u30C9z) ->\
    \ \u30CE\u30FC\u30C9x\u306E\u53F3\u306E\u5B50\u306B\u306A\u308B\n        int nz\
    \ = nodes_[ny].child[direction];\n        // \u30CE\u30FC\u30C9x\u306E\u89AA(\u30CE\
    \u30FC\u30C9p)\n        int np; bool px_dir;\n        tie(np, px_dir) = GetParent(nx);\n\
    \n        // p\u306E\u5B50: x -> y\n        nodes_[np].child[px_dir] = ny;\n \
    \       nodes_[ny].parent = np;\n        root_ = nodes_[SENTINEL].child[LEFT];\n\
    \n        // x\u306E\u53F3\u306E\u5B50: y -> z\n        nodes_[nx].child[!direction]\
    \ = nz;\n        if(nz != SENTINEL) nodes_[nz].parent = nx;\n\n        // y\u306E\
    \u5DE6\u306E\u5B50: z -> x\n        nodes_[ny].child[direction] = nx;\n      \
    \  nodes_[nx].parent = ny;\n\n        UpdateSize(nx);\n        UpdateSize(ny);\n\
    \    }\n\n    int Search(T value){\n        int node = root_;\n        while(node\
    \ != SENTINEL){\n            if(value == nodes_[node].value) return node;\n  \
    \          if(value < nodes_[node].value) node = nodes_[node].child[LEFT];\n \
    \           else node = nodes_[node].child[RIGHT];\n        }\n        return\
    \ SENTINEL;\n    }\n\n    void Lift(int nt){\n        assert(nt);\n        int\
    \ np; bool pt_dir;\n        tie(np, pt_dir) = GetParent(nt);\n        // t\u306E\
    \u5B50\u30CE\u30FC\u30C9\u306E\u5185\u3001\u6301\u3061\u4E0A\u3052\u308B\u65B9\
    \u3092x\u3001\u305D\u306E\u307E\u307E\u306E\u65B9\u3092y\u3068\u3059\u308B\n \
    \       // \u57FA\u672C\u306Fx\u304C\u53F3\u306E\u5B50\u3060\u304C\u3001x\u304C\
    NULL\u306A\u3089y\u3068swap\u3059\u308B(\u4E21\u65B9NULL\u306E\u5834\u5408\u3082\
    \u3042\u308B\u306E\u3067\u6CE8\u610F)\n        int nx = nodes_[nt].child[RIGHT],\
    \ ny = nodes_[nt].child[LEFT];\n        if(nx == SENTINEL) swap(nx, ny);\n   \
    \     nodes_[np].child[pt_dir] = nx;\n        SetParent(nx, np);\n        SetParent(ny,\
    \ nx);\n        root_ = nodes_[SENTINEL].child[LEFT];\n    }\n\n    void Replace(int\
    \ nx, int ny){\n        // \u30CE\u30FC\u30C9x\u306E\u4F4D\u7F6E\u306B\u30CE\u30FC\
    \u30C9y\u3092\u7F6E\u63DB\u3059\u308B\n        assert(nx && ny);\n        int\
    \ np; bool px_dir;\n        tie(np, px_dir) = GetParent(nx);\n        int lc =\
    \ nodes_[nx].child[LEFT], rc = nodes_[nx].child[RIGHT];\n        nodes_[np].child[px_dir]\
    \ = nodes_[lc].parent = nodes_[rc].parent = ny;\n        nodes_[ny].parent = np;\n\
    \        nodes_[ny].child[LEFT] = lc;\n        nodes_[ny].child[RIGHT] = rc;\n\
    \        root_ = nodes_[SENTINEL].child[LEFT];\n    }\n\n    void UpdateSizeToRoot(int\
    \ node){\n        for(; node != SENTINEL; node = nodes_[node].parent){\n     \
    \       UpdateSize(node);\n        }\n    }\n\n    void Fixup(int nx, int np,\
    \ bool px_dir){\n        while(np != SENTINEL && GetColor(nx) == BLACK){\n   \
    \         // \u30CE\u30FC\u30C9y -> \u30CE\u30FC\u30C9p\u306Ex\u3067\u306F\u306A\
    \u3044\u65B9\u306E\u5B50\n            int ny = nodes_[np].child[!px_dir];\n  \
    \          assert(ny);\n            if(GetColor(ny) == RED){\n               \
    \ SetColor(np, RED);\n                SetColor(ny, BLACK);\n                Rotate(np,\
    \ px_dir);\n                ny = nodes_[np].child[!px_dir];\n            }\n \
    \           else{\n                // \u30CE\u30FC\u30C9n, f -> \u30CE\u30FC\u30C9\
    y\u306E\u5B50\u306E\u3046\u3061\u3001x\u306B\u8FD1\u3044\u65B9\u3068\u9060\u3044\
    \u65B9\n                int nn = nodes_[ny].child[px_dir], nf = nodes_[ny].child[!px_dir];\n\
    \                if(GetColor(nn) == BLACK && GetColor(nf) == BLACK){\n       \
    \             SetColor(ny, RED);\n                    nx = np;\n             \
    \       tie(np, px_dir) = GetParent(nx);\n                }\n                else{\n\
    \                    if(GetColor(nf) == BLACK){\n                        SetColor(ny,\
    \ RED);\n                        SetColor(nn, BLACK);\n                      \
    \  Rotate(ny, !px_dir);\n                        ny = nodes_[np].child[!px_dir];\n\
    \                        nf = nodes_[ny].child[!px_dir];\n                   \
    \ }\n                    SetColor(ny, GetColor(np));\n                    SetColor(np,\
    \ BLACK);\n                    SetColor(nf, BLACK);\n                    Rotate(np,\
    \ px_dir);\n                    break;\n                }\n            }\n   \
    \     }\n        SetColor(nx, BLACK);\n    }\n\n    int CountLessImpl(T x, bool\
    \ equal){\n        int cum = 0;\n        int node = root_;\n        while(node\
    \ != SENTINEL){\n            int lc = nodes_[nodes_[node].child[LEFT]].size;\n\
    \            if(x == nodes_[node].value) return cum + lc + equal;\n          \
    \  if(x < nodes_[node].value) node = nodes_[node].child[LEFT];\n            else{\n\
    \                cum += lc + 1;\n                node = nodes_[node].child[RIGHT];\n\
    \            }\n        }\n        return cum;\n    }\n};\n\n#undef LEFT\n#undef\
    \ RIGHT\n#undef SENTINEL\n#undef BLACK\n#undef RED\n"
  code: "#include \"../Common.hpp\"\n\n#define LEFT 0\n#define RIGHT 1\n#define SENTINEL\
    \ 0\n#define BLACK 0\n#define RED 1\n\ntemplate<typename T>\nclass RedBlackTree{\n\
    \    public:\n    RedBlackTree(int N = 500010){\n        nodes_.resize(N);\n \
    \       next_ = 1;\n        nodes_[SENTINEL].color = BLACK;\n        nodes_[SENTINEL].size\
    \ = 0;\n        nodes_[SENTINEL].parent = SENTINEL;\n        nodes_[SENTINEL].child[0]\
    \ = nodes_[SENTINEL].child[1] = SENTINEL;\n        root_ = SENTINEL;\n    }\n\n\
    \    void Insert(T x){\n        // \u6839\u304C\u7A7A\u306A\u3089\u6839\u306B\u633F\
    \u5165\n        if(root_ == SENTINEL){\n            root_ = CreateNode(x, SENTINEL);\n\
    \            nodes_[SENTINEL].child[0] = root_;\n            SetColor(root_, BLACK);\n\
    \            return;\n        }\n\n        // \u633F\u5165\u3059\u308B\u30CE\u30FC\
    \u30C9\n        int nt;\n\n        // \u65E2\u5B58\u304B\u306E\u30C1\u30A7\u30C3\
    \u30AF\u3068\u633F\u5165\u5834\u6240(\u3069\u306E\u30CE\u30FC\u30C9\u306E\u5B50\
    \u304B)\u306E\u63A2\u7D22\n        for(int nx = root_;;){\n            // \u65E2\
    \u5B58\u30C1\u30A7\u30C3\u30AF\n            if(nodes_[nx].value == x){\n     \
    \           return;\n            }\n\n            // \u63A2\u7D22\u65B9\u5411\u306E\
    \u53D6\u5F97\n            bool direction = GetDirection(nodes_[nx].value, x);\n\
    \            // \u63A2\u7D22\u5148\u304CNULL(x\u304C\u8449)\u306A\u3089\u3001\u305D\
    \u306E\u4F4D\u7F6E\u306B\u30CE\u30FC\u30C9\u3092\u633F\u5165\n            if(nodes_[nx].child[direction]\
    \ == SENTINEL){\n                nodes_[nx].child[direction] = CreateNode(x, nx);\n\
    \                nt = nodes_[nx].child[direction];\n                for(int target_node\
    \ = nx; target_node != SENTINEL; target_node = nodes_[target_node].parent){\n\
    \                    UpdateSize(target_node);\n                }\n           \
    \     break;\n            }\n            nx = nodes_[nx].child[direction];\n \
    \       }\n\n        // \u6574\u5408\u6027\u30C1\u30A7\u30C3\u30AF\n        while(1){\n\
    \            // \u73FE\u5728\u306E\u30CE\u30FC\u30C9\u304C\u6839\u306A\u3089\u9ED2\
    \u304F\u3057\u3066\u7D42\u308F\u308A\n            if(nodes_[nt].parent == SENTINEL){\n\
    \                SetColor(nt, BLACK);\n                return;\n            }\n\
    \n            // \u30CE\u30FC\u30C9x -> \u30CE\u30FC\u30C9t\u306E\u89AA(\u76F4\
    \u524D\u306Eif\u6587\u3088\u308Ac\u306F\u6839\u3067\u306F\u306A\u3044)\n     \
    \       int nx;\n            bool xt_dir;\n            tie(nx, xt_dir) = GetParent(nt);\n\
    \n            // \u73FE\u5728\u30CE\u30FC\u30C9\u307E\u305F\u306F\u89AA\u30CE\u30FC\
    \u30C9\u304C\u9ED2\u306A\u3089\u554F\u984C\u306A\u3057\n            if(GetColor(nt)\
    \ == BLACK || GetColor(nx) == BLACK){\n                break;\n            }\n\
    \n            // \u30CE\u30FC\u30C9z -> \u30CE\u30FC\u30C9x\u306E\u89AA(\u76F4\
    \u524D\u306Eif\u6587\u3088\u308Ax\u306F\u6839\u3067\u306F\u306A\u3044)\n     \
    \       int ny, nz;\n            bool yx_dir;\n            tie(nz, yx_dir) = GetParent(nx);\n\
    \            // \u30CE\u30FC\u30C9y -> \u30CE\u30FC\u30C9z\u306E\u5B50\u306E\u3046\
    \u3061\u3001x\u3067\u306F\u306A\u3044\u65B9(NULL\u306E\u5834\u5408\u3082\u3042\
    \u308B\u306E\u3067\u6CE8\u610F)\n            ny = nodes_[nz].child[!yx_dir];\n\
    \n            if(GetColor(ny) == RED){\n                // \u30CE\u30FC\u30C9\
    y\u304C\u8D64\u306A\u3089x,y,z\u306E\u8272\u3092\u53CD\u8EE2\n               \
    \ SetColor(nx, BLACK);\n                SetColor(ny, BLACK);\n               \
    \ SetColor(nz, RED);\n                // \u30CE\u30FC\u30C9z\u3092\u8D77\u70B9\
    \u3068\u3057\u3066\u6B21\u306E\u6574\u5408\u6027\u30C1\u30A7\u30C3\u30AF\n   \
    \             nt = nz;\n            }\n            else{\n                if(xt_dir\
    \ != yx_dir){\n                    // x\u3092\u56DE\u8EE2\u3055\u305B\u3066xc_dir\
    \ == yx_dir\u306E\u30D1\u30BF\u30FC\u30F3\u306B\u5E30\u7740\u3055\u305B\u308B\n\
    \                    Rotate(nx, yx_dir);\n                    swap(nx, nt);\n\
    \                }\n                // z\u3092\u56DE\u8EE2\u3055\u305B\u3066x\u3068\
    z\u306E\u8272\u3092\u5909\u66F4\u3059\u308B\n                Rotate(nz, !yx_dir);\n\
    \                SetColor(nx, BLACK);\n                SetColor(nz, RED);\n  \
    \              break;\n            }\n        }\n    }\n\n    void Erase(T x){\n\
    \        // \u524A\u9664\u3059\u308B\u30CE\u30FC\u30C9\n        int nt = Search(x);\n\
    \        if(nt == SENTINEL) return;\n\n        bool removed_color;\n        if(nodes_[nt].child[LEFT]\
    \ != SENTINEL && nodes_[nt].child[RIGHT] != SENTINEL){\n            // \u30CE\u30FC\
    \u30C9t\u304C\u5B50\u30922\u500B\u6301\u3064\n            // \u30CE\u30FC\u30C9\
    t\u306E\u53F3\u306E\u5B50\u304B\u3089\u6700\u3082\u5C0F\u3055\u3044\u30CE\u30FC\
    \u30C9s\u3092\u63A2\u3059\n            int ns = nodes_[nt].child[RIGHT];\n   \
    \         while(nodes_[ns].child[LEFT] != SENTINEL){\n                ns = nodes_[ns].child[LEFT];\n\
    \            }\n            // \u3064\u3044\u3067\u306B\u3001\u305D\u306E\u4F4D\
    \u7F6E\u306B\u6765\u308B\u3053\u3068\u306B\u306A\u308B\u30CE\u30FC\u30C9x\u306E\
    \u89AA\u30CE\u30FC\u30C9p\u3092\u6301\u3063\u3066\u304A\u304F\n            int\
    \ np;\n            bool px_dir;\n            tie(np, px_dir) = GetParent(ns);\n\
    \            if(nodes_[ns].parent == nt){\n                Lift(nt);\n       \
    \         nodes_[ns].child[LEFT] = nodes_[nt].child[LEFT];\n                np\
    \ = ns;\n            }\n            else{\n                Lift(ns);\n       \
    \         Replace(nt, ns);\n            }\n            removed_color = GetColor(ns);\n\
    \            SetColor(ns, GetColor(nt));\n\n            // \u30CE\u30FC\u30C9\
    x\u304B\u3089\u9811\u5F35\u3063\u3066\u8272\u5857\u308A\u3059\u308B\n        \
    \    int nx = nodes_[np].child[px_dir];\n            UpdateSizeToRoot(np);\n \
    \           if(removed_color == BLACK){\n                Fixup(nx, np, px_dir);\n\
    \            }\n        }\n        else{\n            // \u30CE\u30FC\u30C9t\u304C\
    \u5B50\u30920or1\u500B\u6301\u3064\n            removed_color = GetColor(nt);\n\
    \            int np;\n            bool pt_dir;\n            tie(np, pt_dir) =\
    \ GetParent(nt);\n            Lift(nt);\n            int nx = nodes_[np].child[pt_dir];\n\
    \            UpdateSizeToRoot(np);\n            if(removed_color == BLACK){\n\
    \                Fixup(nx, np, pt_dir);\n            }\n        }\n    }\n\n \
    \   bool Contains(T x){\n        return Search(x) != SENTINEL;\n    }\n\n    inline\
    \ int Size(){\n        return nodes_[root_].size;\n    }\n\n    T KthElement(int\
    \ k, T e = T{}){\n        if(k > Size() || k < 1) return e;\n        int node\
    \ = root_;\n        int cum = 0;\n        while(1){\n            int lc = nodes_[nodes_[node].child[LEFT]].size;\n\
    \            if(cum + lc + 1 == k) return nodes_[node].value;\n            if(cum\
    \ + lc + 1 > k) node = nodes_[node].child[LEFT];\n            else cum += lc +\
    \ 1, node = nodes_[node].child[RIGHT];\n        }\n    }\n\n    int CountLess(T\
    \ x){\n        return CountLessImpl(x, false);\n    }\n\n    int CountLessEqual(T\
    \ x){\n        return CountLessImpl(x, true);\n    }\n\n    int CountGreater(T\
    \ x){\n        return Size() - CountLessImpl(x, true);\n    }\n\n    int CountGreaterEqual(T\
    \ x){\n        return Size() - CountLessImpl(x, false);\n    }\n\n    T MaximumLess(T\
    \ x, T inf = numeric_limits<T>::min()){\n        if(root_ == SENTINEL) return\
    \ inf;\n        int node = root_;\n        T ret = inf;\n        while(node !=\
    \ SENTINEL){\n            if(nodes_[node].value < x){\n                ret = nodes_[node].value;\n\
    \                node = nodes_[node].child[RIGHT];\n            }\n          \
    \  else{\n                node = nodes_[node].child[LEFT];\n            }\n  \
    \      }\n        return ret;\n    }\n\n    T MaximumLessEqual(T x, T inf = numeric_limits<T>::min()){\n\
    \        if(root_ == SENTINEL) return inf;\n        int node = root_;\n      \
    \  T ret = inf;\n        while(node != SENTINEL){\n            if(nodes_[node].value\
    \ <= x){\n                ret = nodes_[node].value;\n                node = nodes_[node].child[RIGHT];\n\
    \            }\n            else{\n                node = nodes_[node].child[LEFT];\n\
    \            }\n        }\n        return ret;\n    }\n\n    T MinimumGreater(T\
    \ x, T inf = numeric_limits<T>::max()){\n        if(root_ == SENTINEL) return\
    \ inf;\n        int node = root_;\n        T ret = inf;\n        while(node !=\
    \ SENTINEL){\n            if(nodes_[node].value > x){\n                ret = nodes_[node].value;\n\
    \                node = nodes_[node].child[LEFT];\n            }\n           \
    \ else{\n                node = nodes_[node].child[RIGHT];\n            }\n  \
    \      }\n        return ret;\n    }\n\n    T MinimumGreaterEqual(T x, T inf =\
    \ numeric_limits<T>::max()){\n        if(root_ == SENTINEL) return inf;\n    \
    \    int node = root_;\n        T ret = inf;\n        while(node != SENTINEL){\n\
    \            if(nodes_[node].value >= x){\n                ret = nodes_[node].value;\n\
    \                node = nodes_[node].child[LEFT];\n            }\n           \
    \ else{\n                node = nodes_[node].child[RIGHT];\n            }\n  \
    \      }\n        return ret;\n    }\n\n    private:\n    struct Node{\n     \
    \   int parent;\n        int child[2];\n        bool color;\n        T value;\n\
    \        int size;\n    };\n\n    vector<Node> nodes_;\n    int root_, next_;\n\
    \n    int CreateNode(T value, int parent){\n        int ret = next_++;\n     \
    \   Node &n = nodes_[ret];\n        n.parent = parent;\n        n.child[LEFT]\
    \ = n.child[RIGHT] = SENTINEL;\n        n.color = RED;\n        n.value = value;\n\
    \        n.size = 1;\n        return ret;\n    }\n\n    inline void UpdateSize(int\
    \ node){\n        nodes_[node].size = 1 + nodes_[nodes_[node].child[0]].size +\
    \ nodes_[nodes_[node].child[1]].size;\n    }\n\n    inline bool GetDirection(T\
    \ parent_value, T child_value){\n        if(child_value < parent_value) return\
    \ LEFT;\n        if(child_value > parent_value) return RIGHT;\n        assert(false);\n\
    \    }\n\n    pair<int, bool> GetParent(int node){\n        int parent = nodes_[node].parent;\n\
    \        return make_pair(parent, parent == SENTINEL || nodes_[parent].child[LEFT]\
    \ == node ? LEFT : RIGHT);\n    }\n\n    inline void SetParent(int node, int parent){\n\
    \        if(node){\n            nodes_[node].parent = parent;\n        }\n   \
    \ }\n\n    inline bool GetColor(int node){\n        return nodes_[node].color;\n\
    \    }\n\n    inline void SetColor(int node, bool color){\n        if(node !=\
    \ SENTINEL){\n            nodes_[node].color = color;\n        }\n    }\n\n  \
    \  void Rotate(int nx, bool direction){\n        // \u3053\u3053\u3067\u306F\u5DE6\
    \u56DE\u8EE2\u306E\u8A71\n        assert(nx != SENTINEL);\n        // \u30CE\u30FC\
    \u30C9x\u3092\u5DE6\u56DE\u8EE2 -> \u30CE\u30FC\u30C9x\u306E\u53F3\u306E\u5B50\
    (\u30CE\u30FC\u30C9y)\u3068\u306E\u89AA\u5B50\u95A2\u4FC2\u3092\u5165\u308C\u66FF\
    \u3048\u308B(\u306E\u3067\u975ENULL\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\
    )\n        int ny = nodes_[nx].child[!direction];\n        assert(ny != SENTINEL);\n\
    \        // \u30CE\u30FC\u30C9y\u306E\u5DE6\u306E\u5B50(\u30CE\u30FC\u30C9z) ->\
    \ \u30CE\u30FC\u30C9x\u306E\u53F3\u306E\u5B50\u306B\u306A\u308B\n        int nz\
    \ = nodes_[ny].child[direction];\n        // \u30CE\u30FC\u30C9x\u306E\u89AA(\u30CE\
    \u30FC\u30C9p)\n        int np; bool px_dir;\n        tie(np, px_dir) = GetParent(nx);\n\
    \n        // p\u306E\u5B50: x -> y\n        nodes_[np].child[px_dir] = ny;\n \
    \       nodes_[ny].parent = np;\n        root_ = nodes_[SENTINEL].child[LEFT];\n\
    \n        // x\u306E\u53F3\u306E\u5B50: y -> z\n        nodes_[nx].child[!direction]\
    \ = nz;\n        if(nz != SENTINEL) nodes_[nz].parent = nx;\n\n        // y\u306E\
    \u5DE6\u306E\u5B50: z -> x\n        nodes_[ny].child[direction] = nx;\n      \
    \  nodes_[nx].parent = ny;\n\n        UpdateSize(nx);\n        UpdateSize(ny);\n\
    \    }\n\n    int Search(T value){\n        int node = root_;\n        while(node\
    \ != SENTINEL){\n            if(value == nodes_[node].value) return node;\n  \
    \          if(value < nodes_[node].value) node = nodes_[node].child[LEFT];\n \
    \           else node = nodes_[node].child[RIGHT];\n        }\n        return\
    \ SENTINEL;\n    }\n\n    void Lift(int nt){\n        assert(nt);\n        int\
    \ np; bool pt_dir;\n        tie(np, pt_dir) = GetParent(nt);\n        // t\u306E\
    \u5B50\u30CE\u30FC\u30C9\u306E\u5185\u3001\u6301\u3061\u4E0A\u3052\u308B\u65B9\
    \u3092x\u3001\u305D\u306E\u307E\u307E\u306E\u65B9\u3092y\u3068\u3059\u308B\n \
    \       // \u57FA\u672C\u306Fx\u304C\u53F3\u306E\u5B50\u3060\u304C\u3001x\u304C\
    NULL\u306A\u3089y\u3068swap\u3059\u308B(\u4E21\u65B9NULL\u306E\u5834\u5408\u3082\
    \u3042\u308B\u306E\u3067\u6CE8\u610F)\n        int nx = nodes_[nt].child[RIGHT],\
    \ ny = nodes_[nt].child[LEFT];\n        if(nx == SENTINEL) swap(nx, ny);\n   \
    \     nodes_[np].child[pt_dir] = nx;\n        SetParent(nx, np);\n        SetParent(ny,\
    \ nx);\n        root_ = nodes_[SENTINEL].child[LEFT];\n    }\n\n    void Replace(int\
    \ nx, int ny){\n        // \u30CE\u30FC\u30C9x\u306E\u4F4D\u7F6E\u306B\u30CE\u30FC\
    \u30C9y\u3092\u7F6E\u63DB\u3059\u308B\n        assert(nx && ny);\n        int\
    \ np; bool px_dir;\n        tie(np, px_dir) = GetParent(nx);\n        int lc =\
    \ nodes_[nx].child[LEFT], rc = nodes_[nx].child[RIGHT];\n        nodes_[np].child[px_dir]\
    \ = nodes_[lc].parent = nodes_[rc].parent = ny;\n        nodes_[ny].parent = np;\n\
    \        nodes_[ny].child[LEFT] = lc;\n        nodes_[ny].child[RIGHT] = rc;\n\
    \        root_ = nodes_[SENTINEL].child[LEFT];\n    }\n\n    void UpdateSizeToRoot(int\
    \ node){\n        for(; node != SENTINEL; node = nodes_[node].parent){\n     \
    \       UpdateSize(node);\n        }\n    }\n\n    void Fixup(int nx, int np,\
    \ bool px_dir){\n        while(np != SENTINEL && GetColor(nx) == BLACK){\n   \
    \         // \u30CE\u30FC\u30C9y -> \u30CE\u30FC\u30C9p\u306Ex\u3067\u306F\u306A\
    \u3044\u65B9\u306E\u5B50\n            int ny = nodes_[np].child[!px_dir];\n  \
    \          assert(ny);\n            if(GetColor(ny) == RED){\n               \
    \ SetColor(np, RED);\n                SetColor(ny, BLACK);\n                Rotate(np,\
    \ px_dir);\n                ny = nodes_[np].child[!px_dir];\n            }\n \
    \           else{\n                // \u30CE\u30FC\u30C9n, f -> \u30CE\u30FC\u30C9\
    y\u306E\u5B50\u306E\u3046\u3061\u3001x\u306B\u8FD1\u3044\u65B9\u3068\u9060\u3044\
    \u65B9\n                int nn = nodes_[ny].child[px_dir], nf = nodes_[ny].child[!px_dir];\n\
    \                if(GetColor(nn) == BLACK && GetColor(nf) == BLACK){\n       \
    \             SetColor(ny, RED);\n                    nx = np;\n             \
    \       tie(np, px_dir) = GetParent(nx);\n                }\n                else{\n\
    \                    if(GetColor(nf) == BLACK){\n                        SetColor(ny,\
    \ RED);\n                        SetColor(nn, BLACK);\n                      \
    \  Rotate(ny, !px_dir);\n                        ny = nodes_[np].child[!px_dir];\n\
    \                        nf = nodes_[ny].child[!px_dir];\n                   \
    \ }\n                    SetColor(ny, GetColor(np));\n                    SetColor(np,\
    \ BLACK);\n                    SetColor(nf, BLACK);\n                    Rotate(np,\
    \ px_dir);\n                    break;\n                }\n            }\n   \
    \     }\n        SetColor(nx, BLACK);\n    }\n\n    int CountLessImpl(T x, bool\
    \ equal){\n        int cum = 0;\n        int node = root_;\n        while(node\
    \ != SENTINEL){\n            int lc = nodes_[nodes_[node].child[LEFT]].size;\n\
    \            if(x == nodes_[node].value) return cum + lc + equal;\n          \
    \  if(x < nodes_[node].value) node = nodes_[node].child[LEFT];\n            else{\n\
    \                cum += lc + 1;\n                node = nodes_[node].child[RIGHT];\n\
    \            }\n        }\n        return cum;\n    }\n};\n\n#undef LEFT\n#undef\
    \ RIGHT\n#undef SENTINEL\n#undef BLACK\n#undef RED"
  dependsOn:
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/DataStructure/RedBlackTree.hpp
  requiredBy: []
  timestamp: '2026-06-22 22:44:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/DataStructure/LC-OrderedSet.test.cpp
documentation_of: Library/DataStructure/RedBlackTree.hpp
layout: document
title: "Red-Black Tree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728 (\u8D64\u9ED2\u6728\
  )"
---

# Red-Black Tree - 平衡二分探索木 (赤黒木)

集合を管理するデータ構造です。

## Function

### Constructor

```
RedBlackTree(int N = 500010)
```

- 平衡二分探索木 $S$ を初期化します。
- $N$ は集合の最大要素数です。基本的に気にする必要はありません。
- `T` は `numeric_limits` が定義されている型であることを想定しています。

**制約**

- $1 \le N \le 10^6$

---

### Insert

```
void Insert(T x)
```

- $S$ に要素 $x$ を挿入します。
- $x \in S$ の場合は何もしません。

**計算量**

- $\textrm{O}(\log N)$

---

### Erase

```
void Erase(T x)
```

- $S$ から要素 $x$ を削除します。
- $x \notin S$ の場合は何もしません。

**計算量**

- $\textrm{O}(\log N)$

---

### Contains

```
bool Contains(T x)
```

- $x \in S$ であるかを判定します。

**計算量**

- $\textrm{O}(\log N)$

---

### Size

```
int Size()
```

- 現在の $S$ の要素数を返します。

**計算量**

- $\textrm{O}(1)$

---

### KthElement

```
T KthElement(int k, T e = T{})
```

- $S$ に含まれる要素のうち $k$ 番目に小さい要素を返します。
- $k \lt 1$ または $k \gt |S|$ の場合は $e$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountLess

```
int CountLess(T x)
```

- $S$ に含まれる要素のうち $x$ **より小さい**要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountLessEqual

```
int CountLessEqual(T x)
```

- $S$ に含まれる要素のうち $x$ **以下**の要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountGreater

```
int CountGreater(T x)
```

- $S$ に含まれる要素のうち $x$ **より大きい**要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### CountGreaterEqual

```
int CountGreaterEqual(T x)
```

- $S$ に含まれる要素のうち $x$ **以上**の要素の個数を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MaximumLess(T x, T inf = numeric_limits<T>::min())

```
T MaximumLess(T x, T inf = numeric_limits<T>::min())
```

- $S$ に含まれる要素のうち $x$ **より小さい**要素のうち最大のものを返します。
- そのような要素が存在しない場合は $-\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MaximumLessEqual(T x, T inf = numeric_limits<T>::min())

```
T MaximumLessEqual(T x, T inf = numeric_limits<T>::min())
```

- $S$ に含まれる要素のうち $x$ **以下**の要素のうち最大のものを返します。
- そのような要素が存在しない場合は $-\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MinimumGreater(T x, T inf = numeric_limits<T>::max())

```
T MinimumGreater(T x, T inf = numeric_limits<T>::max())
```

- $S$ に含まれる要素のうち $x$ **より大きい**要素のうち最小のものを返します。
- そのような要素が存在しない場合は $\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---

### MinimumGreaterEqual(T x, T inf = numeric_limits<T>::max())

```
T MinimumGreaterEqual(T x, T inf = numeric_limits<T>::max())
```

- $S$ に含まれる要素のうち $x$ **以上**の要素のうち最小のものを返します。
- そのような要素が存在しない場合は $\infty$ を返します。

**計算量**

- $\textrm{O}(\log N)$

---
