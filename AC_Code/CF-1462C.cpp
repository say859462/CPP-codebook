#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=2e3+5;
vector<int>t[mx],root;
int ans=0;
int dep[mx]={0};
void dfs(int idx,int d){
    dep[idx]=d;
    ans=max(ans,d);
    for(int i:t[idx]){
        dfs(i,d+1);
    }
    return ;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n;
    int a,b,c,d;
    cin>>t;
    //123456789
    while(t--){
        cin>>n;
        if(n>45){
            cout<<-1<<'\n';
        }
        else{
            int i=9;
            string ans;
            while(n-i>0){
                ans+=i+'0';
                n-=i;
                i--;
            }
            if(n)ans+='0'+n;
            reverse(ans.begin(),ans.end());
            cout<<ans<<'\n';
        }
    }
    return 0;
}
