#include <iostream>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int t;
  cin>>t;
  string a;
  while(t--){
    cin>>a;
    int cnt=1;
    int ans=0;
    for(int i=0;i<a.size();i++){
      if(a[i]=='X'){
        cnt=1;
      }
      else{
        ans+=cnt;
        cnt++;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
