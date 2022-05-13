int dis[N][N];
void init(){
	for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        if(i != j)
            dis[i][j] = INF;
        else
            dis[i][j] = 0;
    }
}
}
for(int k = 0; k < n; k++){ // 窮舉中繼點 k
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ // 窮舉點對 (i, j)
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        }
    }
}
