#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll gcd(ll a,ll b){
    if(a==0 || b==0)return a?a:b;
    while(b){
        ll tmp=a;
        a=b;
        b=tmp%b;
    }
    return b;
}
int main(){//gcd(a,b)=gcd(a-b,b)
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n;
    ll a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a==b){
            cout<<0<<" "<<0<<'\n';
        }
        else{
            ll g=abs(a-b);
            cout<<abs(a-b)<<" "<<min(b%g,g-b%g)<<'\n';
        }
    }
    return 0;
}
