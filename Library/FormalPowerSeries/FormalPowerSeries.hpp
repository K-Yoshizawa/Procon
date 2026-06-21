#pragma once

#include "../Common.hpp"
#include "Convolution.hpp"

class FormalPowerSeries : public vector<mint> {
    public:
    using vector<mint>::vector;
    using FPS = FormalPowerSeries;

    FPS Inverse(int N = -1) const {
        assert(!this->empty() && (*this)[0] != mint(0));
        if(N == -1){
            N = this->size();
        }
        FPS res = {(*this)[0].Inverse()};
        for(int i = 1; i < N; i <<= 1){
            FPS t = (this->Prefix(i << 1) * res).Prefix(i << 1);
            for(auto &x : t){
                x = -x;
            }
            t[0] += mint(2);
            res = (res * t).Prefix(i << 1);
        }
        return res.Prefix(N);
    }

    FPS Exp(int N = -1) const {
        assert(this->empty() || (*this)[0] == mint(0));
        if(N == -1){
            N = this->size();
        }
        FPS res = {mint(1)};
        for(int i = 1; i < N; i <<= 1){
            FPS t = this->Prefix(i << 1) - res.Log(i << 1);
            t[0] += mint(1);
            res = (res * t).Prefix(i << 1);
        }
        return res.Prefix(N);
    }

    FPS Log(int N = -1) const {
        assert(!this->empty() && (*this)[0] == mint(1));
        if(N == -1){
            N = this->size();
        }
        return (this->Prefix(N).Differential() * this->Inverse(N)).Prefix(N - 1).Integral().Prefix(N);
    }

    FPS Differential() const {
        const int N = this->size();
        FPS ret(max(0, N - 1));
        for(int i = 1; i < N; ++i){
            ret[i - 1] = (*this)[i] * mint(i);
        }
        return ret;
    }

    FPS Integral() const {
        const int N = this->size();
        FPS ret(N + 1);
        vector<mint> inv(N + 1);
        if(N >= 1){
            inv[1] = 1;
        }
        for(int i = 2; i <= N; ++i){
            inv[i] = -inv[998244353 % i] * (998244353 / i);
        }
        for(int i = 0; i < N; ++i){
            ret[i + 1] = (*this)[i] * inv[i + 1];
        }
        return ret;
    }

    FPS &operator+=(const mint &v){if (this->empty()) this->resize(1); (*this)[0] += v; return *this;}
    FPS &operator-=(const mint &v){if (this->empty()) this->resize(1); (*this)[0] -= v; return *this;}
    FPS &operator*=(const mint &v){for (auto &x : *this) x *= v; return *this;}
    FPS &operator/=(const mint &v){return *this *= v.Inverse();}

    FPS &operator+=(const FPS &r){
        if(r.size() > this->size()){
            this->resize(r.size());
        }
        for(int i = 0; i < (int)r.size(); ++i){
            (*this)[i] += r[i];
        }
        return *this;
    }
    FPS &operator-=(const FPS &r){
        if(r.size() > this->size()){
            this->resize(r.size());
        }
        for(int i = 0; i < (int)r.size(); ++i){
            (*this)[i] -= r[i];
        }
        return *this;
    }
    FPS &operator*=(const FPS &r){
        if(this->empty() || r.empty()){
            this->clear(); return *this;
        }
        auto res = ntt::Convolution(*this, r);
        return *this = FPS(res.begin(), res.end());
    }

    FPS operator-() const {FPS ret(*this); for (auto &x : ret) x = -x; return ret;}

    FPS operator+(const mint &v) const {return FPS(*this) += v;}
    FPS operator-(const mint &v) const {return FPS(*this) -= v;}
    FPS operator*(const mint &v) const {return FPS(*this) *= v;}
    FPS operator/(const mint &v) const {return FPS(*this) /= v;}
    FPS operator+(const FPS &r) const {return FPS(*this) += r;}
    FPS operator-(const FPS &r) const {return FPS(*this) -= r;}
    FPS operator*(const FPS &r) const {return FPS(*this) *= r;}

    private:
    FPS Prefix(int N) const {
        FPS ret(this->begin(), this->begin() + min((int)this->size(), N));
        ret.resize(N);
        return ret;
    }
};