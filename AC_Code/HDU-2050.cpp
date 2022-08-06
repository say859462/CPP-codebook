#include <iostream>
using namespace std;
int dp[10005]={0};
void solve(){

  dp[0]=1;
  dp[1]=2;
  for(int i=2;i<=10000;i++){
    dp[i]=dp[i-1]+2*(i-1)*2+1;
  }
  return ;
}
int main(){
  cin.tie(0);ios::sync_with_stdio(0);
  solve();
  int n,x;
  cin>>n;
  while(n--){
    cin>>x;
    cout<<dp[x]<<'\n';
  }
  return 0;
}
