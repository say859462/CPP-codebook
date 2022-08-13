#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
    cin>>t;
    ll a,b,c,d;
    string s;
    while(t--){
        cin>>s;
        int one=0,zero=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')zero++;
            else one++;
        }
        int mv=min(one,zero);
        if(mv%2)cout<<"DA"<<'\n';
        else cout<<"NET"<<'\n';
    }
    return 0;
}
