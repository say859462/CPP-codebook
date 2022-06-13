#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char al[]="A   3  HIL JM O   2TUVWXY5";
char num[]="1SE Z  8 ";
bool check1(string a){//pali
  int len=a.size();
  for(int i=0;i<a.size();i++){
    if(a[i]!=a[len-1-i])return false;
  }
  return true;
}
bool check2(string b){//mirror
  int len=b.size();
  for(int i=0;i<(1+len)/2;i++){
    if(b[i]>='A'&&b[i]<='Z'){
      if(al[b[i]-'A']!=b[len-i-1])return false;
      
    }
    else {
        if(num[b[i]-'1']!=b[len-i-1])return false;
      }
  }
  return true;
}
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  string n;
  while(cin>>n){
    if(check1(n)&&check2(n)){
      cout<<n<<" -- is a mirrored palindrome.";
    }
    else if(check1(n)){
      cout<<n<<" -- is a regular palindrome.";
    }
    else if(check2(n)){
      cout<<n<<" -- is a mirrored string.";
    }
    else{
      cout<<n<<" -- is not a palindrome.";
    }
    cout<<'\n'<<'\n';
  }
}
