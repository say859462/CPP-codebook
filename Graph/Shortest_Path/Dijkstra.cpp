void dijkstra()
{

	for (int i = 0; i <= vertice; i++)//initialize
	{
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[A] = 0;

	while (1)
	{
		int idx = -1;
		int mx = INF;
		for (int i = 0; i <= vertice; i++)
		{
			if (!vis[i] && dis[i] < mx)
			{
				idx = i, mx = dis[i];
			}
		}
		if (idx == -1)
			break;
		vis[idx] = 1;
		for (int i = 0; i < node[idx].size(); i++)
		{
			int u = node[idx][i];
			int weight = w[idx][u];
			if (dis[u] > dis[idx] + weight)
			{
				dis[u] = dis[idx] + weight;
			}
		}
	}
}
//優化版
init();
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
 
pq.push(make_pair(dis[start], start)); // 為了方便實作，用pair包起來會先比較距離大小
 
while(!pq.empty()){
    auto [d, u] = pq.top(); pq.pop();
    if(vis[u])    continue;  // 確保每個點最多只被走過一遍
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){  // 窮舉此點所有連到的點
        int v = edge[u][i].to, w = edge[u][i].weight;
        if(dis[v] > dis[u] + w){
            dis[v] = dis[u] + w;  // 鬆弛
            pq.push(make_pair(dis[v], v)); // 如果有更新距離，則丟進 priority_queue
        }
    }
}
