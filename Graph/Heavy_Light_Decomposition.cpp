#include <iostream>
#include <vector>
using namespace std;
int sz[MXN],dep[MXN],fa[MXN],heavy[MXN];
vector<int> treeID;
vector<vector<int>> tree;
int treeSz=1;
int root[MXN], len[MXN];
void dfs1(int x,int f,int d){
    dep[x]=d;  //紀錄深度
    fa[x]=f; //設父節點
    sz[x]=1;     //將自己本身加進子樹大小
    heavy[x]=0;    //一開始先指向空
    for(int i=0;i<edge[x].size();i++){
        if(edge[x][i]==f)    continue;
        dfs1(edge[x][i],x,d+1);        //dfs下去紀錄每個子樹的大小
        sz[x]+=sz[edge[x][i]];         //將子樹大小加至自己
        if(sz[edge[x][i]]>sz[heavy[x]])  heavy[x]=edge[x][i];  //找重兒子
    }
}
void dfs2(int x,int f,bool isLight){
    for(int i=0;i<edge[x].size();i++){
        if(edge[x][i]==f)    continue;
        if(edge[x][i]==heavy[x])            //判斷是否為重兒子
            root[edge[x][i]]=root[x];       //若為重兒子則跟自己同一條鏈
        else    root[edge[x][i]]=edge[x][i],treeSz++; //否則剖分成新鏈
        dfs2(edge[x][i],x);
    }
    len[root[x]]++;                         //紀錄每條鏈的長度儲存在第一節點的位置
}

/*void buildTree(){
    tree.resize(treeSz);
    for(int i=1,j=0;i<=n;i++){
        if(root[i]==i){    //判斷鏈的開頭
            treeID[i]=j++;    //設為第j條鏈
            tree[treeID[i]].resize(len[i]*4,0);  //以線段樹為例
        }                                        //設第j條鏈的長度4倍大小
    }
}線段樹*/

/*void update(int ver,int x,int v,bool ini){
  int dif=val[ver][x-1];
  while(x<BIT[ver].size()){
    if(ini) BIT[ver][x]^=(1<<dif);
    BIT[ver][x]^=v;
    x+=lowbit(x);
  }
}

void build(){
  for(int i=1;i<=n;i++){
    BIT[root[i]].resize(len[root[i]]+5);
  }

  for(int i=1;i<=n;i++){
    if(!visit[root[i]]){
      for(int j=0;j<val[root[i]].size();j++){

        update(root[i],j+1,1<<val[root[i]][j],0);
      }

      visit[root[i]]=1;
    }
  }
}BIT*/

int main(){
  
}
