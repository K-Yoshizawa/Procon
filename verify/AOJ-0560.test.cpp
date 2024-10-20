#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0560"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/CumulativeSum2D.hpp"

int main(){
    int N, M; cin >> N >> M;
    int K; cin >> K;
    CumulativeSum2D<int> Jcum(N, M), Ocum(N, M), Icum(N, M);
    for(int i = 0; i < N; ++i){
        string S; cin >> S;
        for(int j = 0; j < M; ++j){
            switch(S[j]){
                case 'J': Jcum.Set(i, j, 1); break;
                case 'O': Ocum.Set(i, j, 1); break;
                case 'I': Icum.Set(i, j, 1); break;
            }
        }
    }
    Jcum.Build();
    Ocum.Build();
    Icum.Build();
    for(int i = 0; i < K; ++i){
        int a, b, c, d; cin >> a >> b >> c >> d, --a, --b, --c, --d;
        cout << Jcum.Sum(a, b, c, d) << ' ' << Ocum.Sum(a, b, c, d) << ' ' << Icum.Sum(a, b, c, d) << endl;
    }
}