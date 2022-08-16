#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    ll t,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(c<=d && b<a){
            cout<<-1<<'\n';
            continue;
        }
        if(b>=a){
            cout<<b<<'\n';
            continue;
        }
        ll rest=c-d;
        ll tmp=((a-b)-1)/rest+1;
        cout<< b+ tmp*c <<'\n';
    }
    return 0;
}
