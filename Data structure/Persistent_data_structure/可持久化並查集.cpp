struct node{
    node *l,*r;
    int fa,dep;
};
int d[mx]={0};//節點i的深度 越深代表集合大小越大
vector<node *>version;
node *root=new node;
void build(node *cur,int l,int r){
    if(l==r){
        cur->fa=l;
        cur->dep=1;
        d[l]=1;
        return ;
    }
    int mid=(l+r)>>1;
    cur->l=new node;
    cur->r=new node;
    build(cur->l,l,mid);
    build(cur->r,mid+1,r);
    return ;
}

node* update(node *pre,int l,int r,int pos,int val){//將pos的父節點改為val (將集合pos 合併到val集合) 使得節點pos 的父節點為val
    node *x=new node;
    if(l==r){
        x->fa=val;
        x->dep=pre->dep;
        d[l]=pre->dep;
        return x;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        x->r=pre->r;
        x->l=update(pre->l,l,mid,pos,val);
    }
    else{
        x->l=pre->l;
        x->r=update(pre->r,mid+1,r,pos,val);
    }
    return x;
}  
int query(node *rt,int l,int r,int pos){//尋找pos的父節點
    if(l==r){
        return rt->fa;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) return query(rt->l,l,mid,pos);
    else return query(rt->r,mid+1,r,pos);
}

int find(int x){//尋找節點x的父節點 
    int f=query(root,1,n,x);
    if(f==x) return x;//若不能再往上找父節點 代表為該集合根結點
    return  find(f);
}

void add_dep(node *rt,int l,int r,int pos){//將結點pos 的深度+1 (k集合 合併到 pos集合上)
    if(l==r){
        d[pos]++;
        rt->dep++;
        return ;
    }
    int mid=(l+r)>>1;

    if(pos<=mid) add_dep(rt->l,l,mid,pos);

    else add_dep(rt->r,mid+1,r,pos);

    return ;
}
int mian(){
  int f1=find(a),f2=find(b);
  //cout<<f1<<" "<<f2<<'\n';
  if(d[f1]>d[f2]) swap(f1,f2);
  root=update(root,1,n,f1,f2);
  if(d[f1]==d[f2]) add_dep(root,1,n,f2);
  version.push_back(root);
}
