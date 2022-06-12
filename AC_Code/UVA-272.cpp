#include <iostream>
#include <string>
using namespace std;
string c[2]={"``","''"};
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  string n;
  int cnt=0;
  while(getline(cin,n)){
    
    for(int i=0;i<n.size();i++){
      if(n[i]=='"'){
        cout<<c[cnt%2];
        cnt++;
      }
      else cout<<n[i];
    }
    cout<<'\n';
  }
  return 0;
}
