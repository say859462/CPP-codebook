#include <iostream>
using namespace std;
int dp[45]={0};
void solve(){

  dp[1]=0;
  dp[2]=1;
  dp[3]=2;
  for(int i=4;i<=40;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  return ;
}
int main(){
  cin.tie(0);ios::sync_with_stdio(0);
  int n,x;
  solve();
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    cout<<dp[x]<<'\n';
  }
  return 0;
}
