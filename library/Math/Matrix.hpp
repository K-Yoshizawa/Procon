/**
 * @file Matrix.hpp
 * @author log K (lX57)
 * @brief Matrix - 行列演算
 * @version 1.0
 * @date 2023-10-11
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Matrix{
    public:
    vector<vector<T>> A;

    Matrix(){}
    Matrix(int N, int M) : A(N, vector<T>(M, 0)){}
    Matrix(int N) : A(N, vector<T>(N, 0)){}
    Matrix(vector<vector<T>> &Data) : A(Data){}

    size_t Height() const {return A.size();}
    size_t Width() const {return A[0].size();}
    size_t Size() const {assert(Height() == Width()); return Height();}

    vector<T> const &operator[](int k) const{
        return (A.at(k));
    }

    vector<T> &operator[](int k){
        return (A.at(k));
    }

    Matrix<T> &operator+=(const Matrix<T> &R){
        int N = Height(), M = Width();
        assert(N == R.Height() && M == R.Width());
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                (*this)[i][j] += R[i][j];
        return (*this);
    }
    
    Matrix<T> &operator-=(const Matrix<T> &R){
        int N = Height(), M = Width();
        assert(N == R.Height() && M == R.Width());
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                (*this)[i][j] -= R[i][j];
        return (*this);
    }
    
    Matrix<T> &operator*=(const Matrix<T> &R){
        int N = Height(), M = R.Width(), L = Width();
        assert(L == R.Height());
        vector<vector<T>> tmp(N, vector<T>(M, 0));
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                for(int k = 0; k < L; ++k)
                    tmp[i][j] += (*this)[i][k] * R[k][j];
        A.swap(tmp);
        return (*this);
    }

    Matrix<T> operator*(const Matrix<T> &R){
        return (Matrix(*this) *= R);
    }

    friend ostream &operator<<(ostream &os, Matrix &p){
        int N = p.Height(), M = p.Width();
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                os << p[i][j] << (j + 1 == M ? "" : " ");
            }
            os << (i + 1 == N ? "" : "\n");
        }
        return (os);
    }

    void print(){
        int N = Height(), M = Width();
        cerr << "Matrix ===============================\n";
        for(int i = 0; i < N; ++i){
            cerr << "[";
            for(int j = 0; j < M; ++j){
                cerr << A[i][j] << " ]"[j + 1 == M];
            }
            cerr << endl;
        }
    }

    T det() const {
        Matrix<T> tmp(*this);
        T ret = 1;
        int N = Size();
        int i = 0;
        for(int j = 0; i < N && j < N; ++j){
            // cerr << "i = " << i << ", j = " << j << endl;
            // tmp.print();
            bool found = false;
            for(int ti = i; ti < N && !found; ++ti){
                // cerr << " - ti = " << ti << ", val = " << tmp[ti][j] << endl;
                if(tmp[ti][j] != 0){
                    if(ti != i){
                        swap(tmp[ti], tmp[i]);
                        ret *= -1;
                    }
                    // cerr << " -  - OK\n";
                    found = true;
                }
            }
            if(!found) return 0;
            // tmp.print();
            for(int ti = i + 1; ti < N; ++ti){
                if(tmp[ti][j] == 0) continue;
                T mul = tmp[ti][j] / tmp[i][j];
                // cerr << " - ti = " << ti << ", mul = " << mul << endl;
                for(int tj = j; tj < N; ++tj){
                    // cerr << " -  - tj = " << tj << ", sub = " << tmp[i][tj] << " * " << mul << " = " << tmp[i][tj] * mul << endl;
                    tmp[ti][tj] -= tmp[i][tj] * mul;
                }
            }
            ++i;
        }
        for(int i = 0; i < N; ++i) ret *= tmp[i][i];
        return ret;
    }

    bool isRegular() const {
        return (det() != 0);
    }

    static Matrix<T> I(size_t N){
        Matrix<T> ret(N);
        for(int i = 0; i < N; ++i) ret[i][i] = 1;
        return (ret);
    }

    static Matrix<T> inv(const Matrix<T> &M){
        assert(M.isRegular());
        Matrix<T> tmp(M), ret = Matrix<T>::I(M.Size());
        int N = M.Size();
        int i = 0;
        for(int j = 0; i < N && j < N; ++j){
            bool found = false;
            for(int ti = i; ti < N && !found; ++ti){
                if(tmp[ti][j] != 0){
                    if(ti != i){
                        swap(tmp[ti], tmp[i]);
                        swap(ret[ti], ret[i]);
                    }
                    found = true;
                }
            }
            T div = tmp[i][j];
            for(int tj = 0; tj < N; ++tj) tmp[i][tj] /= div, ret[i][tj] /= div;
            for(int ti = 0; ti < N; ++ti){
                if(ti == i || tmp[ti][j] == 0) continue;
                T mul = tmp[ti][j];
                for(int tj = 0; tj < N; ++tj){
                    tmp[ti][tj] -= tmp[i][tj] * mul;
                    ret[ti][tj] -= ret[i][tj] * mul;
                }
            }
            ++i;
        }
        return ret;
    }
};