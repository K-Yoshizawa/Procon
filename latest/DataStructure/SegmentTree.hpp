


#include <bits/stdc++.h>
using namespace std;

template<typename Monoid>
struct SegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;

    int __Size, __Offset, __ZeroIndex;
    vector<Monoid> __Data;
    const F f;
    const Monoid __M1;

    inline void __Check(int x){
        assert(1 <= x && x <= __Size);
    }

    Monoid __query(int ql, int qr, int left, int right, int cell){
        if(qr <= left || right <= ql){
            return __M1;
        }
        if(ql <= left && right <= qr){
            return __Data[cell];
        }
        int mid = (left + right) / 2;
        Monoid ans_left = __query(ql, qr, left, mid, 2 * cell);
        Monoid ans_right = __query(ql, qr, mid, right, 2 * cell + 1);
        return f(ans_left, ans_right);
    }

    public:
    SegmentTree(int Size, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false) : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < Size) __Size <<= 1;
        __Offset = __Size - 1;
        __Data.resize(2 * __Size, __M1);
    }

    void build(){
        for(int i = __Offset; i >= 1; --i){
            __Data[i] = f(__Data[i * 2 + 0], __Data[i * 2 + 1]);
        }
    }

    void set(int Index, Monoid Value){
        __Check(Index + __ZeroIndex);
        __Data[__Offset + Index + __ZeroIndex] = Value;
    }

    SegmentTree(vector<Monoid> &Init_Data, F Merge, const Monoid &Monoid_Identity, bool ZeroIndex = false) : f(Merge), __M1(Monoid_Identity), __ZeroIndex(ZeroIndex){
        __Size = 1;
        while(__Size < (int)Init_Data.size()) __Size <<= 1;
        __Offset = __Size - 1;
        __Data.resize(2 * __Size, __M1);
        for(int i = 0; i < (int)Init_Data.size(); ++i){
            __Data[__Size + i] = Init_Data[i];
        }
        build();
    }

    void update(int Index, Monoid Value){
        __Check(Index + __ZeroIndex);
        int k = __Offset + Index + __ZeroIndex;
        __Data[k] = Value;
        while(k >>= 1){
            __Data[k] = f(__Data[2 * k], __Data[2 * k + 1]);
        }
    }

    Monoid query(int Left, int Right){
        __Check(Left + __ZeroIndex);
        __Check(Right + __ZeroIndex - 1);
        return __query(Left + __ZeroIndex, Right + __ZeroIndex, 1, __Size + 1, 1);
    }

    Monoid get(int k){
        __Check(k + __ZeroIndex);
        return __Data[__Offset + k + __ZeroIndex];
    }

    Monoid operator[](const int &k){
        return get(k);
    }
};