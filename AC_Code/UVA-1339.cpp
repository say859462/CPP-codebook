#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){

    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

    string a,b;
    int cnt[26]={0};
    int cnt2[26]={0};
    while(cin>>a>>b){
        if(a==b){
            cout<<"YES"<<'\n';
            continue;
        }
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for(int i=0;i<b.size();i++){
            cnt[b[i]-'A']++;
            cnt2[a[i]-'A']++;
        }

        sort(cnt,cnt+26);
        sort(cnt2,cnt2+26);
        
        bool flag=1;
        for(int i=0;i<26;i++){
            if(cnt[i]!=cnt2[i]){
                flag=0;
                break;
            }
        }

        if(flag){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';

    }

    return 0;
}
