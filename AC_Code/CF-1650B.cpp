#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,l,r,a;
    cin>>t;
    //f(x)=[x/a]+ x mod a
    while(t--){
        cin>>l>>r>>a;
        if(l/a == r/a){
            cout<<r/a + r%a<<'\n';
        }
        else{
            cout<<max(r/a + r%a,r/a-1 + a-1)<<'\n';
        
    }
    return 0;
}
