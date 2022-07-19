
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n,m;
    char mp[105][105]={};
    int mov[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int ans=0;
    int x,y;
    while(cin>>n>>m){

        if(!n&&!m)break;
        memset(mp,'\0',sizeof(mp));
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='@'){
                    queue<pair<int,int>>q;
                    ans++;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> rec=q.front();q.pop();
                        mp[rec.first][rec.second]='*';
                        for(int k=0;k<8;k++){
                            x=rec.first+mov[k][0];
                            y=rec.second+mov[k][1];
                            if(i>=1&&i<=n&&j>=1&&j<=m&&mp[x][y]=='@'){
                                q.push(make_pair(x,y));
                                mp[x][y]='*';
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
