#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int mx=1e5+10;
int tin[mx];
int tou[mx];
vector<int>edge[mx];
int main(){
  int n;
  cin>>n;
  int u,v;
  for(int i=0;i<n;i++){
    cin>>u>>v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  queue<int>q;
  for(int i=0;i<n;i++){
    if(!tin[i]){
      q.push(i);
    }
  }
  vector<int>ans;
  while(!q.empty()){
    int t=q.front();q.pop();
    for(int i:edge[t]){
      tin[i]--;
      if(!tin[i]){
        q.push(i);
      }
    }
    ans.push_back(t);
  }
  
}
