#include <iostream>
#define NO_TAG 0
#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
using namespace std;
const int mx=1e5+10;
int num[mx];
int tree[mx*4];
void build(int idx,int l,int r){
   if(l==r){
      tree[idx]=num[l];
   }
  int mid=(l+r)>>1;
  build(cl(idx),l,mid);
  build(cr(idx),mid+1,r);
  tree[idx]=tree[cl(idx)]+tree[cr(idx)];//依題目要求更改
}
int query(int i,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){ //若當前區間在詢問區間內，直接回傳區間最大值
        return tree[i];
    }
    int mid=(l+r)/2, ret=0;
    if(ql<=mid) // 如果左子區間在詢問區間內
        ret = max(ret, query(cl(i),l,mid,ql,qr));
    if(qr> mid) // 如果右子區間在詢問區間內
        ret = max(ret, query(cr(i),mid+1,r,ql,qr);
    return ret;
}

void push(int i,int l,int r){
    if(tag[i] != NO_TAG){ // 判斷是否有打標記
        tree[i] += tag[i];  // 有的話就更新當前節點的值
        if(l != r){  // 如果有左右子節點把標記往下打
            tag[cl(i)] += tag[i];
            tag[cr(i)] += tag[i];
        }
        tag[i] = NO_TAG; // 更新後把標記消掉
    }    
}
void pull(int i,int l,int r){
    int mid = (l+r)/2;
    push(cl(i),l,mid); push(cr(i),mid+1,r);
    tree[i] = max(tree[cl(i)], tree[cr(i)]);
}
void update(int i,int l,int r,int ql,int qr,int v){
    push(i,l,r);
    if(ql<=l && r<=qr){
        tag[i] += v;
        return;
    }
    int mid=(l+r)/2;
    if(ql<=mid)  update(cl(i),l,mid,ql,qr,v);
    if(qr> mid)  update(cr(i),mid+1,r,ql,qr,v);
    pull(i,l,r);
}
