int build(int id, int lx, int rx, int ly, int ry){
    if(lx > rx || ly > ry)    return 0;
    if(lx == rx && ly == ry){
        return tree[id] = a[lx][ly];
    }
    int mx = (lx + rx)/2, my = (ly + ry)/2;
    tree[id] += build(id*4  , lx, mx, ly, my);
    tree[id] += build(id*4+1, mx+1, rx, ly, my);
    tree[id] += build(id*4+2, lx, mx, my+1, ry);
    tree[id] += build(id*4+3, mx+1, rx, my+1, ry);
    return tree[id];
}
void update(int id, int lx, int rx, int ly, int ry){
    push(id, lx, rx, ly, ry);
    if(qlx <= lx && rx <= qrx && qly <= ly && ry <= qry){
        tag[id] += val;
        return;
    }
    int mx = (lx + rx)/2, my = (ly + ry)/2;
    if(qlx <= mx && qly <= my)
        update(id*4  , lx, mx, ly, my);
    if(qrx >  mx && qly <= my)
        update(id*4+1, mx+1, rx, ly, my);
    if(qlx <= mx && qry > my)
        update(id*4+2, lx, mx, my+1, ry);
    if(qrx >  mx && qry > my)
        update(id*4+3, mx+1, rx, my+1, ry);
    pull(id, lx, rx, ly, ry);
}
	int query(int id, int lx, int rx, int ly, int ry){
    push(id, lx, rx, ly, ry);
    if(qlx <= lx && rx <= qrx && qly <= ly && ry <= qry){
        return tree[id];
    }
    int mx = (lx + rx)/2, my = (ly + ry)/2, ret = 0;
    if(qlx <= mx && qly <= my)
        ret += query(id*4  , lx, mx, ly, my);
    if(qrx >  mx && qly <= my)
        ret += query(id*4+1, mx+1, rx, ly, my);
    if(qlx <= mx && qry > my)
        ret += query(id*4+2, lx, mx, my+1, ry);
    if(qrx >  mx && qry > my)
        ret += query(id*4+3, mx+1, rx, my+1, ry);
    return ret;
}
