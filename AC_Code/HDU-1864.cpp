#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
vector<double>val;
double dp[35]={0};//dp[i]前i個物品 能報銷的最大金額
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    double  q,x;
    int n,m;
    char a,b;
    while(cin>>q>>n && n){
        val.clear();
        memset(dp,0,sizeof(dp));
        for(int i=0,cnt=1;i<n;i++){
            cin>>m;
            bool flag=1;
            int A=0,B=0,C=0;
            for(int j=0;j<m;j++){
                cin>>a>>b>>x;
                x*=100;
                //cout<<a<<'\n';
                if(a=='A'){
                    A+=x;
                }
                else if(a=='B'){
                    B+=x;
                }
                else if(a=='C'){
                    C+=x;
                }
                else flag=0;
            }
            if(flag&&(A+C+B)<=100000&&A<=60000&&B<=60000&&C<=60000)val.push_back(A+B+C);//單張金額不超過1k且每個物件少於等於600
        }
        dp[0]=val[0];
        for(int i=1;i<val.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]+val[i]<=int(q*100))dp[i]=max(dp[i],dp[j]+val[i]);
            }
        }
        double ans=0;
        for(int i=0;i<val.size();i++){
            ans=max(ans,dp[i]);
        }
        cout<<fixed<<setprecision(2)<<(double)ans/100<<'\n';
    }
    return 0;
}
