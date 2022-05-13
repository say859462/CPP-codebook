#include <iostream>
#include <vector>
using namespace std;

struct node{
    ll val;
    node *l, *r;
};
 
vector<node *> version;    //用一個vector紀錄全部版本的根節點
 
void build(node *now_version, l, r);

ll query(node *now_version, l, r, ql, qr);

node *update_version(node *pre_version,int l,int r,int pos,int v); //回傳新建的節點
 

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
        x->l = update(pre_version->l, l, mid, pos, v); //左邊節點連向新節點
        x->r = pre->version->r;                        //右邊連到原本的右邊
    }
    else{ //更新右邊
        x->l = pre->version->l;                         //左邊連到原本的左邊
        x->r = update(pre_version->r, r, mid, pos, v);  //右邊節點連向新節點
    }
    x->val = x->l->val + x->r->val;
    return x;
}
