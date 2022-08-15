#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n<k){
            cout<<k-n<<'\n';
        }
        else{
            if( (k&1 && n&1) || (k%2==0&&n%2==0)){
                cout<<0<<'\n';
            }
            else{
                cout<<1<<'\n';
            }
            
        }
    }
    return 0;
}
