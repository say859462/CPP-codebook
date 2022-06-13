#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int n;
  int cnt=1;
  while(cin>>n && n){

    cout<<"Game "<<cnt++<<":"<<'\n';
    vector<int>ans(n);
    int cnt1[10]={0};
    for(int i=0;i<n;i++){
      cin>>ans[i];
      cnt1[ans[i]]++;
    }

    vector<int>g(n);

    while(1){
      int r1=0;
      int r2=0;
      bool vis1[1005]={0};//ans
      bool vis2[1005]={0};//guess
      for(int i=0;i<n;i++){
        cin>>g[i];
      }
      if(!g[0])break;

      for(int i=0;i<n;i++){//cal pair(i,j)'s i
        if(ans[i]==g[i]){
          r1++;
          vis1[i]=vis2[i]=1;
        }
      }
      
      for(int i=0;i<n;i++){//窮舉每個還沒配對過的答案位置，去與猜測者也還沒配對過的位置，且位置不相同去找尋是否有相同的值
        if(!vis1[i]){
          for(int j=0;j<n;j++){
            if(i!=j && !vis2[j] && ans[i]==g[j]){
              r2++;
              vis2[j]=1;
              vis1[i]=1;
              break;
            }
          }
        }
      }
      cout<<"    ("<<r1<<","<<r2<<")"<<'\n';
    }

  }
  return 0;
}
