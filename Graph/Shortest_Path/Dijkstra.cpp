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
