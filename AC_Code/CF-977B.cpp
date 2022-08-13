#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    map<string,int>rec;
    vector<string>str;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        string tmp;
        tmp+=s[i];
        tmp+=s[i+1];

        if(!rec[tmp])str.push_back(tmp);
        rec[tmp]++;
    }
    pair<string,int>ans=make_pair("0",0);
    for(int i=0;i<str.size();i++){
        if(rec[str[i]]>ans.second){
            ans=make_pair(str[i],rec[str[i]]);
        }
    }
    cout<<ans.first<<'\n';
    return 0;
}
