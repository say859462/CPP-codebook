int dp[mx]={};
int sz[mx]={};
vector<vector<int>> edge(mx);
void dfs(int x,int f){
    sz[x]=1;
    for(auto i:edge[x]){
        if(i==f)continue;
        dfs(i,x);
        sz[x]+=sz[i];
        dp[x]+=(dp[i]+sz[i]);
    }
    return ;
}
void dfs2(int x,int f,ll sum){
    ans+=(dp[x]+sum);
    for(auto i:edge[x]){
        if(i==f)continue;
         ll tmp = sum+dp[x]-(dp[i]+sz[i])+(n-sz[i]);
         dfs2(i,x,tmp);
    }
    return ;
}
