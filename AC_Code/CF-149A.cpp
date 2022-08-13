#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    vector<int>num;
    int k;
    cin>>k;
    int x;
    for(int i=1;i<=12;i++){
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end(),greater<int>());
    if(k==0){
        cout<<0<<'\n';
    }
    else{
        int ans=0;
        int sum=0;
        for(int i=0;i<12;i++){
            sum+=num[i];
            ans++;
            if(sum>=k)break;
        }

        if(ans<12){
            cout<<ans<<'\n';
        }
        else if(ans==12 && sum>=k){
            cout<<12<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}
