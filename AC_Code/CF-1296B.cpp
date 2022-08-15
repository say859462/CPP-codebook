#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,s;
    cin>>t;
    while(t--){
        cin>>s;
        int ans=0;
        while(s){
            ans+=(s/10) *10;
            int back=s/10;
            if(back==0){
                ans+=s%10;
                break;
            }
            s=s%10+back;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
