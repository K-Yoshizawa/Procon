#!/bin/bash

oj-bundle code.cpp > submit.cpp
g++ submit.cpp -std=c++17 -O2 -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o answer.exe
