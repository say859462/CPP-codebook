#include <iostream>
#include <cstring>
using namespace std;
char mp[10][10]={};
int n,k;
int ans=0;
bool row[10]={0};
void dfs(int cur,int total){
    if(cur>n||total==k){
        if(total==k){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        
            if(!row[i]&&mp[i][cur]=='#'){
                row[i]=1;
                dfs(cur+1,total+1);
                row[i]=0;
            }
        
    }
    dfs(cur+1,total);//換下一列作為開始
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    
    while(cin>>n>>k){
        if(n==-1&&k==-1)break;
        ans=0;
        memset(mp,'\0',sizeof(mp));
        memset(row,0,sizeof(row));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mp[i][j];
            }
        }
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
