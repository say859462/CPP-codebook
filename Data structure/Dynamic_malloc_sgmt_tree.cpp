#define NO_TAG 0
struct node{
    node *l, *r;
    int val,tag;
};

void push(node *x){
  if(x->tag){
    if(!x->l){
      x->l=new node;
    }
    if(!x->r){
      x->r=new node;
    }
    x->l->tag=x->tag;
    x->r->tag=x->tag;
    x->tag=0;
  } 
  return ;
}
void pull(node *x){
  if(x->l){
    x->val=x->l->val;
  }
  if(x->r){
    x->val+=x->r->val;
  }
  return ;
}
void update(node *x, int l, int r, int ql, int qr, int v){
    push(x);
    if(ql <= l &&  r <= qr){
        x->tag += v;
        return;
    }
    int mid=(l+r)>>1;
    if(ql <= mid){
        if(x->l == nullptr)    x->l = new node(); //判斷是否有節點
        update(x->l, l , mid, ql, qr, v);
    }
    if(qr >  mid){
        if(x->r == nullptr)    x->r = new node(); //判斷是否有節點
        update(x->r, mid+1, r, ql, qr, v);
    }
    pull(x);
}
