#include <iostream>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){

    string tmp;

    cin>>tmp;

    string ans=tmp;

    int len=tmp.size();
    for(int i=1;i<len;i++){
      string cmp=tmp.substr(i,len-i);
      string add=tmp.substr(0,i);
      if(cmp+add<ans){
        ans=cmp+add;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
