---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: icpc/BellmanFord.hpp
    title: icpc/BellmanFord.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/Combination.hpp
    title: icpc/Combination.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/Dijkstra.hpp
    title: icpc/Dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/Dinic.hpp
    title: icpc/Dinic.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/DualSegmentTree.hpp
    title: icpc/DualSegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/HeavyLightDecomposition.hpp
    title: icpc/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/LazySegmentTree.hpp
    title: icpc/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/ModInt.hpp
    title: icpc/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/PrimalDual.hpp
    title: icpc/PrimalDual.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/SegmentTree.hpp
    title: icpc/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/StronglyConnectedComponents.hpp
    title: icpc/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/UnionFind.hpp
    title: icpc/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/WarshallFloyd.hpp
    title: icpc/WarshallFloyd.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-A.test.cpp
    title: verify_icpc/AOJ-DPL-5-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-B.test.cpp
    title: verify_icpc/AOJ-DPL-5-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-D.test.cpp
    title: verify_icpc/AOJ-DPL-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DPL-5-E.test.cpp
    title: verify_icpc/AOJ-DPL-5-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-1-A.test.cpp
    title: verify_icpc/AOJ-DSL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-2-A.test.cpp
    title: verify_icpc/AOJ-DSL-2-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-2-D.test.cpp
    title: verify_icpc/AOJ-DSL-2-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-DSL-2-F.test.cpp
    title: verify_icpc/AOJ-DSL-2-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-1-A.test.cpp
    title: verify_icpc/AOJ-GRL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-1-B.test.cpp
    title: verify_icpc/AOJ-GRL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-1-C.test.cpp
    title: verify_icpc/AOJ-GRL-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-3-C.test.cpp
    title: verify_icpc/AOJ-GRL-3-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-5-C.test.cpp
    title: verify_icpc/AOJ-GRL-5-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-5-D.test.cpp
    title: verify_icpc/AOJ-GRL-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-5-E.test.cpp
    title: verify_icpc/AOJ-GRL-5-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-6-A.test.cpp
    title: verify_icpc/AOJ-GRL-6-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_icpc/AOJ-GRL-6-B.test.cpp
    title: verify_icpc/AOJ-GRL-6-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "icpc/Template.hpp"


    #include <bits/stdc++.h>

    using namespace std;


    using ll = long long;

    using vi = vector<int>;

    using vl = vector<ll>;

    using vvi = vector<vi>;

    using vvl = vector<vl>;

    using pi = pair<int, int>;

    '
  code: '#pragma once


    #include <bits/stdc++.h>

    using namespace std;


    using ll = long long;

    using vi = vector<int>;

    using vl = vector<ll>;

    using vvi = vector<vi>;

    using vvl = vector<vl>;

    using pi = pair<int, int>;'
  dependsOn: []
  isVerificationFile: false
  path: icpc/Template.hpp
  requiredBy:
  - icpc/BellmanFord.hpp
  - icpc/Dijkstra.hpp
  - icpc/PrimalDual.hpp
  - icpc/Dinic.hpp
  - icpc/UnionFind.hpp
  - icpc/ModInt.hpp
  - icpc/SegmentTree.hpp
  - icpc/LazySegmentTree.hpp
  - icpc/StronglyConnectedComponents.hpp
  - icpc/Combination.hpp
  - icpc/HeavyLightDecomposition.hpp
  - icpc/DualSegmentTree.hpp
  - icpc/WarshallFloyd.hpp
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_icpc/AOJ-DSL-2-F.test.cpp
  - verify_icpc/AOJ-GRL-1-B.test.cpp
  - verify_icpc/AOJ-DPL-5-B.test.cpp
  - verify_icpc/AOJ-GRL-1-C.test.cpp
  - verify_icpc/AOJ-GRL-5-D.test.cpp
  - verify_icpc/AOJ-GRL-5-E.test.cpp
  - verify_icpc/AOJ-DPL-5-A.test.cpp
  - verify_icpc/AOJ-DSL-2-A.test.cpp
  - verify_icpc/AOJ-GRL-5-C.test.cpp
  - verify_icpc/AOJ-GRL-6-B.test.cpp
  - verify_icpc/AOJ-DSL-1-A.test.cpp
  - verify_icpc/AOJ-DPL-5-E.test.cpp
  - verify_icpc/AOJ-DSL-2-D.test.cpp
  - verify_icpc/AOJ-DPL-5-D.test.cpp
  - verify_icpc/AOJ-GRL-3-C.test.cpp
  - verify_icpc/AOJ-GRL-1-A.test.cpp
  - verify_icpc/AOJ-GRL-6-A.test.cpp
documentation_of: icpc/Template.hpp
layout: document
redirect_from:
- /library/icpc/Template.hpp
- /library/icpc/Template.hpp.html
title: icpc/Template.hpp
---
