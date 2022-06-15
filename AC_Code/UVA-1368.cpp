#include <iostream>
#include <cstring>
using namespace std;
char rec[5]="ACGT";
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int t;
  cin>>t;
  int n,len;
  while(t--){
    cin>>n>>len;
    char dna[55][1005]={};

    for(int i=1;i<=n;i++){
      cin>>dna[i];
    }
    int cnt[4]={0};
    int sum=0;
    for(int i=0;i<len;i++){
      
      memset(cnt,0,sizeof(cnt));
      for(int j=1;j<=n;j++){
        if(dna[j][i]=='A')cnt[0]++;
        else if(dna[j][i]=='C')cnt[1]++;
        else if(dna[j][i]=='G')cnt[2]++;
        else cnt[3]++;
      }
      int mx=0;
      int ans=0;
      for(int k=0;k<4;k++){
       if(cnt[k]>mx){
         ans=k;
         mx=cnt[k];
       }
      }
      sum+=(n-mx);
      cout<<rec[ans];
    }
    cout<<'\n';
    cout<<sum<<'\n';
  }
}
