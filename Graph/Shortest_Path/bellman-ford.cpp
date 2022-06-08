	for(int j = 0; j < n-1; j++){
    for(int i = 0; i < m; i++){ // 對於所有邊都嘗試鬆弛
        if(dis[ edge[i].to ] > dis[ edge[i].from ] + edge[i].weight){
            dis[ edge[i].to ] = dis[ edge[i].from ] + edge[i].weight;
        }
    }
}
