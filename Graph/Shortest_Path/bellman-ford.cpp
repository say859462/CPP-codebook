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
class Solution {
    
  public:
    const int INF = 1e8;
    int dis[505] = {0};
    int cost[505][505];
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        // 初始化圖的邊與權重
        vector<int> e[505];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            cost[u][v] = w;
            e[u].push_back(v);
        }

        // 初始化所有頂點的距離
        for (int i = 0; i < V; i++)
            dis[i] = INF;
        
        dis[S] = 0; // 設定源點的距離為0
        
        // 進行 V-1 次 relax
        for (int times = 0; times < V - 1; times++) {
            bool next = false;
            for (int i = 0; i < V; i++) {
                for (int j : e[i]) {
                    if (dis[i] + cost[i][j] < dis[j]) {
                        dis[j] = dis[i] + cost[i][j];
                        next = true; // 有發生更新
                    }
                }
            }
            if (!next) break; // 如果沒有發生更新，提早結束
        }

        // 檢測負權重循環
        for (int i = 0; i < V; i++) {
            for (int j : e[i]) {
                if (dis[i] + cost[i][j] < dis[j]) {
                    // 如果在第 V 次還可以放鬆，則存在負權重循環
                    return { -1 };
                }
            }
        }

        // 將結果轉換為 vector 返回
        vector<int> ans;
        for (int i = 0; i < V; i++)
            ans.push_back(dis[i]);
        
        return ans;
    }
};
