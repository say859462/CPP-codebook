bool spfa(){
  queue<int>q;
  dis[1]=0;
  cnt[1]=1;
  q.push(1);
  while(!q.empty()){
    int u=q.front();q.pop();
    vis[u]=0;
    for(int i=0;i<edge[u].size();i++){
      int xx=edge[u][i].first;
      int yy=edge[u][i].second;
      if(dis[xx]>dis[u]+yy){
        dis[xx]=dis[u]+yy;
        cnt[xx]++;
        if(cnt[xx]>n)//return true;
        if(!vis[xx])q.push(xx);
      }
    }
  }
  //return false;
}
