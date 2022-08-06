#include <iostream>
#define ll long long
using namespace std;
ll dp[60]={0};//dp[i] 第i年有的母牛數量
void init(){  
   dp[1]=1;
   dp[2]=2;
   dp[3]=3;
   dp[4]=4;
  for(int i=5;i<=55;i++){
    dp[i]=dp[i-1]+dp[i-3];
  }
  return ;
}
int main(){

  cin.tie(0);ios::sync_with_stdio(0);
  init();
  int n;
  while(cin>>n && n){
    cout<<dp[n]<<'\n';
  }
  
  return 0;
}
