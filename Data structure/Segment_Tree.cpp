void pull(int idx){
    tree[idx]=max(tree[cl(idx)],tree[cr(idx)]);
    return ;
}
void push(int idx,int l,int r){
    if(tag[idx]){
        tree[cl(idx)]=tag[idx];
        tree[cr(idx)]=tag[idx];
        if(l!=r){
            tag[cl(idx)]=tag[idx];
            tag[cr(idx)]=tag[idx];
        }
        tag[idx]=0;
    }
    return ;
}
void build(int idx,int l,int r){
    if(l==r){
        cin>>tree[idx];
        return ;
    }
    int mid=(l+r)>>1;
    build(cl(idx),l,mid);
    build(cr(idx),mid+1,r);
    pull(idx);
    return ;
}
void update(int idx,int l,int r,int ql,int qr,ll val){
    push(idx,l,r);
    if(ql<=l && r<=qr){
        tree[idx]=val;
        tag[idx]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(ql<=mid)update(cl(idx),l,mid,ql,qr,val);
    if(qr>mid)update(cr(idx),mid+1,r,ql,qr,val);
    pull(idx);
    return ;
}
ll query(int idx,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        return tree[idx];
    }
    int mid=(l+r)>>1;
    push(idx,l,r);
    ll ans=0;
    if(ql<=mid)ans=max(ans,query(cl(idx),l,mid,ql,qr));
    if(qr>mid)ans=max(ans,query(cr(idx),mid+1,r,ql,qr));
    return ans;
}
