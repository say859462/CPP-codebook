class Solution {
  public:
    int cnt=0;
    int dfn[100005]={0};
    int low[100005]={0};
    bool ok[100005]={0};
    void dfs(int u,int v,vector<int>edge[]){
        dfn[u]=low[u]=cnt++;
        int child=0;
        for(int i:edge[u]){
            if(i==v)continue;//if next node is parent 
            if(dfn[i]<0){//not visit yet
                dfs(i,u,edge);
                low[u]=min(low[u],low[i]);
                if(u!=0 && low[i]>=dfn[u]){//u is not root but there exist a child node can not reach the lower low value than u
                    ok[u]=1;
                }
                child++;
            }
            else{
                low[u]=min(low[u],low[i]);
            }
        }
        if(u==0 && child>1){//u is root and has 2 child
            ok[u]=1;
        }
        return ;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>ans;
        cnt=0;
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        memset(ok,0,sizeof(ok));
        dfs(0,-1,adj);
        for(int i=0;i<V;i++){
            if(ok[i])ans.push_back(i);
        }
        if(ans.size()==0)ans.push_back(-1);
        return ans;
    }
};
