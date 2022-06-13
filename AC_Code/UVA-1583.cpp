#include <iostream>
using namespace std;
const int mx=1e5+10;
int a[mx]={0};
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  for(int i=0;i<=1e5;i++){
    int sum=i;
    int tmp=i;
    while(tmp){
      sum+=(tmp%10);
      tmp/=10;
    }
    a[i]=sum;
  }
  
  int t;
  int n;
  cin>>t;
  while(t--){
    cin>>n;
    bool flag=1;
    for(int i=0;i<=n;i++){
      if(a[i]==n){
        cout<<i<<'\n';
        flag=0;
        break;
      }
    }
    if(flag)cout<<0<<'\n';
  }
  return 0;
}
