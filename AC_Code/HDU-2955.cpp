//HDU-2955 0/1knapsack+percent transform + opsite thinking
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int mx=1e2+10;
int val[mx]={0};
double pr[mx]={0};
double dp[10005]={0};//dp[i] 拿到i元不被抓的機率
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
    cin>>t;
    double p;
    int n;
    double tmp;
    while(t--){
        cin>>p>>n;
        p=1-p;
        memset(pr,0,sizeof(pr));
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        int sum=0;
        for(int i=1;i<=n;i++) {
            cin>>val[i]>>pr[i];
            pr[i]=1-pr[i];//不被抓的機率
            sum+=val[i];
        }
        dp[0]=1;//不拿錢100%可以
        for(int i=1;i<=n;i++){
            for(int j=sum;j>=val[i];j--){
                dp[j]=max(dp[j],dp[j-val[i]]*pr[i]);
            }
        }
        for(int i=sum;i>=0;i--){
            if(dp[i]>=p){
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}
