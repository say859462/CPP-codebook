#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define on 1
#define off 0
#define ll long long
using namespace std;
const int MAX=2e5+10;
vector<int> node[MAX];
vector<pair<int,int>> rec(MAX);//紀錄i節點之子樹左右區間
bool status[MAX]={0};//輸入當前各節點狀態
bool for_tree[MAX]={0};
int tree[4*MAX]={0};//線段樹
int lazy_tag[4*MAX]={0};//懶標記
int cnt=0;
//線段數、樹壓平、區間修改、區間訪問

void dfs_time(int x){//得到節點x的子樹區間左右界
    rec[x].first=++cnt;
    for_tree[cnt]=status[x];//Important! 由於節點dfs不一定會是按照節點編號遞迴，所以當前紀錄的左界不一定等於當前節點編號
    for(auto i:node[x]){
        dfs_time(i);
    }
    rec[x].second=cnt;
}
void build(int l,int r,int idx){//建線段樹
    if(l==r){
        tree[idx]=for_tree[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,idx<<1);
    build(mid+1,r,idx<<1|1);
    tree[idx]=tree[idx<<1]+tree[idx<<1|1];
    return ;
}
void push(int l,int r,int cur){//懶標記下移
    if(lazy_tag[cur]){
        int mid=(l+r)>>1;
        //將懶標記往下打
        lazy_tag[cur<<1]^=1;
        lazy_tag[cur<<1|1]^=1;
        //
        lazy_tag[cur]=0;
        tree[cur<<1]=(mid-l+1)-tree[cur<<1];//值為該子樹的映射 0->1 / 1->0
        tree[cur<<1|1]=(r-(mid+1)+1)-tree[cur<<1|1];
    }
    return ;
}
void update(int ql,int qr,int l,int r,int cur){//更新區間值

    if(ql<=l&&r<=qr){//代表整個區間都需要更新
        tree[cur]=(r-l+1)-tree[cur];
        lazy_tag[cur]^=1;
        return ;
    }
    int mid=(l+r)>>1;
    push(l,r,cur);//檢查是否有之前更新所留下來的懶標記(有的話順便更新值)

    if(ql<=mid){
        update(ql,qr,l,mid,cur<<1);
    }
    if(qr>mid){
        update(ql,qr,mid+1,r,cur<<1|1);//cur<<1|1=cur*2+1
    }

    tree[cur]=tree[cur<<1]+tree[cur<<1|1];//子節點值更新之後需要其祖先的值也進行更新
    return;
}
int query(int ql,int qr,int l,int r,int cur){//詢問區間值
    if(l>=ql&&r<=qr){
        return tree[cur];
    }
    int ans=0;
    int mid=(l+r)>>1;
    push(l,r,cur);//順便檢查是否有懶標記
    if(ql<=mid){
        ans+=query(ql,qr,l,mid,cur<<1);
    }
    if(qr>mid){
        ans+=query(ql,qr,mid+1,r,cur<<1|1);
    }
    tree[cur]=tree[cur<<1]+tree[cur<<1|1];
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        node[u].push_back(i);
    }
    
    for(int i=1;i<=n;i++){
        cin>>status[i];
    }
  
    dfs_time(1);
    build(1,n,1);
    
}
