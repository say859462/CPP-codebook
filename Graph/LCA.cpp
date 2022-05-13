#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int mx=1e5+10;
vector<int>edge[mx];
int tin[mx],tou[mx];
int  t=1;
int anc[mx][log2(mx)]={0};
int n;
void dfs(int x,int f){
  anc[x][0]=f;
  tin[x]=t++;
  for(int i:edge[x]){
    if(i==f)continue;
    dfs(i,x);
  }
  tou[x]=t++;
  return ;
}
bool isAncestor(int anc,int child){
  return tin[anc]<=tin[child]&&tou[anc]>=tou[child];
} 
int getLca(int u, int v){
    if(isAncestor(u, v))    return u; // 如果 u 為 v 的祖先則 lca 為 u
    if(isAncestor(v, u))    return v; // 如果 v 為 u 的祖先則 lca 為 u
    for(int i=lgN;i>=0;i--){    // 判斷 2^lgN, 2^(lgN-1),...2^1, 2^0 倍祖先
        if(!isAncestor(anc[u][i], v)) // 如果 2^i 倍祖先不是 v 的祖先
            u = anc[u][i];            // 則往上移動
    }
    return anc[u][0]; // 回傳此點的父節點即為答案
}
int main(){
  cin>>n;
  int u,v;
  for(int i=1;i<=n;i++){
    cin>>u>>v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1,1);
  for(int i=1;i<=log2(n);i++){
    for(int j=1;j<=n;j++){
      anc[j][i]=anc[anc[j][i-1]][i-1];
    }
  }
}
