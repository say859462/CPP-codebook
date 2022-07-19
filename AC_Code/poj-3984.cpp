#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mp[5][5]={0};
int mov[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[5][5]={0};
map<pair<int,int>,pair<int,int>>road;
bool check(int i,int j){
    if(i<0||i>4||j<0||j>4||mp[i][j]==1||vis[i][j])return 0;
    return 1;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>mp[i][j];
        }
    }
    queue<pair<int,int>>q;
    pair<int,int>start=make_pair(0,0);
    q.push(start);
    pair<int,int>end=make_pair(4,4);
    while(!q.empty()){
        pair<int,int>rec=q.front();q.pop();
        if(rec==end)break;
        vis[rec.first][rec.second]=1;
        bool flag=1;
        for(int i=0;i<4;i++){
            int x=rec.first+mov[i][0];
            int y=rec.second+mov[i][1];
            if(check(x,y)){
                q.push(make_pair(x,y));
                road[make_pair(x,y)]=rec;
            }
        }
    }
    vector<pair<int,int>>ans;
    pair<int,int>tmp=road[end];
    ans.push_back(end);
    while(tmp!=start){
        ans.push_back(tmp);
        tmp=road[tmp];
    }
    ans.push_back(start);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<"("<<ans[i].first<<", "<<ans[i].second<<")"<<'\n';
    }
    return 0;
}
