#include <bits/stdc++.h>
#define ll long long 
using namespace std;
bool cmp(ll a,ll b){
    return abs(a)>abs(b);
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
   int n;
   cin>>n;
   vector<int>num;
   num.resize(n);
   int cnt=0;
   int neg=0;
   ll ans=0;
   for(int i=0;i<n;i++){
        cin>>num[i];
        if(num[i]==0){
            cnt++;
            continue;
        }
        if(num[i]<0)neg++;
        ans+=abs(num[i])-1;
   }
   if(cnt==0){
        if(neg&1){//-1
            cout<<ans+2<<'\n';
        }
        else{
            cout<<ans<<'\n';
        }
   }
   else{
        cout<<ans+cnt<<'\n';
   }
    return 0;
}
