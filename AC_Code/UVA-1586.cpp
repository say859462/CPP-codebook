#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
map<char,double>mp;
int main(){
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
  mp['C']=12.01;
  mp['H']=1.008;
  mp['O']=16.00;
  mp['N']=14.01;
  int t;
  cin>>t;
  string a;
  while(t--){
    cin>>a;
    vector<char>element;
    vector<int>num;
    int n=0;
    double ans=0;
    for(int i=0;i<a.size();i++){
      if(a[i]>='A'&&a[i]<='Z')element.push_back(a[i]);
    }
    bool flag=0;
    for(int i=0;i<a.size();i++){
      if(a[i]>='A'&&a[i]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'){
        num.push_back(1);
        continue;
      }
      if(i==a.size()-1&&a[i]>='A'&&a[i]<='Z')num.push_back(1);

      if(a[i]>='0'&&a[i]<='9'&&flag){
        for(int j=i;  (a[j]>='0'&&a[j]<='9')  && j<a.size() ;j++){
          n=n*10+a[j]-'0';
        }
        num.push_back(n);
        n=0;
        flag=0;
      }
      if(a[i]>='A'&&a[i]<='Z')flag=1;
    }
    for(int i=0;i<num.size();i++){
      ans+=(mp[element[i]]*num[i]);
    }
    cout<<fixed<<setprecision(3)<<ans<<'\n';
  } 
}
