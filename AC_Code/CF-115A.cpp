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
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;//i是x的manager
        if(x!=-1){
            t[x].push_back(i);
        }
        else root.push_back(i);
    }
    for(int i=1;i<=n;i++)dfs(i,1);
    cout<<ans<<'\n';
    return 0;
}
