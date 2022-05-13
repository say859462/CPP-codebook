#include <iostream>
using namespace std;
struct Treap{
    int key,pri,sz;     //key,priority,size
    int tag;//用於翻轉區間、單點詢問
    Treap *l, *r;       //左右子樹
    Treap(){}
    Treap(_key){
        key = _key;
        pri = rand();   //隨機的數維持樹的平衡
        sz  = 1;
        l = r = nullptr;
    }
};
Treap *root=new Treap;
int Size(Treap *x){return x? x->sz:0;}
void pull(Treap *x){x->sz= Size(x->l) +Size(x->r)+1; }//用於區間加值 內部程式碼依題目要求更改

//記得在Treap結構裡加入變數tag
void push(Treap* x){//翻轉後中序輸出
    if(x->tag){                      //如果區間要翻轉
        swap(x->l,x->r);             //交換左右子樹
        if(x->l)    x->l->tag ^= 1;  //加tag到左子樹
        if(x->r)    x->r->tag ^= 1;  //加tag到右子樹
        x->tag = NO_TAG;
    }
}

//左邊Treap的key(value)需<=右邊的Treap 
Treap *merge(Treap *a, Treap *b){
  if(!a||!b) return a?a:b;
  if(a->pri>b->pri){
    a->r=merge(a->r,b);
    pull(a);
    return a;
  }
  else{
    b->l=merge(a,b->l);
    pull(b);
    return b;
  }
}
//x 欲分割Treap
void splitByKey(Treap *x,int k,Treap* &a,Treap* &b){
    if(!x){ a=b=nullptr; }
    else if(x->val<=k){//自己本身以及左子樹均小於等於k
      a=x;
      splitByKey(x->r,k,a->r,b);
      pull(a);
    }
    else{
      b=x;
      splitByKey(x->l,k,a,b->l);
      pull(b);
    }
}
//希望左邊Treap大小為k個 右邊為n-k個
void splitByKth(Treap *x,int k,Treap* &a,Treap* &b){
  if(!x){ a=b=nullptr;}
  else if(Size(x->l)+1<=k){ //若自己+左子樹<=k個
    a=x;
    splitByKth(x->r,k-Size(x->l)-1,a->r,b);
    pull(a);
  }
  else{
    b=x;
    splitByKth(x->l,k,a,b->l);
    pull(b);
  }
}
void insert(int val){             //新增一個值為val的元素
    Treap *x = new Treap(val);    //設一個treap節點
    Treap *l,*r;
    splitByKey(root, val, l, r);  //找到新節點要放的位置
    root = merge(merge(l,x),r);   //合併到原本的treap裡
}                                 
void erase(int val){              //移除所有值為val的元素
    Treap *l,*mid,*r;
    splitByKey(root, val, l, r);  //把小於等於val的丟到l
    splitByKey(l, val-1, l, mid); //小於val的丟到l,等於val的就會在mid裡
    root = merge(l,r);            //將除了val以外的值合併
}
void cut(int ql,int qr){//欲翻轉區間 ，split函式根據依照kth分割或者key分割而有所變動
    push(root);
    Treap *l,*mid,*r,*tmp;
    split(root,ql-1,l,tmp);//l=[1~ql-1] tmp=[ql~n]
    split(tmp,qr-ql+1,mid,r);// mid=[ql~qr] r=[qr+1~n]
    mid->tag^=1;
    root=merge(merge(l,mid),r);
    return ;
}
