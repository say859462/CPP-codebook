#include <iostream>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int t;
  cin>>t;
  string a;
  while(t--){
    cin>>a;
    for(int i=1;i<=a.length();i++){
      string cmp=a.substr(0,i);
      bool flag=0;
      if(a.size()%i)continue;
      for(int j=0;j<a.size();j+=i){
        string tmp=a.substr(j,i);
        if(tmp!=cmp){
          flag=1;
          break;
        }
      }
      if(!flag){
        cout<<i<<'\n';
        break;
      }
    }
    if(t)cout<<'\n';
  }
}
