#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  string s;
  set<string>ans;
  char ch;
  while((ch=getchar())!=EOF){
    
    if(isalpha(ch))s+=tolower(ch);
    else{
      ans.insert(s);
      s="";
    }
  }
  set<string>::iterator it=ans.begin();
  for(;it!=ans.end();it++){
    if(*it!="")
      cout<<*it<<'\n';
  }
  return 0;
}
