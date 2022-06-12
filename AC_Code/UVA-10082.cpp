#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;
char a[]="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  char c;
  int i;
  while( (c=getchar())!=EOF){
    for(i=1;a[i]&&a[i]!=c;i++);
    if(a[i])cout<<a[i-1];
    else cout<<c;
  }
  
  return 0;
}
