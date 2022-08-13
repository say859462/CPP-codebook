#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
    cin>>t;
    int x,n,m;
    while(t--){
        cin>>x>>n>>m;
        if(10*m>=x){
            cout<<"YES"<<'\n';
        }
        else{
            while( (x>10*m) && n){
                x=x/2+10;
                n--;
            }
            if(x>10*m){
                cout<<"NO"<<'\n';
            }
            else{
                cout<<"YES"<<'\n';
            }
        }
    }
    return 0;
}
