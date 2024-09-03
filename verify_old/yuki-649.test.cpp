#define PROBLEM "https://yukicoder.me/problems/no/649"

#include "../library/DataStructure/KthMultiSet.hpp"

int main(){
    int Q, K; cin >> Q >> K;
    KthMultiSet<long long> st(K);
    while(Q--){
        int query; cin >> query;
        if(query == 1){
            long long v; cin >> v;
            st.insert(v);
        }
        else{
            long long v = -1;
            if(st.exist()){
                v = st.get();
                st.erase(v);
            }
            cout << v << endl;
        }
    }
}