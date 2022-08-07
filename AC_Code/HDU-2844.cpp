#include <bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int a[mx]={0},c[mx]={0};
int dp[mx]{0};//dp[i] i元有幾種組合
vector<int>val;
int main(){

    cin.tie(0);ios::sync_with_stdio(0);
    int n,m;

    while(cin>>n>>m){
        
        if(n==0 && m==0)break;
        val.clear();
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)  cin>>a[i];
        for(int i=1;i<=n;i++)  cin>>c[i];
        
        for(int i=1;i<=n;i++){
            int t=1;
            while(c[i]){
                if(c[i]-t<0)break;
                val.push_back(t*a[i]);
                c[i]-=t;
                t<<=1;
            }
            if(c[i])val.push_back(c[i]*a[i]);
        }
    
        for(int i=0;i<val.size();i++){
            for(int j=m;j>=val[i];j--){
                dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        int sum=0;
        for(int i=1;i<=m;i++){
            if(i==dp[i])sum++;
        }
        cout<<sum<<'\n';
    }

    return 0;
}
