#include <iostream>
#include <string>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  string s,t;
  while(cin>>s>>t){
    int cnt=0;
    for(int i=0;i<t.size();i++){
      if(t[i]==s[cnt]){
        cnt++;
      }
    }
    if(cnt!=s.size())cout<<"No"<<'\n';
    else cout<<"Yes"<<'\n';
  }
}
