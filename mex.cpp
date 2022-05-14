#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define op cin.tie(0);ios::sync_with_stdio(0);cout.tie(0);
using namespace std;
const int mx=2e5+10;
int num[mx]={0};
struct node{
    node *l,*r;
    int w;
    node(){
        l=r=nullptr;
    }
};
vector<node *>version;//儲存各版本線段樹，第k版本代表 序列前k個元素的結果
node *root=new node;
void build(node *cur,int l,int r){//預先建構初始線段樹 節點區間[l,r]之值代表最後一次被更新的版本
    if(l==r){
        cur->w=0;
        return ;
    }
    int mid=(l+r)>>1;
    cur->l=new node;
    cur->r=new node;
    build(cur->l,l,mid);
    build(cur->r,mid+1,r);
    cur->w=0;
    return ;
}
node *update(node *pre,int l,int r,int val,int pos){
    node *x=new node;
    x->w=pos;
    if(l==r){
        x->w=pos;
        return x;
    }
    int mid=(l+r)>>1;
    if(val<=mid){
        x->l=update(pre->l,l,mid,val,pos);
        x->r=pre->r;
    }
    else{
        x->r=update(pre->r,mid+1,r,val,pos);
        x->l=pre->l;
    }
    x->w=min(x->l->w,x->r->w);
    return x;
}
int query(node *cur,int l,int r,int pos){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(cur->l->w<pos)return query(cur->l,l,mid,pos);
    else return query(cur->r,mid+1,r,pos);
}
int main(){
    op
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    build(root,0,mx);
    version.push_back(root);
    node *new_rt=nullptr;
    for(int i=1;i<=n;i++){
        new_rt=nullptr;
        new_rt=update(version.back(),0,mx,num[i],i);
        version.push_back(new_rt);
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        cout<<query(version[b],0,mx,a)<<'\n';
    }
}
