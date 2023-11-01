---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LC-DeterminantofMatrix.test.cpp
    title: verify/LC-DeterminantofMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-InverseMatrix.test.cpp
    title: verify/LC-InverseMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-MatrixProduct.test.cpp
    title: verify/LC-MatrixProduct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Matrix - \u884C\u5217\u6F14\u7B97"
    links: []
  bundledCode: "#line 1 \"library/Math/Matrix.hpp\"\n/**\n * @file Matrix.hpp\n *\
    \ @author log K (lX57)\n * @brief Matrix - \u884C\u5217\u6F14\u7B97\n * @version\
    \ 1.0\n * @date 2023-10-11\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct Matrix{\n    public:\n    vector<vector<T>> A;\n\
    \n    Matrix(){}\n    Matrix(int N, int M) : A(N, vector<T>(M, 0)){}\n    Matrix(int\
    \ N) : A(N, vector<T>(N, 0)){}\n    Matrix(vector<vector<T>> &Data) : A(Data){}\n\
    \n    size_t Height() const {return A.size();}\n    size_t Width() const {return\
    \ A[0].size();}\n    size_t Size() const {assert(Height() == Width()); return\
    \ Height();}\n\n    vector<T> const &operator[](int k) const{\n        return\
    \ (A.at(k));\n    }\n\n    vector<T> &operator[](int k){\n        return (A.at(k));\n\
    \    }\n\n    Matrix<T> &operator+=(const Matrix<T> &R){\n        int N = Height(),\
    \ M = Width();\n        assert(N == R.Height() && M == R.Width());\n        for(int\
    \ i = 0; i < N; ++i)\n            for(int j = 0; j < M; ++j)\n               \
    \ (*this)[i][j] += R[i][j];\n        return (*this);\n    }\n    \n    Matrix<T>\
    \ &operator-=(const Matrix<T> &R){\n        int N = Height(), M = Width();\n \
    \       assert(N == R.Height() && M == R.Width());\n        for(int i = 0; i <\
    \ N; ++i)\n            for(int j = 0; j < M; ++j)\n                (*this)[i][j]\
    \ -= R[i][j];\n        return (*this);\n    }\n    \n    Matrix<T> &operator*=(const\
    \ Matrix<T> &R){\n        int N = Height(), M = R.Width(), L = Width();\n    \
    \    assert(L == R.Height());\n        vector<vector<T>> tmp(N, vector<T>(M, 0));\n\
    \        for(int i = 0; i < N; ++i)\n            for(int j = 0; j < M; ++j)\n\
    \                for(int k = 0; k < L; ++k)\n                    tmp[i][j] +=\
    \ (*this)[i][k] * R[k][j];\n        A.swap(tmp);\n        return (*this);\n  \
    \  }\n\n    Matrix<T> operator*(const Matrix<T> &R){\n        return (Matrix(*this)\
    \ *= R);\n    }\n\n    friend ostream &operator<<(ostream &os, Matrix &p){\n \
    \       int N = p.Height(), M = p.Width();\n        for(int i = 0; i < N; ++i){\n\
    \            for(int j = 0; j < M; ++j){\n                os << p[i][j] << (j\
    \ + 1 == M ? \"\" : \" \");\n            }\n            os << (i + 1 == N ? \"\
    \" : \"\\n\");\n        }\n        return (os);\n    }\n\n    void print(){\n\
    \        int N = Height(), M = Width();\n        cerr << \"Matrix ===============================\\\
    n\";\n        for(int i = 0; i < N; ++i){\n            cerr << \"[\";\n      \
    \      for(int j = 0; j < M; ++j){\n                cerr << A[i][j] << \" ]\"\
    [j + 1 == M];\n            }\n            cerr << endl;\n        }\n    }\n\n\
    \    T det() const {\n        Matrix<T> tmp(*this);\n        T ret = 1;\n    \
    \    int N = Size();\n        int i = 0;\n        for(int j = 0; i < N && j <\
    \ N; ++j){\n            // cerr << \"i = \" << i << \", j = \" << j << endl;\n\
    \            // tmp.print();\n            bool found = false;\n            for(int\
    \ ti = i; ti < N && !found; ++ti){\n                // cerr << \" - ti = \" <<\
    \ ti << \", val = \" << tmp[ti][j] << endl;\n                if(tmp[ti][j] !=\
    \ 0){\n                    if(ti != i){\n                        swap(tmp[ti],\
    \ tmp[i]);\n                        ret *= -1;\n                    }\n      \
    \              // cerr << \" -  - OK\\n\";\n                    found = true;\n\
    \                }\n            }\n            if(!found) return 0;\n        \
    \    // tmp.print();\n            for(int ti = i + 1; ti < N; ++ti){\n       \
    \         if(tmp[ti][j] == 0) continue;\n                T mul = tmp[ti][j] /\
    \ tmp[i][j];\n                // cerr << \" - ti = \" << ti << \", mul = \" <<\
    \ mul << endl;\n                for(int tj = j; tj < N; ++tj){\n             \
    \       // cerr << \" -  - tj = \" << tj << \", sub = \" << tmp[i][tj] << \" *\
    \ \" << mul << \" = \" << tmp[i][tj] * mul << endl;\n                    tmp[ti][tj]\
    \ -= tmp[i][tj] * mul;\n                }\n            }\n            ++i;\n \
    \       }\n        for(int i = 0; i < N; ++i) ret *= tmp[i][i];\n        return\
    \ ret;\n    }\n\n    bool isRegular() const {\n        return (det() != 0);\n\
    \    }\n\n    static Matrix<T> I(size_t N){\n        Matrix<T> ret(N);\n     \
    \   for(int i = 0; i < N; ++i) ret[i][i] = 1;\n        return (ret);\n    }\n\n\
    \    static Matrix<T> inv(const Matrix<T> &M){\n        assert(M.isRegular());\n\
    \        Matrix<T> tmp(M), ret = Matrix<T>::I(M.Size());\n        int N = M.Size();\n\
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
    \           ++i;\n        }\n        return ret;\n    }\n};\n"
  code: "/**\n * @file Matrix.hpp\n * @author log K (lX57)\n * @brief Matrix - \u884C\
    \u5217\u6F14\u7B97\n * @version 1.0\n * @date 2023-10-11\n */\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct Matrix{\n    public:\n  \
    \  vector<vector<T>> A;\n\n    Matrix(){}\n    Matrix(int N, int M) : A(N, vector<T>(M,\
    \ 0)){}\n    Matrix(int N) : A(N, vector<T>(N, 0)){}\n    Matrix(vector<vector<T>>\
    \ &Data) : A(Data){}\n\n    size_t Height() const {return A.size();}\n    size_t\
    \ Width() const {return A[0].size();}\n    size_t Size() const {assert(Height()\
    \ == Width()); return Height();}\n\n    vector<T> const &operator[](int k) const{\n\
    \        return (A.at(k));\n    }\n\n    vector<T> &operator[](int k){\n     \
    \   return (A.at(k));\n    }\n\n    Matrix<T> &operator+=(const Matrix<T> &R){\n\
    \        int N = Height(), M = Width();\n        assert(N == R.Height() && M ==\
    \ R.Width());\n        for(int i = 0; i < N; ++i)\n            for(int j = 0;\
    \ j < M; ++j)\n                (*this)[i][j] += R[i][j];\n        return (*this);\n\
    \    }\n    \n    Matrix<T> &operator-=(const Matrix<T> &R){\n        int N =\
    \ Height(), M = Width();\n        assert(N == R.Height() && M == R.Width());\n\
    \        for(int i = 0; i < N; ++i)\n            for(int j = 0; j < M; ++j)\n\
    \                (*this)[i][j] -= R[i][j];\n        return (*this);\n    }\n \
    \   \n    Matrix<T> &operator*=(const Matrix<T> &R){\n        int N = Height(),\
    \ M = R.Width(), L = Width();\n        assert(L == R.Height());\n        vector<vector<T>>\
    \ tmp(N, vector<T>(M, 0));\n        for(int i = 0; i < N; ++i)\n            for(int\
    \ j = 0; j < M; ++j)\n                for(int k = 0; k < L; ++k)\n           \
    \         tmp[i][j] += (*this)[i][k] * R[k][j];\n        A.swap(tmp);\n      \
    \  return (*this);\n    }\n\n    Matrix<T> operator*(const Matrix<T> &R){\n  \
    \      return (Matrix(*this) *= R);\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p){\n        int N = p.Height(), M = p.Width();\n        for(int\
    \ i = 0; i < N; ++i){\n            for(int j = 0; j < M; ++j){\n             \
    \   os << p[i][j] << (j + 1 == M ? \"\" : \" \");\n            }\n           \
    \ os << (i + 1 == N ? \"\" : \"\\n\");\n        }\n        return (os);\n    }\n\
    \n    void print(){\n        int N = Height(), M = Width();\n        cerr << \"\
    Matrix ===============================\\n\";\n        for(int i = 0; i < N; ++i){\n\
    \            cerr << \"[\";\n            for(int j = 0; j < M; ++j){\n       \
    \         cerr << A[i][j] << \" ]\"[j + 1 == M];\n            }\n            cerr\
    \ << endl;\n        }\n    }\n\n    T det() const {\n        Matrix<T> tmp(*this);\n\
    \        T ret = 1;\n        int N = Size();\n        int i = 0;\n        for(int\
    \ j = 0; i < N && j < N; ++j){\n            // cerr << \"i = \" << i << \", j\
    \ = \" << j << endl;\n            // tmp.print();\n            bool found = false;\n\
    \            for(int ti = i; ti < N && !found; ++ti){\n                // cerr\
    \ << \" - ti = \" << ti << \", val = \" << tmp[ti][j] << endl;\n             \
    \   if(tmp[ti][j] != 0){\n                    if(ti != i){\n                 \
    \       swap(tmp[ti], tmp[i]);\n                        ret *= -1;\n         \
    \           }\n                    // cerr << \" -  - OK\\n\";\n             \
    \       found = true;\n                }\n            }\n            if(!found)\
    \ return 0;\n            // tmp.print();\n            for(int ti = i + 1; ti <\
    \ N; ++ti){\n                if(tmp[ti][j] == 0) continue;\n                T\
    \ mul = tmp[ti][j] / tmp[i][j];\n                // cerr << \" - ti = \" << ti\
    \ << \", mul = \" << mul << endl;\n                for(int tj = j; tj < N; ++tj){\n\
    \                    // cerr << \" -  - tj = \" << tj << \", sub = \" << tmp[i][tj]\
    \ << \" * \" << mul << \" = \" << tmp[i][tj] * mul << endl;\n                \
    \    tmp[ti][tj] -= tmp[i][tj] * mul;\n                }\n            }\n    \
    \        ++i;\n        }\n        for(int i = 0; i < N; ++i) ret *= tmp[i][i];\n\
    \        return ret;\n    }\n\n    bool isRegular() const {\n        return (det()\
    \ != 0);\n    }\n\n    static Matrix<T> I(size_t N){\n        Matrix<T> ret(N);\n\
    \        for(int i = 0; i < N; ++i) ret[i][i] = 1;\n        return (ret);\n  \
    \  }\n\n    static Matrix<T> inv(const Matrix<T> &M){\n        assert(M.isRegular());\n\
    \        Matrix<T> tmp(M), ret = Matrix<T>::I(M.Size());\n        int N = M.Size();\n\
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
  path: library/Math/Matrix.hpp
  requiredBy: []
  timestamp: '2023-10-11 01:51:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-MatrixProduct.test.cpp
  - verify/LC-DeterminantofMatrix.test.cpp
  - verify/LC-InverseMatrix.test.cpp
documentation_of: library/Math/Matrix.hpp
layout: document
redirect_from:
- /library/library/Math/Matrix.hpp
- /library/library/Math/Matrix.hpp.html
title: "Matrix - \u884C\u5217\u6F14\u7B97"
---
