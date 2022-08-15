#include <bits/stdc++.h>
#define ll long long
using namespace std;
string mp[3]={"1","14","144"};
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,s;
    cin>>s;
    string str;
    while(s){
        str+='0'+s%10;
        int check=s%10;
        if(check!=1 && check!=4){
            cout<<"NO"<<'\n';
            return 0;
        }
        s/=10;
    }
    reverse(str.begin(),str.end());

    for(int i=0;i<str.size();i++){
        string tmp;
        if(i+2<str.size()){
            tmp=str.substr(i,3);
            if(tmp==mp[2]){
                i+=2;
                continue;
            }
        }
        if(i+1<str.size()){
            tmp=str.substr(i,2);
            if(tmp==mp[1]){
                i+=1;
                continue;
            }
        }
        if(str[i]!='1'){
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    return 0;
}
