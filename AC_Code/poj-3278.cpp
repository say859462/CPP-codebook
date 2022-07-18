#include <iostream>
#include <queue>
using namespace std;
int n,k;
const int INF=0x3f3f3f3f;
const int mx=1e5+10;
bool vis[mx]={0};
int bfs(){
    queue< pair<int,int> >q;
    q.push(make_pair(n,0));
    vis[n]=1;
    while(!q.empty()){
        pair<int,int>rec=q.front();q.pop();
        vis[rec.first]=1;
        if(rec.first==k)return rec.second;
        if(rec.first+1>=0&&rec.first+1<=100000&&!vis[rec.first+1]){
            q.push(make_pair(rec.first+1,rec.second+1));
        }
        if(rec.first-1>=0&&rec.first-1<=100000&&!vis[rec.first-1]){
            q.push(make_pair(rec.first-1,rec.second+1));
        }
        if(rec.first*2>=0&&rec.first*2<=100000&&!vis[2*rec.first]){
            q.push(make_pair(rec.first*2,rec.second+1));
        }
    }
    return 0;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>n>>k;
    cout<<bfs()<<'\n';
    return 0;
}
