#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
  int n,q;
  int cnt=1;
  vector<int> num;
  bool vis[10005]={0};
  int i;
  while(cin>>n>>q){
    if(!n && !q)break;
    num.clear();
    num.resize(n);
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
      cin>>num[i];
      vis[num[i]]=1;
    }
    sort(num.begin(),num.end());
    cout<<"CASE# "<<cnt++<<":"<<'\n';
    while(q--){
      cin>>i;
      if(!vis[i]){
        cout<<i<<" not found\n";
      }
      else{
        cout<<i<<" found at "<<find(num.begin(),num.end(),i)-num.begin()+1<<'\n';
      }
    }
  } 
}
