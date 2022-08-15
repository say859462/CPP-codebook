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
    while(t--){
        cin>>n;
        cin>>a>>b>>c>>d;
        int top=c+d,down=c-d;
        int low=a-b,high=a+b;
        if(high * n <down || low*n >top){
            cout<<"No"<<'\n';
        }
        else{
            cout<<"Yes"<<'\n';
        }

    }
    return 0;
}
