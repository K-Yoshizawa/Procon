---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Matrix - \u884C\u5217\u6F14\u7B97"
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/Matrix.hpp\"\n/**\n * @file Matrix.hpp\n\
    \ * @author log K (lX57)\n * @brief Matrix - \u884C\u5217\u6F14\u7B97\n * @version\
    \ 1.0\n * @date 2023-10-11\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T>\nusing mat = vector<vector<T>>;\n\ntemplate<typename T>\n\
    struct Matrix{\n    public:\n    mat<T> A;\n\n    Matrix(){}\n    Matrix(int N,\
    \ int M) : A(N, vector<T>(M, 0)){}\n    Matrix(int N) : A(N, vector<T>(N, 0)){}\n\
    \    Matrix(mat<T> &Data) : A(Data){}\n\n    size_t height() const {return A.size();}\n\
    \    size_t width() const {return A[0].size();}\n    size_t size() const {assert(height()\
    \ == width()); return height();}\n\n    vector<T> const &operator[](int k) const{\n\
    \        return (A.at(k));\n    }\n\n    vector<T> &operator[](int k){\n     \
    \   return (A.at(k));\n    }\n\n    Matrix<T> &operator+=(const Matrix<T> &R){\n\
    \        int N = height(), M = width();\n        assert(N == R.height() && M ==\
    \ R.width());\n        for(int i = 0; i < N; ++i)\n            for(int j = 0;\
    \ j < M; ++j)\n                (*this)[i][j] += R[i][j];\n        return (*this);\n\
    \    }\n    \n    Matrix<T> &operator-=(const Matrix<T> &R){\n        int N =\
    \ height(), M = width();\n        assert(N == R.height() && M == R.width());\n\
    \        for(int i = 0; i < N; ++i)\n            for(int j = 0; j < M; ++j)\n\
    \                (*this)[i][j] -= R[i][j];\n        return (*this);\n    }\n \
    \   \n    Matrix<T> &operator*=(const Matrix<T> &R){\n        int N = height(),\
    \ M = R.width(), L = width();\n        assert(L == R.height());\n        mat<T>\
    \ tmp(N, vector<T>(M, 0));\n        for(int i = 0; i < N; ++i)\n            for(int\
    \ j = 0; j < M; ++j)\n                for(int k = 0; k < L; ++k)\n           \
    \         tmp[i][j] += (*this)[i][k] * R[k][j];\n        A.swap(tmp);\n      \
    \  return (*this);\n    }\n\n    Matrix<T> operator*(const Matrix<T> &R){\n  \
    \      return (Matrix(*this) *= R);\n    }\n\n    Matrix<T> &operator^=(const\
    \ long long p){\n        long long q = p;\n        auto ret = Matrix<T>::I(size());\n\
    \        auto B(*this);\n        while(q){\n            if(q & 1){\n         \
    \       ret *= B;\n            }\n            B *= B;\n            q >>= 1;\n\
    \        }\n        A = (mat<T>)ret;\n        return (*this);\n    }\n\n    Matrix<T>\
    \ operator^(const long long p){\n        return (Matrix<T>(*this) ^= p);\n   \
    \ }\n\n    operator mat<T>() const{\n        return A;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, Matrix<T> &p){\n        for(int i = 0; i < p.height();\
    \ ++i){\n            for(int j = 0; j < p.width(); ++j){\n                is >>\
    \ p[i][j];\n            }\n        }\n        return (is);\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, Matrix &p){\n        int N = p.height(), M\
    \ = p.width();\n        for(int i = 0; i < N; ++i){\n            for(int j = 0;\
    \ j < M; ++j){\n                os << p[i][j] << (j + 1 == M ? \"\" : \" \");\n\
    \            }\n            os << (i + 1 == N ? \"\" : \"\\n\");\n        }\n\
    \        return (os);\n    }\n\n    void print(){\n        int N = height(), M\
    \ = width();\n        cerr << \"Matrix ===============================\\n\";\n\
    \        for(int i = 0; i < N; ++i){\n            cerr << \"[\";\n           \
    \ for(int j = 0; j < M; ++j){\n                cerr << A[i][j] << \" ]\"[j + 1\
    \ == M];\n            }\n            cerr << '\\n';\n        }\n    }\n\n    T\
    \ det() const {\n        Matrix<T> tmp(*this);\n        T ret = 1;\n        int\
    \ N = size();\n        int i = 0;\n        for(int j = 0; i < N && j < N; ++j){\n\
    \            // cerr << \"i = \" << i << \", j = \" << j << '\\n';\n         \
    \   // tmp.print();\n            bool found = false;\n            for(int ti =\
    \ i; ti < N && !found; ++ti){\n                // cerr << \" - ti = \" << ti <<\
    \ \", val = \" << tmp[ti][j] << '\\n';\n                if(tmp[ti][j] != 0){\n\
    \                    if(ti != i){\n                        swap(tmp[ti], tmp[i]);\n\
    \                        ret *= -1;\n                    }\n                 \
    \   // cerr << \" -  - OK\\n\";\n                    found = true;\n         \
    \       }\n            }\n            if(!found) return 0;\n            // tmp.print();\n\
    \            for(int ti = i + 1; ti < N; ++ti){\n                if(tmp[ti][j]\
    \ == 0) continue;\n                T mul = tmp[ti][j] / tmp[i][j];\n         \
    \       // cerr << \" - ti = \" << ti << \", mul = \" << mul << '\\n';\n     \
    \           for(int tj = j; tj < N; ++tj){\n                    // cerr << \"\
    \ -  - tj = \" << tj << \", sub = \" << tmp[i][tj] << \" * \" << mul << \" = \"\
    \ << tmp[i][tj] * mul << '\\n';\n                    tmp[ti][tj] -= tmp[i][tj]\
    \ * mul;\n                }\n            }\n            ++i;\n        }\n    \
    \    for(int i = 0; i < N; ++i) ret *= tmp[i][i];\n        return ret;\n    }\n\
    \n    bool isRegular() const {\n        return (det() != 0);\n    }\n\n    static\
    \ Matrix<T> I(size_t N){\n        Matrix<T> ret(N);\n        for(int i = 0; i\
    \ < N; ++i) ret[i][i] = 1;\n        return (ret);\n    }\n\n    static Matrix<T>\
    \ inv(const Matrix<T> &M){\n        assert(M.isRegular());\n        Matrix<T>\
    \ tmp(M), ret = Matrix<T>::I(M.size());\n        int N = M.size();\n        int\
    \ i = 0;\n        for(int j = 0; i < N && j < N; ++j){\n            bool found\
    \ = false;\n            for(int ti = i; ti < N && !found; ++ti){\n           \
    \     if(tmp[ti][j] != 0){\n                    if(ti != i){\n               \
    \         swap(tmp[ti], tmp[i]);\n                        swap(ret[ti], ret[i]);\n\
    \                    }\n                    found = true;\n                }\n\
    \            }\n            T div = tmp[i][j];\n            for(int tj = 0; tj\
    \ < N; ++tj) tmp[i][tj] /= div, ret[i][tj] /= div;\n            for(int ti = 0;\
    \ ti < N; ++ti){\n                if(ti == i || tmp[ti][j] == 0) continue;\n \
    \               T mul = tmp[ti][j];\n                for(int tj = 0; tj < N; ++tj){\n\
    \                    tmp[ti][tj] -= tmp[i][tj] * mul;\n                    ret[ti][tj]\
    \ -= ret[i][tj] * mul;\n                }\n            }\n            ++i;\n \
    \       }\n        return ret;\n    }\n};\n"
  code: "/**\n * @file Matrix.hpp\n * @author log K (lX57)\n * @brief Matrix - \u884C\
    \u5217\u6F14\u7B97\n * @version 1.0\n * @date 2023-10-11\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nusing mat = vector<vector<T>>;\n\
    \ntemplate<typename T>\nstruct Matrix{\n    public:\n    mat<T> A;\n\n    Matrix(){}\n\
    \    Matrix(int N, int M) : A(N, vector<T>(M, 0)){}\n    Matrix(int N) : A(N,\
    \ vector<T>(N, 0)){}\n    Matrix(mat<T> &Data) : A(Data){}\n\n    size_t height()\
    \ const {return A.size();}\n    size_t width() const {return A[0].size();}\n \
    \   size_t size() const {assert(height() == width()); return height();}\n\n  \
    \  vector<T> const &operator[](int k) const{\n        return (A.at(k));\n    }\n\
    \n    vector<T> &operator[](int k){\n        return (A.at(k));\n    }\n\n    Matrix<T>\
    \ &operator+=(const Matrix<T> &R){\n        int N = height(), M = width();\n \
    \       assert(N == R.height() && M == R.width());\n        for(int i = 0; i <\
    \ N; ++i)\n            for(int j = 0; j < M; ++j)\n                (*this)[i][j]\
    \ += R[i][j];\n        return (*this);\n    }\n    \n    Matrix<T> &operator-=(const\
    \ Matrix<T> &R){\n        int N = height(), M = width();\n        assert(N ==\
    \ R.height() && M == R.width());\n        for(int i = 0; i < N; ++i)\n       \
    \     for(int j = 0; j < M; ++j)\n                (*this)[i][j] -= R[i][j];\n\
    \        return (*this);\n    }\n    \n    Matrix<T> &operator*=(const Matrix<T>\
    \ &R){\n        int N = height(), M = R.width(), L = width();\n        assert(L\
    \ == R.height());\n        mat<T> tmp(N, vector<T>(M, 0));\n        for(int i\
    \ = 0; i < N; ++i)\n            for(int j = 0; j < M; ++j)\n                for(int\
    \ k = 0; k < L; ++k)\n                    tmp[i][j] += (*this)[i][k] * R[k][j];\n\
    \        A.swap(tmp);\n        return (*this);\n    }\n\n    Matrix<T> operator*(const\
    \ Matrix<T> &R){\n        return (Matrix(*this) *= R);\n    }\n\n    Matrix<T>\
    \ &operator^=(const long long p){\n        long long q = p;\n        auto ret\
    \ = Matrix<T>::I(size());\n        auto B(*this);\n        while(q){\n       \
    \     if(q & 1){\n                ret *= B;\n            }\n            B *= B;\n\
    \            q >>= 1;\n        }\n        A = (mat<T>)ret;\n        return (*this);\n\
    \    }\n\n    Matrix<T> operator^(const long long p){\n        return (Matrix<T>(*this)\
    \ ^= p);\n    }\n\n    operator mat<T>() const{\n        return A;\n    }\n\n\
    \    friend istream &operator>>(istream &is, Matrix<T> &p){\n        for(int i\
    \ = 0; i < p.height(); ++i){\n            for(int j = 0; j < p.width(); ++j){\n\
    \                is >> p[i][j];\n            }\n        }\n        return (is);\n\
    \    }\n\n    friend ostream &operator<<(ostream &os, Matrix &p){\n        int\
    \ N = p.height(), M = p.width();\n        for(int i = 0; i < N; ++i){\n      \
    \      for(int j = 0; j < M; ++j){\n                os << p[i][j] << (j + 1 ==\
    \ M ? \"\" : \" \");\n            }\n            os << (i + 1 == N ? \"\" : \"\
    \\n\");\n        }\n        return (os);\n    }\n\n    void print(){\n       \
    \ int N = height(), M = width();\n        cerr << \"Matrix ===============================\\\
    n\";\n        for(int i = 0; i < N; ++i){\n            cerr << \"[\";\n      \
    \      for(int j = 0; j < M; ++j){\n                cerr << A[i][j] << \" ]\"\
    [j + 1 == M];\n            }\n            cerr << '\\n';\n        }\n    }\n\n\
    \    T det() const {\n        Matrix<T> tmp(*this);\n        T ret = 1;\n    \
    \    int N = size();\n        int i = 0;\n        for(int j = 0; i < N && j <\
    \ N; ++j){\n            // cerr << \"i = \" << i << \", j = \" << j << '\\n';\n\
    \            // tmp.print();\n            bool found = false;\n            for(int\
    \ ti = i; ti < N && !found; ++ti){\n                // cerr << \" - ti = \" <<\
    \ ti << \", val = \" << tmp[ti][j] << '\\n';\n                if(tmp[ti][j] !=\
    \ 0){\n                    if(ti != i){\n                        swap(tmp[ti],\
    \ tmp[i]);\n                        ret *= -1;\n                    }\n      \
    \              // cerr << \" -  - OK\\n\";\n                    found = true;\n\
    \                }\n            }\n            if(!found) return 0;\n        \
    \    // tmp.print();\n            for(int ti = i + 1; ti < N; ++ti){\n       \
    \         if(tmp[ti][j] == 0) continue;\n                T mul = tmp[ti][j] /\
    \ tmp[i][j];\n                // cerr << \" - ti = \" << ti << \", mul = \" <<\
    \ mul << '\\n';\n                for(int tj = j; tj < N; ++tj){\n            \
    \        // cerr << \" -  - tj = \" << tj << \", sub = \" << tmp[i][tj] << \"\
    \ * \" << mul << \" = \" << tmp[i][tj] * mul << '\\n';\n                    tmp[ti][tj]\
    \ -= tmp[i][tj] * mul;\n                }\n            }\n            ++i;\n \
    \       }\n        for(int i = 0; i < N; ++i) ret *= tmp[i][i];\n        return\
    \ ret;\n    }\n\n    bool isRegular() const {\n        return (det() != 0);\n\
    \    }\n\n    static Matrix<T> I(size_t N){\n        Matrix<T> ret(N);\n     \
    \   for(int i = 0; i < N; ++i) ret[i][i] = 1;\n        return (ret);\n    }\n\n\
    \    static Matrix<T> inv(const Matrix<T> &M){\n        assert(M.isRegular());\n\
    \        Matrix<T> tmp(M), ret = Matrix<T>::I(M.size());\n        int N = M.size();\n\
    \        int i = 0;\n        for(int j = 0; i < N && j < N; ++j){\n          \
    \  bool found = false;\n            for(int ti = i; ti < N && !found; ++ti){\n\
    \                if(tmp[ti][j] != 0){\n                    if(ti != i){\n    \
    \                    swap(tmp[ti], tmp[i]);\n                        swap(ret[ti],\
    \ ret[i]);\n                    }\n                    found = true;\n       \
    \         }\n            }\n            T div = tmp[i][j];\n            for(int\
    \ tj = 0; tj < N; ++tj) tmp[i][tj] /= div, ret[i][tj] /= div;\n            for(int\
    \ ti = 0; ti < N; ++ti){\n                if(ti == i || tmp[ti][j] == 0) continue;\n\
    \                T mul = tmp[ti][j];\n                for(int tj = 0; tj < N;\
    \ ++tj){\n                    tmp[ti][tj] -= tmp[i][tj] * mul;\n             \
    \       ret[ti][tj] -= ret[i][tj] * mul;\n                }\n            }\n \
    \           ++i;\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/Matrix.hpp
  requiredBy: []
  timestamp: '2025-05-30 19:43:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/Matrix.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/Matrix.hpp
- /library/Library/unauthenticated/Matrix.hpp.html
title: "Matrix - \u884C\u5217\u6F14\u7B97"
---
