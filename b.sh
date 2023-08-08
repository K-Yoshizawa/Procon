#!/bin/bash

new_atcoder(){
    oj-bundle code.cpp > submit.cpp
    g++ submit.cpp -std=gnu++2a -O2 -Wall -Wextra \
        -mtune=native -march=native -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
        -I/opt/ac-library -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o a.out -lgmpxx -lgmp \
        -I/usr/include/eigen3
}

atcoder(){
    oj-bundle code.cpp > submit.cpp
    g++ submit.cpp -std=gnu++17 -O2 -Wall -Wextra \
        -I/opt/ac-library -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o a.out
}

codeforces(){
    oj-bundle code.cpp > submit.cpp
    g++ submit.cpp -std=c++17 -O2 -o a.out
}

if [ $1 = "na" ]; then
    new_atcoder
elif [ $1 = "a" ]; then
    atcoder
elif [ $1 = "c" ]; then
    codeforces
elif [ $1 = "t" ]; then
    if [ $# = 1 ]; then
        ./a.out
    elif [ $2 = "id" ]; then
        ./a.out < in.txt
    elif [ $2 = "i" ]; then
        ./a.out < in.txt 2> deb.txt
    fi
fi
