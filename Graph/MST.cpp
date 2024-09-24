class Solution
{	
// Kruskal's Alg
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	const int MXN = 1005;
	int p[MXN]={0};
	int rank[MXN]={0};
	
	void umerge(int a,int b){
	    
	    int u = ufind(a);
	    int v= ufind(b);
	    
	    if(rank[u]>=rank[v]){
	         p[v] = u;
	         rank[v] += rank[u];
	         return ;
	    }
	       
	    p[u]=v;
	    rank[u]+=rank[v];
	    
	}
	
	int ufind(int a){
	    if(a==p[a])
	        return a;
	    return p[a] = ufind(p[a]);
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int edge  = V-1;
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++)
            p[i] = i;
        
        for(int i=0;i<V;i++){
            for(vector<int> j: adj[i]){
                edges.push_back(make_pair(j[1],make_pair(i,j[0])));
            }
        }
        
        sort(edges.begin(),edges.end());
        
        
        int idx = 0;
        int ans = 0;
        while(edge && idx<edges.size()){ 
            
            int u = edges[idx].second.first;
            int v = edges[idx].second.second; 
            int w = edges[idx].first;
            
            if(ufind(u)!=ufind(v)){
                umerge(u,v);
                edge--;
                ans+=w;
            }
            
            idx++;
        }   
        
        
        return ans;
       
    }
    
};


class Solution
{   
    
    //Prim's Alg O()
    #define pii pair<int,int>
	public:
	const int INF = 0x3f3f3f3f;
	bool vis[1005] = {0}; // vis[i] : true:node i is already in MST ,I/O
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        

        
        //use priority_queue to maintain the shortest distance from node to MST
        priority_queue< pii,vector<pii>,greater<pii> > pq;
        
        pq.push(make_pair(0,0));
        
        int times = V;
        
        // O(VlogV) + O(ElogV)
        while(times){
            
            //select the minimum distance from that node to MST
            pair<int,int> top = pq.top();        
            pq.pop();
            int u = top.second;
            int w = top.first;
            
            // pass that node which is already visited
            if(vis[u])
                continue;
            
            vis[u] = true;
            ans+=w;
            
            for(auto j:adj[u]){
                
                int v = j[0];
                int w2 = j[1];
                
                if(vis[v])
                    continue;
                
                pq.push(make_pair(w2,v));
                
                
            }
            
            
            times--;
        }
        
        return ans;
        
    }
};
