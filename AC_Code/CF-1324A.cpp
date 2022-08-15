#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    vector<int>base;
    while(t--){
        cin>>n;
        base.clear();
        base.resize(n);
        for(int i=0;i<n;i++)cin>>base[i];
        bool even=0,odd=0;
        for(int i=0;i<n;i++){
            if(base[i]&1)odd=1;
            else even=1;
        }
        if(odd&&!even || !odd &&even){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}
