
vector<tuple<int,int,int>> version;

merge(int x,int y){
    x = find(x);
    y = find(y);
    if(sz[x] > sz[y]){
        version.push_back({x,sz[x],y,fa[y]});
        sz[x] += sz[y];
        fa[y] = x;
    }
    else{
        sz[y] += sz[x];
        fa[x] = y;
        version.push_back({y,sz[y],x,fa[x]});
    }
}
void undo(int k=1){    //回復 k 次
    auto [u,s,v,f] = version.back();
    version.pop_back();
    sz[u] = s;
    fa[v] = f;
}
