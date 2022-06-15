#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int>&a, const pair<int,int>&b){
  if(a.first==b.first)return a.second<b.second;
  return a.first<b.first;
}
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int w,h;
  while(cin>>w>>h){
    if(w>h)swap(w,h);
    vector<pair<int,int>>rec;
    rec.push_back(make_pair(w,h));
    for(int i=0;i<5;i++){
      cin>>w>>h;
      if(w>h)swap(w,h);
      rec.push_back(make_pair(w,h));
    }
    sort(rec.begin(),rec.end(),cmp);//排序後，面由短邊從小排到大
    bool flag=0;  
    for(int i=0;i<6;i+=2){
      if(rec[i].first!=rec[i+1].first || rec[i].second!=rec[i+1].second)flag=1;//兩相同的面邊要相同
    }

    if(rec[0].first!=rec[2].first || rec[0].second!=rec[4].first || rec[2].second!=rec[4].second)flag=1;//考慮最小面的短長邊要與另外兩面的短邊相同
    if(flag)cout<<"IMPOSSIBLE"<<'\n';
    else cout<<"POSSIBLE"<<'\n';
  }
  return 0;
}
