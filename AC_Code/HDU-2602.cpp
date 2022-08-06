#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int mx=1e3+10;
int val[mx]={0},vol[mx]={0};
int dp[2][mx]={0};
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
    cin>>t;
    int n,v;
    while(t--){
        cin>>n>>v;
        memset(val,0,sizeof(val));
        memset(vol,0,sizeof(vol));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)cin>>val[i];
        for(int i=1;i<=n;i++)cin>>vol[i];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=v;j++){
                dp[1][j]=dp[0][j];
                if(j>=vol[i])dp[1][j]=max(dp[0][j],dp[0][j-vol[i]]+val[i]);
            }
            swap(dp[1],dp[0]);
        }
        cout<<max(dp[0][v],dp[1][v])<<'\n';
    }
    return 0;
}
