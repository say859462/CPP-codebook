#include <iostream>
#include <vector>
using namespace std;

struct node{
    ll val;
    node *l, *r;
};
 
vector<node *> version;    //用一個vector紀錄全部版本的根節點
 
void build(node *now_version, l, r){
    if(l==r){   
        now_version->w=0;
        return ;
    }
    int mid=(l+r)>>1;
    now_version->l=getnode();
    now_version->r=getnode();
    build(now_version->l,l,mid);
    build(now_version->r,mid+1,r);
    now_version->w=0;
    return ;
}

int query(node *cur,int l,int r,int pos){//查詢最後出現版本小於POS的數值
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(cur->l->w<pos)return query(cur->l,l,mid,pos);//若左子節點版本數<pos(ql)
    else return query(cur->r,mid+1,r,pos);
}


 

void add_version(int x,int v){    //修改位置 x 的值為 v
    version.push_back(update_version(version.back(), 0, n-1, x, v));
}

node *update_version(node *pre_version, l, r, pos, v){
    node *x = new node();    //當前位置建立新節點
    if(l == r){
        x->val = v;
        return x;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){ //更新左邊
        x->l = update(pre->l, l, mid, pos, v); //左邊節點連向新節點
        x->r = pre->version->r;                        //右邊連到原本的右邊
    }
    else{ //更新右邊
        x->l = pre->l;                         //左邊連到原本的左邊
        x->r = update(pre->r, r, mid, pos, v);  //右邊節點連向新節點
    }
    x->val = x->l->val + x->r->val;
    return x;
}
