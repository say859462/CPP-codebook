#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n,h;
    cin>>t;
    vector<int>num;
    while(t--){
        cin>>n;
        num.resize(n);
        for(int i=0;i<n;i++)cin>>num[i];
        int ans=num[0];
        int tmp=num[0];
        for(int i=1;i<n;i++){
            tmp&=num[i];
            ans=min(ans,tmp);
        }
        cout<<ans<<'\n';
        
    }

    return 0;
}
