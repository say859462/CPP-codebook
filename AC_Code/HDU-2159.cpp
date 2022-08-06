#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int mx=1e2+50;
int val[mx]={0},w[mx]={0};
int dp[mx][mx]={0};//dp[i][j]殺掉j個怪 消耗i忍耐度所獲得的最大經驗值
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n,m,k,s;
    while(cin>>n>>m>>k>>s){

        memset(val,0,sizeof(val));
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=k;i++) cin>>val[i]>>w[i];

        for(int i=1;i<=k;i++){
            for(int j=w[i];j<=m;j++){//當前容忍度
                for(int l=1;l<=s;l++){
                    dp[j][l]=max(dp[j][l],dp[j-w[i]][l-1]+val[i]);
                }
            }
        }
        int ans=-1;
        for(int i=0;i<=m&&ans==-1;i++){//窮舉花費最少容忍度且滿足經驗值條件的
            for(int j=0;j<=s;j++){
                if(dp[i][j]>=n){
                    ans=i;
                    break;
                }
            }
        }
        if(ans==-1)cout<<-1<<'\n';
        else cout<<m-ans<<'\n';
    }


    return 0;
}
