#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int mx=205;
int add[mx]={0},sub[mx]={0};
int d[mx]={0},p[mx]={0};
int dp[25][805]={0};//dp[i][j]選取i個人 在\d(j)-p(j)\為j的情況下 \d(j)+p(j)\最大值
//dp[i][j]=-1時 代表無選取i個人的方案
vector<int>path[25][805];
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t=1;
    int n,m;
    while(cin>>n>>m&& n && m){
        for(int i=0;i<=n-1;i++){
            cin>>d[i]>>p[i];
            add[i]=d[i]+p[i];
            sub[i]=d[i]-p[i];
        }

        for(int i=0;i<=m;i++){
            for(int j=0;j<=801;j++){
                path[i][j].clear();
            }
        }

        memset(dp,-1,sizeof(dp));
        int offset=20*m;//偏移量 辯控差可能為負 須將[-20*m,20*m]映射為[0,40*m]
        dp[0][offset]=0;

        for(int k=0;k<n;k++){
            for(int i=m-1;i>=0;i--){
                for(int j=0;j<=2*offset-1;j++){
                    if(dp[i][j]>=0){//如果有可行的方案
                        if(dp[i+1][j+sub[k]]<=dp[i][j]+add[k]){
                            dp[i+1][j+sub[k]]=dp[i][j]+add[k];
                            path[i+1][j+sub[k]]=path[i][j];//當前最優解轉移路徑
                            path[i+1][j+sub[k]].push_back(k);//並加入當前更優的選擇方案人物
                        }
                    }
                }
            }
        }
        int i=0;
        for(;dp[m][offset+i]==-1&&dp[m][offset-i]==-1;i++);//找到第一個辯控差最小的方案
        //考慮兩個辯控差相同且都有合法方案 則比較辯控和誰比較大
        int tmp=dp[m][offset+i]>dp[m][offset-i]?i:-i;
        cout<<"Jury #"<<t++<<'\n';
        int sumd=0,sump=0;
        for(int j=0;j<=m-1;j++){
            sumd+=d[path[m][offset+tmp][j]];
            sump+=p[path[m][offset+tmp][j]];
        }
        cout<<"Best jury has value "<<sumd<<" for prosecution and value "<<sump<<" for defence: \n";
        for(int j=0;j<=m-1;j++)cout<<" "<<path[m][offset+tmp][j]+1;
        cout<<'\n'<<'\n';

    }


    return 0;
}
