for(int j = 0; j < n-1; j++){
    for(int i = 0; i < m; i++){ // 對於所有邊都嘗試鬆弛
        if(dis[ edge[i].to ] > dis[ edge[i].from ] + edge[i].weight){
            dis[ edge[i].to ] = dis[ edge[i].from ] + edge[i].weight;
        }
    }
}
//優化版
int len[N]; // 紀錄每個點是第幾輪被鬆弛到 共n個點，最多只會被鬆弛n-1次，超過n-1次代表有負環。
bool inque[N];
queue<int> que;
que.push(start);
while(!que.empty()){
    int u = que.front(); que.pop();
    if(len[u] > n-1)    return -1; // 超過 n-1 輪，找到負環
    inque[u] = 0;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i].to, w = edge[u][i].weight;
        if(!inque[v] && dis[v] > dis[u] + w){
            dis[v] = dis[u] + w;
            que.push(v);
            inque[v] = 1;
            len[v] = len[u] + 1; // 從來的點 +1輪被鬆弛到
        }
    }
}
