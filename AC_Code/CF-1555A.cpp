#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int slice[3]={6,8,10};
int cost[3]={15,20,25};
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    ll n,m,t,x,y,z;
    cin>>t;
    while(t--){
        cin>>n;
        // if n is odd we add 1 for sure it always be even
        //we can find that while n>=12 and its even , we can find a set with exacly n pizza
        cout<<max((ll)6,n+1)/2 * 5<<'\n';
    }

    return 0;
}
