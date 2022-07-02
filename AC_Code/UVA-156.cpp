#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<string,string>rec;//紀錄標準化字串的原字串
map<string,int> cnt;//紀錄該字串排序後出現次數
vector<string>ans;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  string tmp;
  while(cin>>tmp &&tmp!="#"){
    string s;
    for(int i=0;i<tmp.size();i++){
      s+=tolower(tmp[i]);
    }
    sort(s.begin(),s.end());
    cnt[s]++;
    rec[s]=tmp;
  }
  for(auto i:cnt){
    if(i.second==1){
      ans.push_back(rec[i.first]);
    }
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<'\n';
  }
}
