#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    ll ans=-0x3f3f3f3f;
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(b>k){
            ans=max(ans,a-(b-k));
        }
        else{
            ans=max(ans,a);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
