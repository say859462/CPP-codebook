#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,a,b,n;
    cin>>t;
    vector<int>size;
    while(t--){
        cin>>n;
        size.clear();
        size.resize(n);
        int mx=0,idx=-1;
        for(int i=0;i<n;i++){
            cin>>size[i];
            mx=max(mx,size[i]);
        }
        for(int i=0;i<n;i++){
            if(size[i]!=mx)continue;
            
            if(i>0 && size[i-1]!=mx){
                idx=i+1;
            }
            if(i+1<n && size[i+1]!=mx){
                idx=i+1;
            }
            
        }
        cout<<idx<<'\n';
    }
    return 0;
}
