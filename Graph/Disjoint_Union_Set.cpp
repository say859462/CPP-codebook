int f[MXN], sz[MXN]; // 多紀錄子樹大小
void merge(int x,int y){
    x = find(x), y =find(y);
    if(sz[x] < sz[y])    swap(x,y);
    sz[x] += sz[y];
    f[y] = x;
}
void init(){
    //初始化一開始大小都為1 (每群一開始都是獨立一個)
    for(int i=1;i<=n;i++)    sz[i] = 1;
    for(int i=1;i<=n;i++)    f[i] = i;
}
