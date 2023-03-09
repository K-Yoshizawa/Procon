#include <bits/stdc++.h>
using namespace std;

int N;
double X[20],Y[20],dp[1<<16][20];

int main(){
    cin>>N;
    for(int i=0;i<N;++i) cin>>X[i]>>Y[i];

    double INF=1e9;
    for(int i=0;i<(1<<N);++i){
        for(int j=0;j<N;++j){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<(1<<N);++i){
        for(int j=0;j<N;++j){
            if(dp[i][j]==INF) continue;
            for(int k=0;k<N;++k){
                if(j==k) continue;
                if((i&(1<<k))>0) continue;
                double next=dp[i][j]+sqrt((X[j]-X[k])*(X[j]-X[k])+(Y[j]-Y[k])*(Y[j]-Y[k]));
                dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],next);
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dp[(1<<N)-1][0]<<endl;
}