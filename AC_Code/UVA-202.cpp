#include <iostream>
#include <cstring>
using namespace std;
int ans[10000]={0};
int vis[10000]={0};
// KEY:若被除數重複出現過，代表循環小數產生
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  int top,down;
  while(cin>>top>>down){
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    cout<<top<<"/"<<down<<" = "<<top/down<<".";
    top%=down;
    int cnt=1;//小數點後第cnt個位置

    while(!vis[top]){//紀錄被除數出現時間，若被除數已經出現過 代表循環了
      vis[top]=cnt;
      top*=10;
      ans[cnt++]=top/down;
      top%=down;
    }

    for(int i=1;i<vis[top];i++){//到第一次產生的被除數位置前，均不是循環小數的數字，先輸出
      cout<<ans[i];
    }
    cout<<"(";
    int length=cnt-vis[top];//第二次出現相同的被除數位置-第一次出現的位置
    if(length>50) cnt=51;
      for(int i=vis[top];i<cnt;i++){//輸出循環小數
        cout<<ans[i];
      }
    
    if(length>50)cout<<"...";
    cout<<")"<<'\n';
    cout<<"   "<<length<<" = number of digits in repeating cycle"<<'\n';
    cout<<'\n';
  }
  return 0;
}
