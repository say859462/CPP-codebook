#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>num;
    int cnt[10]={0};  
    for(int i=1;i<=n;i++){
      num.push_back(i);
    }
    for(int i=0;i<num.size();i++){
      while(num[i]){
        cnt[num[i]%10]++;
        num[i]/=10;
      }
    }
    for(int i=0;i<=9;i++){
      if(i==9)cout<<cnt[i];
      else cout<<cnt[i]<<" ";
    }
    cout<<'\n';
  }
}
