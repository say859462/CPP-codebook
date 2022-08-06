#include <iostream>
#include <cstring>
using namespace std;
int coin[5]={1,5,10,25,50};
int dp[105][300]={0};//dp[i][j]用i個硬幣換j幣值的方式
void solve(){
  dp[0][0]=1;
  for(int k=0;k<5;k++){
    for(int i=1;i<=100;i++){//硬幣數量
      for(int j=coin[k];j<=250;j++){//當前幣值
        dp[i][j]+=dp[i-1][j-coin[k]];
      }
    } 
  }
  return ;
}
int main(){
  cin.tie(0);ios::sync_with_stdio(0);
  solve();
  int x;
  int ans=0;
  while(cin>>x){
    ans=0;
    for(int i=0;i<=100;i++){
      ans+=dp[i][x];
    }
    cout<<ans<<'\n';
  }
  return 0;
}
