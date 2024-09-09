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

void dijkstra()
{
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
}



class Solution
{   
    #define pii pair<int,int>
    //Dijstra's Alg
	public:
	const int INF = 0x3f3f3f3f;
	int dis[1005] = {0} ; //shortest path from source node to i if dis[i]
	bool vis[1005] = {0}; //if it is visited
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        for(int i=0;i<V;i++)
            dis[i] = INF;
        
        dis[S] = 0;
        priority_queue< pii,vector<pii>,greater<pii> > pq;
        pq.push(make_pair(0,S));
        
        
        while(!pq.empty()){//O(V)
            
            pair<int,int> top = pq.top(); //(logE)
            pq.pop();
            int w = top.first;
            int v = top.second;
            
            if(vis[v])
                continue;
            
            vis[v] = true;
            
            //relaxing the determined shortest path node
            for(auto j : adj[v]){
                int u = j[0];
                int w = j[1];
                
                if(dis[v] + w < dis[u]){
                    dis[u] = dis[v] + w;
                }
                
                pq.push(make_pair(dis[u],u));
            }
            
            
        }
        
        vector<int>ans ; 
        for(int i=0;i<V;i++)
            ans.push_back(dis[i]);
        
        return ans;
    }
};
