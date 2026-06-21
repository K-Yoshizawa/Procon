#pragma once

#include "../Common.hpp"
#include "MontgomeryModInt998244353.hpp"

namespace ntt {
    struct Info{
        static constexpr int g = 3;
        static constexpr int rank2 = 23;

        mint root[rank2 + 1], iroot[rank2 + 1];
        mint rate3[rank2 + 1], irate3[rank2 + 1];

        Info(){
            root[rank2] = mint(g).Power((998244353 - 1) >> rank2);
            iroot[rank2] = root[rank2].Inverse();
            for(int i = rank2 - 1; i >= 0; --i){
                root[i] = root[i + 1] * root[i + 1];
                iroot[i] = iroot[i + 1] * iroot[i + 1];
            }
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 3; ++i) {
                rate3[i]  = root[i + 3]  * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod  *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    };

    inline const Info& info(){
        static Info instance;
        return instance;
    }

    void ntt(vector<mint> &f){
        const int n = f.size();
        const int h = countr_zero(static_cast<uint32_t>(n));
        const auto& I = info();
        int len = 0;
        if(h & 1){
            int p = 1 << (h - 1);
            for(int i = 0; i < p; ++i){
                mint r = f[i + p];
                f[i + p] = f[i] - r;
                f[i] += r;
            }
            len++;
        }
        for(; len + 1 < h; len += 2){
            int p = 1 << (h - len - 2);
            const mint imag = I.root[2];
            for(int i = 0; i < p; ++i){
                mint f0 = f[i], f1 = f[i + p], f2 = f[i + 2 * p], f3 = f[i + 3 * p];
                mint f1nf3imag = (f1 - f3) * imag;
                mint f0f2 = f0 + f2, f1f3 = f1 + f3, f0nf2 = f0 - f2;
                f[i] = f0f2 + f1f3;
                f[i + p] = f0f2 - f1f3;
                f[i + 2 * p] = f0nf2 + f1nf3imag;
                f[i + 3 * p] = f0nf2 - f1nf3imag;
            }
            mint rot = I.rate3[0];
            for(int s = 1; s < (1 << len); ++s){
                int offset = s << (h - len);
                mint rot2 = rot * rot, rot3 = rot2 * rot;
                for(int i = 0; i < p; ++i){
                    mint f0 = f[i + offset];
                    mint f1 = f[i + offset + p] * rot;
                    mint f2 = f[i + offset + 2 * p] * rot2;
                    mint f3 = f[i + offset + 3 * p] * rot3;
                    mint f1nf3imag = (f1 - f3) * imag;
                    mint f0f2 = f0 + f2, f1f3 = f1 + f3, f0nf2 = f0 - f2;
                    f[i + offset] = f0f2 + f1f3;
                    f[i + offset + p] = f0f2 - f1f3;
                    f[i + offset + 2 * p] = f0nf2 + f1nf3imag;
                    f[i + offset + 3 * p] = f0nf2 - f1nf3imag;
                }
                rot *= I.rate3[countr_zero(~static_cast<uint32_t>(s))];
            }
        }
    }

    void intt(vector<mint> &f, bool flag = true){
        const int n = f.size();
        const int h = countr_zero(static_cast<uint32_t>(n));
        const auto& I = info();
        int len = h;
        for(; len > 1; len -= 2){
            int p = 1 << (h - len);
            const mint iimag = I.iroot[2];
            for(int i = 0; i < p; ++i){
                mint f0 = f[i], f1 = f[i + p], f2 = f[i + 2 * p], f3 = f[i + 3 * p];
                mint f2nf3iimag = (f2 - f3) * iimag;
                mint f0nf1 = f0 - f1, f0f1 = f0 + f1, f2f3 = f2 + f3;
                f[i] = f0f1 + f2f3;
                f[i + p] = f0nf1 + f2nf3iimag;
                f[i + 2 * p] = f0f1 - f2f3;
                f[i + 3 * p] = f0nf1 - f2nf3iimag;
            }
            mint irot = I.irate3[0];
            for(int s = 1; s < (1 << (len - 2)); ++s){
                int offset = s << (h - len + 2);
                mint irot2 = irot * irot, irot3 = irot2 * irot;
                for(int i = 0; i < p; ++i){
                    mint f0 = f[i + offset];
                    mint f1 = f[i + offset + p];
                    mint f2 = f[i + offset + 2 * p];
                    mint f3 = f[i + offset + 3 * p];
                    mint f2nf3iimag = (f2 - f3) * iimag;
                    mint f0nf1 = f0 - f1, f0f1 = f0 + f1, f2f3 = f2 + f3;
                    f[i + offset] = f0f1 + f2f3;
                    f[i + offset + p] = (f0nf1 + f2nf3iimag) * irot;
                    f[i + offset + 2 * p] = (f0f1 - f2f3) * irot2;
                    f[i + offset + 3 * p] = (f0nf1 - f2nf3iimag) * irot3;
                }
                irot *= I.irate3[countr_zero(~static_cast<uint32_t>(s))];
            }
        }
        if(len >= 1){
            int p = 1 << (h - 1);
            for(int i = 0; i < p; ++i){
                mint fjp = f[i] - f[i + p];
                f[i] += f[i + p];
                f[i + p] = fjp;
            }
        }
        if(flag){
            mint inv = mint(n).Inverse();
            for(auto &x : f){
                x *= inv;
            }
        }
    }

    vector<mint> Convolution(vector<mint> A, vector<mint> B){
        const int N = A.size(), M = B.size();
        if(N == 0 || M == 0) return {};

        if(min(N, M) <= 60){
            vector<mint> C(N + M - 1);
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < M; ++j){
                    C[i + j] += A[i] * B[j];
                }
            }
            return C;
        }

        const int z = bit_ceil(static_cast<uint32_t>(N + M - 1));
        A.resize(z); ntt(A);
        B.resize(z); ntt(B);
        const mint iz = mint(z).Inverse();
        for(int i = 0; i < z; ++i){
            A[i] *= B[i] * iz;
        }
        intt(A, false);
        A.resize(N + M - 1);
        return A;
    }
};
