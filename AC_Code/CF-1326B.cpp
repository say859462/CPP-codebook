#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll>rec;
    vector<ll>ans;
    rec.resize(n);
    for(int i=0;i<n;i++)cin>>rec[i];
    ll mx=rec[0];
    ans.push_back(mx);
    //ans.back()+rec[i]
    for(int i=1;i<n;i++){
        ans.push_back(rec[i]+mx);
        mx=max(mx,rec[i]+mx);
    }
    for(int i:ans)cout<<i<<" ";
    cout<<'\n';
    return 0;
}
