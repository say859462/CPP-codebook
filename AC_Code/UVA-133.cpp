#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;
int main(){
    //cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int n,k,m;
    bool vis[25]={0};
    vector<int>ans[25];
    while(cin>>n>>k>>m){
        if(n==0&&k==0&&m==0)break;
        int size=0;
        memset(vis,0,sizeof(vis));
        
       int total=0;
       int c1,c2,p1=n-1,p2=0;
        //n n-1 ......... 2 1
       while(total!=n){
            c1=c2=0;
            while(1){
                if(!vis[p2])c1++;
                if(c1==k)break;
                p2=(p2+1)%n;//counter clockwise
            }
            while(1){
                if(!vis[p1])c2++;
                if(c2==m)break;
                p1=(p1+(n-1))%n;
            }
            if(p1==p2){
                total++;
                vis[p1]=1;
                printf("%3d%s",p1+1,total==n?"":",");
            }
            else{
                total+=2;
                vis[p1]=vis[p2]=1;
                printf("%3d%3d%s",p2+1, p1+1, total == n ? "" : ",");
            }   
       }
       cout<<'\n';
    }
    return 0;
}
