int lowbit(int x){return x&(-x); }
void update(int r,int c,int val){
  for(int i=r;i<=n;i+=lowbit(i)){
    for(int j=c;j<=n;j+=lowbit(j)){
      BIT[i][j]+=val;
    }
  }
  return ;
}
int query(int r,int c){
  int rec=0;
  for(int i=r;i;i-=lowbit(i)){
    for(int j=c;j;j-=lowbit(j)){
      rec+=BIT[i][j];
    }
  }
  return rec;
}
