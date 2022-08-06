#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[105]={0};
int dp[105][105]={0};//dp[i][j]走第i步到j位置能獲得的最大收益
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
    cin>>t;
    int n,a,b,k;
    while(t--){
        int ans=0;
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        cin>>n>>a>>b>>k;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
        
        for(int i=1;i<=k;i++){//當前第幾步
            for(int j=1;j<=n;j++){//前一位置
                for(int k=j+a;k<=n&&k<=j+b;k++){
                    dp[i][k]=max(dp[i][k],dp[i-1][j]+num[k]);
                }
            }
        }
        for(int i=1;i<=n;i++)ans=max(ans,dp[k][i]);
        cout<<ans+num[1]<<'\n';
    }
    return 0;
}
