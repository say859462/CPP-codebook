#include <iostream>
#define ll long long 
using namespace std;
ll dp[25][2]={0};//dp[i][0]前i個人排列 結尾為高低的方法數 dp[i][1]前i個人排列 結尾為低高的方法數
ll sum[25]={0};//i個人的排列方式
ll cal(ll x){
    ll ans=1;
    while(x!=0){
        ans*=x;
        x--;
    }
    return ans;
}
ll C(ll x,ll y){//C(x,y)
    return cal(x)/cal(x-y)/cal(y);
}
void init(){
    dp[0][0]=dp[0][1]=1;
    dp[1][0]=dp[1][1]=1;
    sum[1]=1;
    for(int i=2;i<=20;i++){//當前有i個人要排列
        sum[i]=0;
        for(int j=1;j<=i;j++){//將第i個人放置j位置
           sum[i]+=dp[j-1][0]*dp[i-j][1]*C(i-1,j-1);//前j-1個人的人選
        }
        dp[i][0]=dp[i][1]=sum[i]/2;//低高潔偉和高低結尾各站一半
    }
    return ;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    init();
    int t;
    cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        cout<<n<<" "<<sum[m]<<'\n';
    }
    return 0;
}
