#include <iostream>
#include <vector>
#include <algorithm>
#define inf 0x3f3f3f3f
#define op cin.tie(0);ios::sync_with_stdio(0);
using namespace std;
const int mx=2e5+10;
int num[mx]={0};
struct qu{
    int l,r,id;
    
}Q[mx];
struct node{
    node *l,*r;
    int val,tag;
    node(){
        l=r=nullptr;
        tag=-1;
        val=inf;
    }
};
/*若當前線段樹 記錄了[i,n]區間的mex值 考慮轉移i->i+1的過程
會受影響的區間範圍為何? 區間[i+1,下一次該元素出現位置-1] 並對該區間做update 若原本的mex小於num[i] 則繼續保留 否則更改為num[i]*/

bool vis[mx]={0};//紀錄該數值是否出現過
int nxt[mx]={0},last[mx]={0};//紀錄第i個元素 下次出現位置 以及 迴圈目前最後一次出現位置
int mex[mx]={0};//紀錄區間[1,i]的mex值
bool cmp(const qu& a, const qu& b){

    if(a.l==b.l)return a.r<b.r;

    return a.l<b.l;
}
void build(node *cur,int l,int r){//建立初始線段樹 初始值為區間[1,i]的mex值 ex:節點[8,8]紀錄 區間[1,8]的mex值
    if(l==r){
        cur->val=mex[l];
        return ;
    }
    int mid=(l+r)>>1;
    cur->l=new node;
    cur->r=new node;
    build(cur->l,l,mid);
    build(cur->r,mid+1,r);
    cur->val=min(cur->l->val,cur->r->val);
    return ;
}
void push(node *cur){

    if(cur->l){//若左子節點存在
        if(~cur->l->tag){//若左子節點已經有tag 則去與欲往下打得tag做比較
            cur->l->tag=min(cur->tag,cur->l->tag);
        }
        else{
            cur->l->tag=cur->tag;
        }
        cur->l->val=min(cur->l->val,cur->tag);
    }

    if(cur->r){//若右子節點存在
        if(~cur->r->tag){
            cur->r->tag=min(cur->tag,cur->r->tag);
        }
        else{
            cur->r->tag=cur->tag;
        }
        cur->r->val=min(cur->r->val,cur->tag);
    }

    cur->tag=-1;//將當前節點tag移除
    
    return ;
}
void update(node *rt,int l,int r,int ql,int qr,int mn){

    if(r<ql || l>qr )return ; //若當前節點代表區間已經不再詢問區間內 

    if(rt->tag!=-1)push(rt);//若當前節點有tag

    if(ql<=l&&r<=qr){//若當前在詢問區間內 打上tag 並比較當前節點的值與欲更新的值 取min
        rt->tag=mn;
        rt->val=min(rt->val,mn);
        return ;
    }   

    int mid=(l+r)>>1;
     
      update(rt->l,l,mid,ql,qr,mn);

      update(rt->r,mid+1,r,ql,qr,mn);
    

    rt->val=min(rt->l->val,rt->r->val);

    return ;

}
int query(node *rt,int l,int r,int pos){//詢問 葉節點[r,r]之值 

    
    if(rt->tag!=-1)push(rt);

    if(l==r&&l==pos) return rt->val;

    int mid=(l+r)>>1;

    if(pos<=mid) return query(rt->l,l,mid,pos);

    else return query(rt->r,mid+1,r,pos);
}

int main(){
    op
    int n,q;

    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    for(int i=1;i<=q;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }

    for(int i=n;i>0;i--){

        if(last[num[i]]==0)nxt[i]=n+1;//若當前 元素num[i]尚未出現過，則將第i個元素下一次出現位置設為n+1
        else nxt[i]=last[num[i]];//否則紀錄第i個元素下次出現位置
        last[num[i]]=i;
    }

    int j=0;
    for(int i=1;i<=n;i++){//找尋區間[1,i]的mex值 O(N) (每個值域只會跑過一次)
        vis[num[i]]=true;
        for(; ;j++ )if(!vis[j])break;
        mex[i]=j;
    }
    /*for(int i=1;i<=n;i++){
        cout<<mex[i]<<" ";
    }*/

    sort(Q+1,Q+1+q,cmp);

    node *root=new node;

    build(root,1,n);

    int ans[mx]={0};
    for(int i=1,j=1;i<=n&&j<=q;i++){
        while(Q[j].l==i){
            ans[Q[j].id]=query( root , 1 , n , Q[j].r );
            j++;
        }
        update(root,   1,n ,    1,nxt[i]-1  , num[i]);//更新區間[ 1 ,  nxt[i]-1 ]的mex值
    }

    for(int i=1;i<=q;i++){
        cout<<ans[i]<<'\n';
    }
    

} 
